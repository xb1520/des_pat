#include <iostream>
#include "Proxy.h"


int main() {
    Http http;
    http.request("http://baidu.com");
    http.request("https://baidu.com");

    Proxy proxy;
    proxy.request("http://baidu.com");
    proxy.request("https://baidu.com");
    return 0;
}
