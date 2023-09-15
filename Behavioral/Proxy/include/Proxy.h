#pragma once
#include <vector>
#include <string>
#include <format>
#include <iostream>


//接口
class IHttp
{
public:
    virtual int request(const std::string& url) = 0;
};



//真实业务
class Http : public IHttp
{
public:
    int request(const std::string& url){
        std::cout << "http访问:" << url << std::endl;
        return 200;
    }
};


//代理，可以拦截非法操作，记录日志
class Proxy :  public IHttp
{
private:
    Http& instance(){
        static Http http;//延迟加载
        return http;
    }
public:
    int request(const std::string& url){
        if(url.starts_with("https://")){
            std::cout << "代理拦截一条https请求:" << url << std::endl;//记录日志
            return 404;//拒绝代理https请求
        }
        std::cout << "代理一条http请求:" << url << std::endl;//记录日志
        return instance().request(url);
    }
};