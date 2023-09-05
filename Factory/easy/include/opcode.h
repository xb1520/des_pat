#pragma once

template<typename _Ty>
struct OpCode
{
    virtual _Ty operator()(_Ty a,_Ty b) = 0;
};


template<typename _Ty>
struct OpAdd : public OpCode<_Ty>
{
    _Ty operator()(_Ty a,_Ty b) override{
        return a + b;
    }
};

template<typename _Ty>
struct OpSub : public OpCode<_Ty>
{
    _Ty operator()(_Ty a,_Ty b) override{
        return a - b;
    }
};

template<typename _Ty>
struct OpMult : public OpCode<_Ty>
{
    _Ty operator()(_Ty a,_Ty b) override{
        return a * b;
    }
};

// template<typename _Ty>
// struct OpDiv : public OpCode<_Ty>
// {
//     _Ty operator()(_Ty a,_Ty b) override{
//         return a / b;
//     }
// };

#include <type_traits>
#include <exception>
template<typename _Ty>
struct OpDiv : public OpCode<_Ty>
{
    _Ty operator()(_Ty a,_Ty b) override{
        if constexpr (std::is_integral_v<_Ty>){
            throw std::exception("除数不能为0");
        }
        return a / b;
    }
};