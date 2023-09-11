/*
使用utf-8 with bom的话，会发现相比于 utf-8在文件头多了三个字节， EF BB BF 
*/
#include "template_method.h"
#include <iostream>


int main()
{
    // TxtProcess txt(__FILE__);
    // txt.process();

    // HexProcess hex(__FILE__);
    // hex.process();

    FileProcessor process(__FILE__);

    process.process(HandleTxt{});

    process.process(HandleHex{});
}