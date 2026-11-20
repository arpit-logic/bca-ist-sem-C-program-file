#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strsSize < 0 || (strsSize > 0 && strs == NULL)) {
        return NULL;
    }

    size_t prefixLength = strsSize == 0 ? 0 : strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        size_t j = 0;
        while (j < prefixLength && strs[i][j] != '\0' &&
               strs[i][j] == strs[0][j]) {
            j++;
        }
        prefixLength = j;
    }

    char* prefix = malloc(prefixLength + 1);
    if (prefix == NULL) {
        return NULL;
    }

    if (prefixLength > 0) {
        memcpy(prefix, strs[0], prefixLength);
    }
    prefix[prefixLength] = '\0';
    return prefix;
}

int main(void)
{
    char words[100][256];
    char* wordPointers[100];
    int count;

    printf("Enter number of strings (0-100): ");
    if (scanf("%d", &count) != 1 || count < 0 || count > 100) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    printf("Enter %d strings: ", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%255s", words[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        wordPointers[i] = words[i];
    }

    char* prefix = longestCommonPrefix(wordPointers, count);
    if (prefix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Longest common prefix: \"%s\"\n", prefix);
    free(prefix);
    return 0;
}
