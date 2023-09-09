#include "Adapter.h"
#include <iostream>


int main()
{
    Http http;
    int code = http.request("https://http.Http.class");
    std::cout << "code: " << code << std::endl;

    Curl curl;
    code = curl.curl("https://curl.Curl.class");
    std::cout << "code: " << code << std::endl;

    HttpObj http_obj(&curl);
    code = http_obj.request("https://http_obj.HttpObj.class");
    std::cout << "code: " << code << std::endl;
}