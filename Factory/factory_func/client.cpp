#include "factory.h"
#include <iostream>

template<typename _Ty>
auto CreateOpCode(char op)
{
    if(op == '+')return AddFactory<_Ty>().CreateOpCode();
    if(op == '-')return SubFactory<_Ty>().CreateOpCode();
    if(op == '*')return MultFactory<_Ty>().CreateOpCode();
    if(op == '/')return DivFactory<_Ty>().CreateOpCode();
    return IFactory<_Ty>::POpCode();
}


int main()
{
    int a,b;
    char op;
    std::cout << "请输入一个表达式(目前支持+-*/):" << std::flush;
    std::cin >> a >> op >> b;
    auto opcode = CreateOpCode<int>(op);
    if(!opcode){
        std::cerr << "不合法的操作数..." << std::endl;
        return -1;
    }

    try
    {
        std::cout <<  (*opcode)(a,b)<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}