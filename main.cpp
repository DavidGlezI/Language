
#include <sstream> 
#include <iostream>
#include <map>
#include <regex>
#include <vector>
 
enum returns{
    constant = 1
};

std::vector<std::string> parseString(std::string Word){
    std::stringstream ss(Word);
    std::vector<std::string> vec;
    std::string token;


     
    
    while (getline(ss, token, ' ')) {
        if(token ==" "){
            vec.push_back("space");
        }
        // store token string in the vector
        vec.push_back(token);
    }
    for(int i=0; i<vec.size(); i++){
            std::cout<<vec[i]<<std::endl;
        }
 
    return vec;


}

std::vector<std::string> tokenFun(/*std::vector<std::string>& vec,*/ std::string& word){
    std::vector<std::string>respuesta(word.size(),"");
    std::map< size_t, std::vector<std::string>> matches;
    // Tenemos el map con las expresiones y su respectivo token
    static std::map<std::string, std::string> tokens = {
        {"[aA]delante|[aA]tras","Identificador"},
        {"[0-9]+","Integer"},
        {"\\(" ,"OpenBracket"},
        {"\\)","ClosingBracket"},
    };
    // Recorremos todo el map para acceder a las expresiones
    for (std::map<std::string,std::string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
        std::regex exp(it->first); // Guardamos el primer valor del map que es la expresion REGEX 
        // Checamos si hay match con la palabra
        auto words_begin = std::sregex_iterator( word.begin(), word.end(), exp);
        auto words_end   = std::sregex_iterator();
        for ( auto i= words_begin; i != words_end; ++i){
            respuesta[i->position()]=it->second;
            //matches[ i->position() ] = make_pair( i->str(), it->second );
        }

        

        /*
        for(int i=0; i<vec.size(); i++){
            if(std::regex_search(vec[i], exp)){
            respuesta.insert(respuesta.begin(),it->second);
            }
        }
        */
    }
    for(int i=0; i<respuesta.size(); i++){
        if ( respuesta.at(i) == "" ) {
         //remove element if empty string
         respuesta.erase(respuesta.begin() + i);
         --i;
      }
    }
    /*
    for ( auto match = matches.begin(); match != matches.end(); ++match ){
        std::cout<< match->second.first << " " << match->second.second << std::endl;
    }
    */
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
    
    //std::vector<std::string> vec = parseString(respuesta);
    std::vector<std::string> out= tokenFun(respuesta);

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