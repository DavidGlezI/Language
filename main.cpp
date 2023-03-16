
#include <sstream> 
#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include <boost/tokenizer.hpp>
 
enum returns{
    constant = 1
};

std::vector<std::string> parseString(std::string Word){
    std::stringstream ss(Word);
    std::vector<std::string> vec;
    std::string token;


     
    boost::char_separator<char> sep(" "); // specify only the kept separators
    boost::tokenizer<boost::char_separator<char>> tokens(Word, sep);
    for (std::string t : tokens) { vec.push_back(t); }
    /*
    while (getline(ss, token, ' ')) {
        if(token ==" "){
            vec.push_back("space");
        }
        // store token string in the vector
        vec.push_back(token);
    }
    */
    for(int i=0; i<vec.size(); i++){
            std::cout<<vec[i]<<std::endl;
        }
    return vec;


}

std::vector<std::string> tokenFun(std::vector<std::string>& vec){
    std::vector<std::string> respuesta;
    // Tenemos el map con las expresiones y su respectivo token
    static std::map<std::string, std::string> tokens = {
        {"[aA]delante","Identificador"},
        {"[0-9]","Integer"},
        {"space","Whitespace"},
    };
    // Recorremos todo el map para acceder a las expresiones
    for (std::map<std::string,std::string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
        std::regex exp(it->first); // Guardamos el primer valor del map que es la expresion REGEX 

        // Checamos si hay match con la palabra
        for(int i=0; i<vec.size(); i++){
            if(std::regex_search(vec[i], exp)){
            respuesta.insert(respuesta.begin(),it->second);
        }
    }
        
    }
    return respuesta;

}



/*
void matchBABY(std::string keyWord){
    bool match;
    std::string TOKEN, expresion;
    std::regex_match(keyWord, std::regex(expresion));
    switch(constant){
        case constant:
            
            break;
    }
}

*/

int main(){


    std::string respuesta;
    std::cout<<"Ingresa un comando:";
    std::getline(std::cin, respuesta);
    std::cout << std::endl;
    std::cout<<"Size:"<<respuesta.size()<<std::endl;
    
    std::vector<std::string> vec = parseString(respuesta);
    std::vector<std::string> out= tokenFun(vec);

    /*
    bool match = std::regex_match(respuesta, std::regex("HOLA"));
    if(match){
        std::cout<<"correcto"<<std::endl;
    }
    else{
        std::cout<<"Incorrecto"<<std::endl;
    }
    */
    for(int i=0; i<out.size(); i++){
        std::cout<<out[i]<<std::endl;
    }
    /*
    std::vector<std::string>::iterator it;
    for (it=out.begin();it!=out.end();it++){
        std::cout<<*it<<std::endl;
    }
    */

    return 0;
}