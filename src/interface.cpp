#include "interface.h"
/*
template<class T, class V>
T cinCheck(T minimum, T maximum, V message[], V wrong_message[]) {
    std::string number;
    T mess;
    while ((std::cout << message )<< "\n"&& (!(std::cin >> number) || number > maximum || number < minimum )){
        
        std::cout << wrong_message<<"\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

template<class T*&>
void cinCheck(T* input, std::function<bool(bool)> wrongfunc, std::function<bool(T)> checkFunc){
    std::string temp;
    while (true){
        wrongfunc(true);
        std::cin >> temp;
        T temp2 = static_cast<T>(temp);
        if(cin.fail() || checkFunc(temp2)){
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            wrongfunc(false);
        }
        else if(temp.empty()){
            break;
        }
        else{
            *input = static_cast<T>(temp);
            break;
        }
    }
}
*/
/*template<class T, class V>
T cinCheck(){
    while()
}
*/

void Interface::editItem(Item* item){

    std::deque<std::string>* contents;
    if(item->getContents(contents)){
        std::string temp;
        bool end = false;
        std::string replacement;
        int line{};
        while(!end){
            std::cout << item->getIndex() << ":\n";
            for(long i = 0; i < contents->size(); ++i){
                std::cout << i + 1 << "\t" << contents->at(i) << '\n';
            }
            std::cout << "Edit line: ";
            std::cin >> temp;
            if(temp == "exit"){
                end = true;
                break;
            }
            else if(slib::isDigit(temp)){
                line = stoi(temp);
                if(line > contents->size()){
                    continue;
                }
                std::cout << line << ": ";
                std::cin >> temp;
                if(temp == "exit"){
                    end = true;
                    break;
                }
                item->editItem(line - 1, temp);
                auditor.saveItem(*item);
            }
        }
    }
}