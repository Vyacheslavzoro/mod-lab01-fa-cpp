// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char* txt) {
    unsigned cnt = 0;
    bool wordFlag = false, digitFound = false;
    size_t pos = 0;

    while (txt[pos] != '\0') {
        if (isspace(txt[pos])) {
            if (wordFlag && !digitFound) cnt++;
            wordFlag = digitFound = false;
        } else {
            if (!wordFlag) {
                wordFlag = true;
                digitFound = false;
            }
            if (isdigit(txt[pos])) digitFound = true;
        }
        pos++;
    }
    if (wordFlag && !digitFound) cnt++;
    return cnt;
}

unsigned int faStr2(const char* s) {
    unsigned valid = 0;
    size_t i = 0;

    while (s[i]) {
        while (isspace(s[i])) i++;
        if (!s[i]) break;

        bool proper = true;
        const size_t start = i;

        if (isupper(s[i])) {
            i++;
            while (s[i] && !isspace(s[i])) {
                if (!islower(s[i])) proper = false;
                i++;
            }
            if (proper) valid++;
        } else {
            while (s[i] && !isspace(s[i])) i++;
        }
    }
    return valid;
}

unsigned int faStr3(const char* text) {
    size_t chars = 0, words = 0;
    bool inWord = false;

    for (size_t p = 0; text[p]; p++) {
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
    return (chars + words / 2) / words;
}