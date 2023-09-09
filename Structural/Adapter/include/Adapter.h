#pragma once
#include <string>

//客户端需要的接口
class IHttp
{
public:
    virtual int request(std::string url) = 0;
};


//被适配的类
class Curl
{
public:
    int curl(std::string url);
};



//类适配器
class Http : private Curl,public IHttp
{
public:
    int request(std::string url) override;
};



//对象适配器
class HttpObj : public IHttp
{
private: Curl* curl;
public:
    inline HttpObj(Curl* _curl):curl(_curl){};
    int request(std::string url) override;
};