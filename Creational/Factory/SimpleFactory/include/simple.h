#pragma once
#include "opcode.h"
#include <memory>

template<typename _Ty>
class SimpleFactory
{
public:
    using OpCode = OpCode<_Ty>;
    using POpCode = std::unique_ptr<OpCode>;
    static POpCode CreateOpCode(char op);
};



template <typename _Ty>
inline SimpleFactory<_Ty>::POpCode SimpleFactory<_Ty>::CreateOpCode(char op)
{
    if(op == '+')return POpCode(new OpAdd<_Ty>());
    if(op == '-')return POpCode(new OpSub<_Ty>());
    if(op == '*')return POpCode(new OpMult<_Ty>());
    if(op == '/')return POpCode(new OpDiv<_Ty>());
    return nullptr;
}
