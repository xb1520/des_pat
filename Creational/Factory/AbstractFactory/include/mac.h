#include <iostream>
#include "factory.h"


class MacButton : public Button
{
public:
    MacButton(){std::cout << "Macos Button Create!" << std::endl;}
    ~MacButton(){std::cout << "Macos Button Destory!" << std::endl;}
};

class MacEdit : public Edit
{
public:
    MacEdit(){std::cout << "Macos Edit Create!" << std::endl;}
    ~MacEdit(){std::cout << "Macos Edit Destory!" << std::endl;}
};


class MacFactory : public AbstractFactory
{
public:
    using PButton = AbstractFactory::PButton;
    using PEdit = AbstractFactory::PEdit;
    PButton CreateButton(){return PButton(new MacButton());}
    PEdit CreateEdit(){return PEdit(new MacEdit());}
};