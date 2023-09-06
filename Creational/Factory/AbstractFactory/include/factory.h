#pragma once
#include <memory>

class Button{
public:
    virtual ~Button() = default;
};

class Edit{
public:
    virtual ~Edit() = default;
};

class AbstractFactory
{
public:
    using PButton = std::unique_ptr<Button>;
    using PEdit = std::unique_ptr<Edit>;
    virtual PButton CreateButton() = 0;
    virtual PEdit CreateEdit() = 0;
};







