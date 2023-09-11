#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <format>
#include <iostream>


template<typename Handle>
concept IsFileHandle = requires(Handle t) {
    { t.read_data("") } -> std::same_as<std::vector<char>>; 
    { t.process({}) } -> std::same_as<int>; 
};


/*约束 or 模板 ？*/
// template<class Handle>
class FileProcessor
{
    std::string file;
    std::vector<char> data;
    // Handle handle;
private:
public:
    FileProcessor(const std::string& file):file(file){}
public:
    //模板方法 提供一个骨架
    template<IsFileHandle Handle>
    int process(Handle&& handle)
    {
        data = std::move(handle.read_data(file));
        return handle.process(data);
    }
};


//具体实现
class HandleTxt
{
public:
    std::vector<char> read_data(const std::string& file){
        std::ifstream ifs(file);
        std::vector<char> res{std::istreambuf_iterator<char>(ifs),std::istreambuf_iterator<char>()};
        res.emplace_back(0);
        if((unsigned char)res[0] == 0xEF && (unsigned char)res[1] == 0xBB && (unsigned char)res[2] == 0xBF){//修复utf-8 with bom
            res.erase(res.begin(),res.begin() + 3);
        }
        return res;
    }
    int process(const std::vector<char>& data){
        std::cout << "HandleTxt:" << std::endl;
        std::cout << data.data() << std::endl;
        return 0;
    }
    
};


//具体实现
class HandleHex
{
public:
    std::vector<char> read_data(const std::string& file){
        std::ifstream ifs(file,std::ios::binary);
        return {std::istreambuf_iterator<char>(ifs),std::istreambuf_iterator<char>()};
    }
    int process(const std::vector<char>& data){
        std::cout << "HandleHex:" << std::endl;
        int idx{};
        for(auto c : data){
            std::cout << std::format("{:02X} ",(unsigned char)c);
            if(++idx % 16 == 0){
                std::cout << std::endl;
            }
        }
        return 0;
    }
};

// using TxtProcess = FileProcessor<HandleTxt>;
// using HexProcess = FileProcessor<HandleHex>;