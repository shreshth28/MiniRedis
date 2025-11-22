#include <iostream>
#include <string>

int main()
{
    std::cout<<"MiniRedis starting..."<<std::endl;
    std::cout<<"Type 'exit' or 'quit' to stop."<<std::endl;

    std::string line;
    while(true){
        std::cout<<"miniredis>";
        if(!std::getline(std::cin,line)){
            std::cout<<"\nInpput closed, shutting down MiniRedis."<<std::endl;
            break;
        }

        if(line=="exit"||line=="quit"){
            std::cout<<"Goodbye!"<<std::endl;
            break;
        }
        std::cout<<"You said: "<<line<<std::endl;
    }
    return 0;
}