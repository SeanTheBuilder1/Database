#include "auditor.h"

bool Auditor::exist(const std::string& index){
    for(auto &i : audit){
        if(i  == index)
            return true;
    }
    return false;
}

void Auditor::addItem(Item& item){
    //Check if item already exists
    if(std::find(database.dataSave.begin(), database.dataSave.end(), ("`" + item.getIndex())) == std::end(database.dataSave)){
        //Find terminator
        auto it = std::find(database.dataSave.begin(), database.dataSave.end(), "`");
        std::deque<std::string>* temp;
        if(item.getContents(temp)){
            //Add temporary index to temp
            temp->insert(temp->begin(), "`" + item.getIndex());
            temp->emplace_back("`");
            database.dataSave.erase(it);
            //Insert temp to database starting from terminator
            database.dataSave.insert(it, temp->begin(), temp->end());
            //Save database
            database.saveData(database.dataSave);
            //Remove temporary index
            temp->pop_back();
            temp->pop_front();
            //Add item to audit
            audit.emplace_back(item.getIndex());
            items.emplace_back(item);
        }
    }
}

bool Auditor::openItem(const std::string& index){
    Item temp{index};
    //Get item from database
    if(temp.readItem(temp.getIndex())){
        //Add captured item to audit 
        for(auto& i : audit){
            if(temp.getIndex() == i){
                std::cout << "Item already audited, no need to open\n";
                return true;
            }
        }
        items.emplace_back(temp);
        audit.emplace_back(index);
        return true;
    }
    else{
        //Error message
        std::cout << "The item \"" + index + "\" does not exist on the database\n";
        return false;
    }   
}

void Auditor::delItem(const std::string& index){
    //Get indexed item
    openItem(index);
    Item* temp;
    if(getItem(index, temp)){
        std::deque<std::string>* cont;
        if(temp->getContents(cont)){
            //Clear contents of item
            cont->clear();
            //Save empty item
            saveItem(*temp);
            for(long i = 0; i < database.dataSave.size(); ++i){
                //Find and delete empty index
                if(database.dataSave[i] == ("`" + index)){
                    database.dataSave.erase(database.dataSave.begin() + i);
                    //Save changes
                    database.saveData(database.dataSave);
                    items.erase(items.begin() + getItemID(index));
                    audit.erase(audit.begin() + getAuditID(index));
                    return;
                }
            }
        }
    }
}

void Auditor::saveDatabase(){
    std::vector<std::string> auditorData;
    //Add current file config
    auditorData.emplace_back(database.dataSave[0]);
    auditorData.emplace_back(database.dataSave[1]);
    //loop through every item and add its index and contents to vector
    for(auto& i : items){
        std::deque<std::string>* contents;
        auditorData.emplace_back('`' + i.getIndex());
        if(i.getContents(contents)){
            for(auto& j : *contents){
                auditorData.push_back(j);
            }
        } 
    }
    //Add suffix
    auditorData.emplace_back("`");
    //Save the captured data to database
    database.saveData(auditorData);
}

void Auditor::sort(){
    //Sort the order of the items (not the contents)
    std::sort(items.begin(), items.end());
    //Also the audit cause consistency
    std::sort(audit.begin(), audit.end());
    //Workaround function, save the whole database
    saveDatabase();
    //Check for audit-item consistency
    assert(checkIntegrity());
}


void Auditor::sort(std::function<bool(Item&, Item&)> compare){
    //Sort items with user given compare function
    std::sort(items.begin(), items.end(), compare);
    //Cant just use same sorting because it uses user given compare func
    fixAudit();
    //Workaround function, save the whole database
    saveDatabase();
    //Check for audit-item consistency
    assert(checkIntegrity());
}


void Auditor::fixAudit(){
    //Make the index and audit line up
    //First remove former audit
    audit.clear();
    //Then add every index of every item
    for(auto& i : items){
        audit.emplace_back(i.getIndex());
    }
}


bool Auditor::checkIntegrity(){
    //Simple if equal shenanigans
    for(long i = 0; i < items.size(); ++i){
        if(items[i].getIndex() != audit[i]){
            return false;
        }    
    }
    return true;
}



void Auditor::moveItem(Item& item, long destination){
    //yaaaa it doesn't look nice but it works
    long start, end;
    std::tie(start, end) = getDatabaseIndex(item);
    std::deque<std::string>* contents;
    item.getContents(contents);
    contents->emplace_front('`' + item.getIndex());
    /*FUTURE OPTIMIZATION PROBABLY
    if(start <= destination && destination <= end)
        std::move_backward(database.dataSave.begin() + start, database.dataSave.begin() + end, std::inserter(database.dataSave, std::next(database.dataSave.begin() + destination)));
    else
        std::move(database.dataSave.begin() + start, database.dataSave.begin() + end, std::inserter(database.dataSave, std::next(database.dataSave.begin() + destination)));
    */
    //std::vector<std::string> copy;
    //copy.reserve(end - start + 1);
    //std::move(database.dataSave.begin() + start, database.dataSave.begin() + end, std::back_inserter(copy));
    database.dataSave.erase(database.dataSave.begin() + start, database.dataSave.begin() + end);
    if(end < destination){
        destination -= contents->size();
    }
    //database.dataSave.insert(database.dataSave.begin() + destination, copy.begin(), copy.end());
    database.dataSave.insert(database.dataSave.begin() + destination, contents->begin(), contents->end());
    contents->emplace_front();
    database.saveData(database.dataSave);
}

void Auditor::moveItem(Item& item, Item& destination){
    //Redirector function for move Item
    long start, end;
    std::tie(start, end) = getDatabaseIndex(destination);
    if(end >= database.dataSave.size() - 1){
        return moveItem(item, end);
    }
    return moveItem(item, end);
}

void Auditor::moveToStart(Item& item){
    //Move to start just after the file config 
    moveItem(item, 2);
}

void Auditor::swapItem(Item& item, Item& destination){
    //This function is messed up tbf
    long start, end, dstart, dend;
    std::tie(start, end) = getDatabaseIndex(item);
    std::tie(dstart, dend) = getDatabaseIndex(destination);

    if(dstart < start){
        //swap for convenience
        return swapItem(destination, item);
    }

    database.dataSave.erase(database.dataSave.begin() + start, database.dataSave.begin() + end);
    std::deque<std::string>* content;
    std::deque<std::string>* dcontent;
    long diff = dend - dstart;
    item.getContents(content);
    destination.getContents(dcontent);
    content->emplace_front('`' + item.getIndex());
    dcontent->emplace_front('`' + destination.getIndex());
    database.dataSave.insert(database.dataSave.begin() + start, dcontent->begin(), dcontent->end());
    long dIndex = ((dstart) - content->size()) + dcontent->size();
    database.dataSave.erase(database.dataSave.begin() + dIndex, database.dataSave.begin() + (diff + dIndex));
    database.dataSave.insert(database.dataSave.begin() + dIndex, content->begin(), content->end());
    content->pop_front();
    dcontent->pop_front();
    database.saveData(database.dataSave);
}

void Auditor::saveItem(Item& item){
    long beg{0};
    long end{0};
    bool stopper = false;
    if(slib::fullOfSpace(item.getIndex())){
        return;
    }


    //index line number of item for next iterator
    for(long i = 0; i < database.dataSave.size();  ++i){
        //Check if index matches
        if((database.dataSave[i] == (std::string("`") + item.getIndex())) == 1){
            //Get beginning of contents
            //Add 1 to iterator to not include index to contents
            beg = (i + 1);
            for(++i; i < database.dataSave.size(); ++i){
                //Check if end of contents
                if(std::find(database.dataSave[i].begin(), database.dataSave[i].end(), '`') != database.dataSave[i].end()){
                    //Save to iterator end of contents
                    end = i;
                    stopper = true;
                    break;
                }
            }
        }
        else if(stopper)
            break;
    }
    //if successful erase old contents of item from database copy and insert new contents 
    //and save database copy to merge to data.txt
    if(stopper){
        std::deque<std::string>* temp;
        item.getContents(temp);
        database.dataSave.erase(database.dataSave.begin() + beg, database.dataSave.begin() + end);
        database.dataSave.insert(database.dataSave.begin() + beg, temp->begin(), temp->end());
        database.saveData(database.dataSave);
    }
}

void Auditor::loadAll(){
    for(long i; i < database.dataSave.size(); ++i){
        //Find if string is an index
        if(database.dataSave[i].find("`") != database.dataSave[i].npos){
            //Check if not terminator
            if(database.dataSave[i] != "`"){
                //add to audit
                openItem(database.dataSave[i].substr(1, std::string::npos));
            }
        }
    }
}

long Auditor::getAuditID(const std::string& index){
    //Get audit position from the std::deque, return -1 if none found
    for(long i = 0; i < audit.size(); ++i){
        if(audit[i] == index){
            return i;
        }
    }
    return -1;
}

long Auditor::getItemID(const std::string& index){
    //Get item position from the std::deque, return -1 if none found
    for(long i = 0; i < items.size(); ++i){
        if(items[i].getIndex() == index){
            return i;
        }
    }
    return -1;
}

bool Auditor::getItem(const std::string& index, Item* &item){
    //loop through items list and check for index given and give pointer for item
    //return true if successful
    //return false if failed
    for(Item& i : items){
        if(i.getIndex() == index){
            item = &i;
            return true;
        };
    }
    return false;
}

bool Auditor::getAudit(std::deque<Item>*& audit){
    if(items.empty()){
        return false;
    }
    else{
        audit = &items;
        return true;
    }
}

void Auditor::openDatabase(const std::string& path){
    database.openFile(path);
    audit.clear();
    items.clear();
}

Auditor& getAuditor(){
    static Auditor auditor;
    return auditor;
}