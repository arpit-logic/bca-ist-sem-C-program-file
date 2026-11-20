//  Example 1:

// Input:
// int x = 4;

// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
// Example 2:

// Input:
// int x = 8;

// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
#include <stdio.h>

int mySqrt(int x)
{
    if (x < 0) {
        return -1;
    }

    int left = 0;
    int right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;
        if (square == x) {
            return mid;
        }
        if (square < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int main(void)
{
    int value;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &value) != 1 || value < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Integer square root: %d\n", mySqrt(value));
    return 0;
}