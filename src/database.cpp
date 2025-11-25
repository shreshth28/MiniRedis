#include "database.hpp"

void Database::set(const std::string &key, const std::string &value){
    kv[key]=value;
}

bool Database::get(const std::string &key,std::string &out_value) const{
    auto it=kv.find(key);
    if(it==kv.end())
        return false;
    out_value=it->second;
    return true;
}

std::size_t Database::del(const std::string &key){
    return kv.erase(key);
}

