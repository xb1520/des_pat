#pragma once
#include "opcode.h"
#include <memory>

template<typename _Ty>
class IFactory
{
public:
    using OpCode = OpCode<_Ty>;
    using POpCode = std::unique_ptr<OpCode>;
    virtual POpCode CreateOpCode() = 0;
};



template<typename _Ty>
class AddFactory : public IFactory<_Ty>
{
public:
    using POpCode = typename IFactory<_Ty>::POpCode;
    POpCode CreateOpCode() override{
        return POpCode(new OpAdd<_Ty>());
    }
};


template<typename _Ty>
class SubFactory : public IFactory<_Ty>
{
public:
    using POpCode = typename IFactory<_Ty>::POpCode;
    POpCode CreateOpCode() override{
        return POpCode(new OpSub<_Ty>());
    }
};

template<typename _Ty>
class MultFactory : public IFactory<_Ty>
{
public:
    using POpCode = typename IFactory<_Ty>::POpCode;
    POpCode CreateOpCode() override{
        return POpCode(new OpMult<_Ty>());
    }
};

template<typename _Ty>
class DivFactory : public IFactory<_Ty>
{
public:
    using POpCode = typename IFactory<_Ty>::POpCode;
    POpCode CreateOpCode() override{
        return POpCode(new OpDiv<_Ty>());
    }
};