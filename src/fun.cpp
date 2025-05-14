// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool containsDigit = false;

    for (int i = 0; str[i]; ++i) {
        // Если слово закончилось и в нём не было цифр — увеличиваем счётчик
        if (std::isspace(str[i])) {
            if (inWord && !containsDigit) {
                ++count;
            }
            inWord = false;
            containsDigit = false;
        } else {
            if (!inWord) {
                inWord = true;
                containsDigit = false;
            }
            if (std::isdigit(str[i])) {
                containsDigit = true;
            }
        }
    }

    if (inWord && !containsDigit) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool validWord = false;
    int i = 0;

    while (str[i]) {
        while (std::isspace(str[i])) ++i;

        if (!str[i]) break;

        if (std::isupper(str[i])) {
            inWord = true;
            validWord = true;
            ++i;

            while (str[i] && !std::isspace(str[i])) {
                if (!std::islower(str[i])) {
                    validWord = false;
                }
                ++i;
            }

            if (validWord) {
                ++count;
            }
        } else {
            while (str[i] && !std::isspace(str[i])) {
                ++i;
            }
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    bool inWord = false;

    for (int i = 0; str[i]; ++i) {
        if (std::isspace(str[i])) {
            if (inWord) {
                ++wordCount;
                inWord = false;
            }
        } else {
            ++totalLength;
            inWord = true;
        }
    }

    if (inWord) {
        ++wordCount;
    }

    if (wordCount == 0) return 0;

    return static_cast<unsigned int>((totalLength + wordCount / 2) / wordCount);
}
