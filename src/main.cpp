// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char* testStr = "  Hello World123 ABC Abc abc A123b Cdef  ";
    
    std::cout << "faStr1: " << faStr1(testStr) << std::endl;
    std::cout << "faStr2: " << faStr2(testStr) << std::endl;
    std::cout << "faStr3: " << faStr3(testStr) << std::endl;

    return 0;
}
