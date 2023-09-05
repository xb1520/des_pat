#include <iostream>
#include <type_traits>

// 原始的类模板

template<typename T>
T my_div(T a,T b)
{
    constexpr bool flag = std::is_integral_v<T>;
    std::cout << "flag:" << flag << std::endl;
    if constexpr (flag){
        if(b == 0)throw "除法不能为0";
    }
    // if(flag){
    //     if(b == 0)throw "b = 0";
    // }
    return a / b;
}

int main() {
    try
    {
        std::cout << my_div(100,0) << std::endl;
        std::cout << my_div(100.0,0.0) << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    return 0;
}
