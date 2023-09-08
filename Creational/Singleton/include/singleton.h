﻿#pragma once
#define SINGLETON_INS(_C) _C singleton<_C>::ins{}

class singleton_base
{
private:
    singleton_base(const singleton_base&) = delete;
    singleton_base(singleton_base&&) = delete;
    singleton_base& operator=(const singleton_base&) = delete;
    singleton_base& operator=(singleton_base&&) = delete;
public:
    singleton_base() = default;
};

//全局静态实现
template<typename C>
class singleton : public singleton_base
{
private:static C ins;
public:
    static C& instance() noexcept{
        return ins;
    }
};



//局部静态实现
template<typename C>
class singleton_local : public singleton_base
{
public:
    static C& instance() noexcept{
        static C ins;
        return ins;
    }
};