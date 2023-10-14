#include "singleton.h"
#include <iostream>
#include <format>

//打印输出
namespace Log{
    void log(std::string _log)
    {
        std::cout << 
        _log
        << std::flush;
    }
}
#define LOG(_log) Log::log(std::format("{}:({})\t{}\n",__FILE__,__LINE__,_log)) 

class singletonA : public singleton<singletonA>
{
    FRIEND_INS(singleton,singletonA)
private:
    singletonA(){
        LOG(_log(__func__));
    }
    ~singletonA(){
        LOG(_log(__func__));
    }
public:
    
    std::string _log(const std::string& str){
        return std::format("this_singletonA:{}\t{}",(void*)this,str.data());
    }
};

SINGLETON_INS(singletonA);

class singletonB : public singleton_local<singletonB>
{
    FRIEND_INS(singleton_local,singletonB)
private:
    singletonB(){
        LOG(_log(__func__));
    }
    ~singletonB(){
        LOG(_log(__func__));
    }
public:
    std::string _log(const std::string& str){
        return std::format("this_singletonB:{}\t{}",(void*)this,str.data());
    }
};

// singletonA a{}; //报错
// singletonB b{}; //报错
int main()
{
    LOG(__func__);
    LOG(singletonA::instance()._log("main_call singletonA 1"));
    LOG(singletonA::instance()._log("main_call singletonA 2"));
    LOG(singletonB::instance()._log("main_call singletonB 1"));
    LOG(singletonB::instance()._log("main_call singletonB 2"));
}