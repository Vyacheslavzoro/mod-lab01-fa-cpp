// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string.h>

unsigned int faStr1(const char *str) {
    int count = 0;
    int size = strlen(str);
    bool isCurrentWord = false;
    bool hasDigit = false;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            if (isCurrentWord) {
                isCurrentWord = false;
                if (!hasDigit) {
                    count++;
                }
                hasDigit = false;
            }
        } else if (static_cast<int>(str[i]) >= 48 &&
            static_cast<int>(str[i]) <= 57) {
            hasDigit = true;
        } else {
            if (!isCurrentWord) {
                isCurrentWord = true;
            }
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    int count = 0;
    int size = strlen(str);
    bool isCurrentWord = false;
    bool hasBigLetter = false;
    bool hasSmallLetter = false;
    bool correctWord = true;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            if (isCurrentWord && correctWord) {
                if (hasBigLetter && hasSmallLetter) {
                    count++;
                }
                isCurrentWord = false;
                hasBigLetter = false;
                hasSmallLetter = false;
                correctWord = true;
            }
        } else if (!correctWord) {
            continue;
        } else if (static_cast<int>(str[i]) >= 65 &&
            static_cast<int>(str[i]) <= 90) {
            if (!isCurrentWord) {
                hasBigLetter = true;
                isCurrentWord = true;
            } else {
                correctWord = false;
            }
        } else if (static_cast<int>(str[i]) >= 97 &&
            static_cast<int>(str[i]) <= 122) {
            hasSmallLetter = true;
        } else {
            correctWord = false;
        }
    }

    return count;
}

unsigned int faStr3(const char *str) {
    int count = 0;
    int size = strlen(str);
    bool isCurrentWord = false;
    int letterCount = 0;
    int wordCount = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            if (isCurrentWord) {
                wordCount++;
            }
            isCurrentWord = false;
        } else if (i == size - 1) {
            letterCount++;
            if (isCurrentWord) {
                wordCount++;
            }
            isCurrentWord = false;
        } else {
            isCurrentWord = true;
            letterCount++;
        }
    }

    return letterCount / wordCount;
}
