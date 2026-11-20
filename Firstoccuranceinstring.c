//  Example 1:

// Input:
// char* haystack = "sadbutsad";
// char* needle = "sad";

// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input:
// char* haystack = "leetcode";
// char* needle = "leeto";

// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
#include <stdio.h>
#include <string.h>

int strStr(const char* haystack, const char* needle)
{
    if (haystack == NULL || needle == NULL) {
        return -1;
    }

    size_t haystackLength = strlen(haystack);
    size_t needleLength = strlen(needle);
    if (needleLength == 0) {
        return 0;
    }
    if (needleLength > haystackLength) {
        return -1;
    }

    for (size_t i = 0; i <= haystackLength - needleLength; i++) {
        if (strncmp(haystack + i, needle, needleLength) == 0) {
            return (int)i;
        }
    }
    return -1;
}

int main(void)
{
    char haystack[1024];
    char needle[1024];

    printf("Enter the text: ");
    if (scanf("%1023s", haystack) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter the substring: ");
    if (scanf("%1023s", needle) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("First occurrence index: %d\n", strStr(haystack, needle));
    return 0;
}
