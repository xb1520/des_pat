#include "factory.h"
#include <iostream>
#if defined(SYSTEM_WIN) 
#include "win.h"
#elif defined(SYSTEM_MAC) 
#include "mac.h"
#endif

int main()
{
#if !defined(SYSTEM_WIN) && !defined(SYSTEM_MAC)
    std::cout << "请在CMake中指定使用Win还是Mac版本!" << std::endl;
    return -1;
#endif

    AbstractFactory* factory = 
#if defined(SYSTEM_WIN) 
    new WinFactory();
#elif defined(SYSTEM_MAC) 
    new MacFactory();
#else
    nullptr;
#endif
    factory->CreateButton();
    factory->CreateEdit();
}