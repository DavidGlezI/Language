#include <iostream>
#include <map>
#include <regex>
 
enum returns{
    constant = 1
};

std::map<std::string, std::string> patterns {
        { "[0-9]+" ,   "NUMBERS" },
        { "Arriba" ,   "IDENTIFIERS" },
        { "\\*|\\+",  "OPERATORS" }
    };
void matchBABY(std::string keyWord){
    bool match;
    std::string TOKEN, expresion;
    std::regex_match(keyWord, std::regex(expresion));
    switch(constant){
        case constant:
            
            break;
    }
}
int main(){


    std::string respuesta;
    std::cout<<"Ingresa un comando:";
    std::getline(std::cin, respuesta);
    std::cout << std::endl;
    

    bool match = std::regex_match(respuesta, std::regex("HOLA"));
    if(match){
        std::cout<<"correcto"<<std::endl;
    }
    else{
        std::cout<<"Incorrecto"<<std::endl;
    }

    return 0;
}