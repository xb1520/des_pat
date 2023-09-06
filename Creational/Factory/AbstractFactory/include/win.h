#include <iostream>
#include "factory.h"

class WinButton : public Button
{
public:
    WinButton(){std::cout << "Windows Button Create!" << std::endl;}
    ~WinButton(){std::cout << "Windows Button Destory!" << std::endl;}
};

class WinEdit : public Edit
{
public:
    WinEdit(){std::cout << "Windows Edit Create!" << std::endl;}
    ~WinEdit(){std::cout << "Windows Edit Destory!" << std::endl;}
};


class WinFactory : public AbstractFactory
{
public:
    using PButton = AbstractFactory::PButton;
    using PEdit = AbstractFactory::PEdit;
    PButton CreateButton(){return PButton(new WinButton());}
    PEdit CreateEdit(){return PEdit(new WinEdit());}
};
