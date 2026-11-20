// Given a roman numeral, convert it to an integer.

 

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
#include <stdio.h>

static int romanValue(char symbol)
{
    switch (symbol) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(const char* s)
{
    if (s == NULL) {
        return 0;
    }

    int result = 0;
    for (const char* current = s; *current != '\0'; current++) {
        int value = romanValue(*current);
        if (value == 0) {
            return 0;
        }
        int nextValue = current[1] == '\0' ? 0 : romanValue(current[1]);
        if (current[1] != '\0' && nextValue == 0) {
            return 0;
        }
        if (value < nextValue) {
            result -= value;
        } else {
            result += value;
        }
    }
    return result;
}

int main(void)
{
    char roman[64];
    printf("Enter a Roman numeral: ");
    if (scanf("%63s", roman) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int value = romanToInt(roman);
    if (value == 0) {
        printf("Invalid Roman numeral.\n");
        return 1;
    }

    printf("Integer value: %d\n", value);
    return 0;
}