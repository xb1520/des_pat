#include "Adapter.h"
#include <iostream>
#include <format>

int Curl::curl(std::string url)
{
    //...请求了url...并返回200
    // std::cout << __func__ << url << std::endl;
    std::cout << std::format("{}::{}\turl:{}",typeid(*this).name(),__func__,url) << std::endl;
    return 200;
}


int Http::request(std::string url)
{
    return Curl::curl(url);
}

int HttpObj::request(std::string url)
{
    return curl->curl(url);
}
