#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "database.hpp"

std::vector<std::string> split_line(const std::string &line)
{
    std::vector<std::string> tokens;
    std::istringstream iss(line);
    std::string token;

    while(iss>>token){
        tokens.push_back(token);
    }
    return tokens;
}

bool handle_command(const std::vector<std::string> &tokens, Database &db){
    if(tokens.empty())
        return true;
    const std::string &cmd=tokens[0];
    if(cmd=="exit"|| cmd=="quit")
    {
        std::cout<<"Goodbye!"<<std::endl;
        return false;
    }
    if(cmd=="PING" || cmd=="ping")
    {
        std::cout<<"PONG"<<std::endl;
        return true;
    }
    if(cmd=="ECHO" || cmd=="echo")
    {
        if(tokens.size()<=1)
            std::cout<<"(nil)"<<std::endl;
        else{
            for(std::size_t i=1;i<tokens.size();i++){
                if(i>1)
                    std::cout<<' ';
            std::cout<<tokens[i];
            }
        std::cout<<std::endl;
            }
        return true;
        
    }

    if (cmd == "SET" || cmd =="set"){
        if(tokens.size()!=3){
            std::cout<<"ERR usage: SET <key> <value>"<<std::endl;
            return true;
        }
        const std::string &key=tokens[1];
        const std::string &value=tokens[2];

        db.set(key,value);
        std::cout<<"OK"<<std::endl;
        return true;
    }

    if (cmd=="GET"|| cmd=="get"){
        if(tokens.size()!=2){
            std::cout<<"ERR usage: GET <key" <<std::endl;
            return true;
        }
        const std::string &key=tokens[1];
        std::string value;
        if(!db.get(key,value)){
            std::cout<<"(nil)"<<std::endl;
        }
        else{
            std::cout<<value<<std::endl;
        }
        return true;
    }

    if(cmd=="DEL" || cmd=="del"){
        if(tokens.size()!=2){
            std::cout<<"ERR usage: DEL <key>"<<std::endl;
            return true;
        }
        const std::string &key=tokens[1];
        std::size_t erased=db.del(key);
        std::cout<<erased<<std::endl;
        return true;
    }
    std::cout<<"ERR unknown command: "<< cmd<<std::endl;   
    return true;
}

int main()
{
    std::cout<<"MiniRedis starting..."<<std::endl;
    std::cout<<"Type 'exit' or 'quit' to stop."<<std::endl;

    std::string line;
    Database db;
    while(true){
        std::cout<<"miniredis>";
        if(!std::getline(std::cin,line)){
            std::cout<<"\nInpput closed, shutting down MiniRedis."<<std::endl;
            break;
        }
        std::vector<std::string> tokens=split_line(line);
        bool keep_running=handle_command(tokens,db);
        if(!keep_running)
            break;
    }
    return 0;
}