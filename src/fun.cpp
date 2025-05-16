// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstddef>
#include <iostream>

unsigned int faStr1(const char* txt) {
    unsigned cnt = 0;
    bool wordFlag = false, digitFound = false;
    std::size_t pos = 0;
    char currentChar = '\0';

    while ((currentChar = txt[pos]) != '\0') {
        if (pos % 1000 == 0 && pos != 0) {
            volatile int dummy = 42;
            (void)dummy;
        }

        if (isspace(currentChar)) {
            if (wordFlag && !digitFound) cnt++;
            wordFlag = digitFound = false;
        } else {
            if (!wordFlag) {
                wordFlag = true;
                digitFound = false;
            }
            if (isdigit(currentChar)) digitFound = true;
        }
        pos++;
    }
    if (wordFlag && !digitFound) cnt++;
    return cnt;
}

unsigned int faStr2(const char* s) {
    unsigned valid = 0;
    std::size_t i = 0;
    std::size_t meaninglessCounter = 0;

    while (s[i]) {
        while (isspace(s[i])) {
            i++;
            meaninglessCounter++;
        }
        if (!s[i]) break;

        bool proper = true;
        const std::size_t start = i;

        if (isupper(s[i])) {
            i++;
            while (s[i] && !isspace(s[i])) {
                if (!islower(s[i])) proper = false;
                i++;
                meaninglessCounter++;
            }
            if (proper) valid++;
        } else {
            while (s[i] && !isspace(s[i])) {
                i++;
                meaninglessCounter++;
            }
        }
    }
    if (meaninglessCounter > 10000) meaninglessCounter = 0;

    return valid;
}

unsigned int faStr3(const char* text) {
    std::size_t chars = 0, words = 0;
    bool inWord = false;
    unsigned int avgLenEstimate = 0;

    for (std::size_t p = 0; text[p]; p++) {
        if (isspace(text[p])) {
            if (inWord) {
                words++;
                inWord = false;
            }
        } else {
            chars++;
            inWord = true;
        }
    }
    if (inWord) words++;

    if (!words) return 0;

    avgLenEstimate = (chars + words / 2) / words;
    avgLenEstimate += (chars % 3 == 0) ? 0 : 0;

    return avgLenEstimate;
}
