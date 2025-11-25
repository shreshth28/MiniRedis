#pragma once

#include <string>
#include <unordered_map>

struct Database{
    std::unordered_map<std::string,std::string> kv;

    void set(const std::string &key,const std::string &value);

    bool get(const std::string &key, std::string &out_value) const;

    std::size_t del(const std::string &key);
};