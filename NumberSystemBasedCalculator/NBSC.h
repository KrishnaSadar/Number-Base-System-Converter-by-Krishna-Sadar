#include <string.h>
#include <math.h>
#include<stdbool.h>
#include<stdio.h>
int toInteger(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

char toCharacter(int n) {
    if (n >= 0 && n <= 9) return n + '0';
    if (n >= 10 && n < 36) return n - 10 + 'A';
    return '!';
}

bool Valid(const char* number, int base) {
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        if (number[i] == '.') continue;
        if (toInteger(number[i]) >= base || toInteger(number[i]) == -1) {
            return false;
        }
    }
    return true;
}
long long cTod(char* number, int base) {
   long long result = 0;
    int length = strlen(number);
    int i;
    for (i = 0; i < length; i++) {
        if (number[i] == '.') break;
        result += toInteger(number[i]) * pow(base, length - i - 1);
    }
    return result;
}
long long cTodF(char* number, int base) {
   long long result = 0;
    int length = strlen(number);
    int i;
                     int pointIndex = 0;
     if (strchr(number, '.') != NULL) {
    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            pointIndex = i;
            break;
        }
    }
        }
        length=length-pointIndex-1;
    for (i = 0; i < length; i++) {
        if (number[i] == '.') break;
        result += toInteger(number[i]) * pow(base, length - i - 1);
    }
    return result;
}

void cFromd(long long n, int base, char* result) {
    char temp[65];
    int it = 0;
    if (n == 0) {
        strcpy(result, "0");
        return;
    }
    while (n > 0) {
        temp[it++] = toCharacter(n % base);
        n /= base;
    }

    for (int i = 0; i < it; i++) {
        result[i] = temp[it - i - 1];
    }
    result[it] = '\0';
}

bool ValidFractional(const char* number, int base) {
    int length = strlen(number);
    bool pointSeen = false;
    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            if (pointSeen) return false;
            pointSeen = true;
            continue;
        }
        if (toInteger(number[i]) >= base || toInteger(number[i]) == -1) {
            return false;
        }
    }
    return true;
}

void convertFractionalPart(const char* number, int inputBase, int outputBase, char* result) {
    double fractionalValue = 0.0;
    int length = strlen(number);
    int pointIndex = 0;
    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            pointIndex = i;
            break;
        }
    }
    for (int i = pointIndex + 1; i < length; i++) {
        fractionalValue += toInteger(number[i]) * pow(inputBase, -(i - pointIndex));
    }

    int tempIndex = 0;
    while (fractionalValue > 0 && tempIndex < 10) {
        fractionalValue *= outputBase;
        int fractionalDigit = (int)fractionalValue;
        result[tempIndex++] = toCharacter(fractionalDigit);
        fractionalValue -= fractionalDigit;
    }

    result[tempIndex] = '\0';
}


void header() {
    printf("|======================================================================|\n\n");
    printf("|                 WELCOME TO NUMBER BASE SYSTEM CONVERTER              |\n\n");
    printf("|======================================================================|\n\n");
    return;
}

void printResult(int n2, char* num2) {
    printf("======================================================================\n");
    printf("The Number in base %d is: %s\n", n2, num2);
    printf("======================================================================\n");
}

void Menu() {
    printf("|                           Select the Option:                         |\n\n");
    printf("|======================================================================|\n\n");
    printf("| 1. Decimal                                                           |\n");
    printf("| 2. Binary                                                            |\n");
    printf("| 3. Octal                                                             |\n");
    printf("| 4. Hexadecimal                                                       |\n");
    printf("| 5. Other base                                                        |\n");
    printf("======================================================================\n\n");
    printf("| Enter your option:");
}
