//  Example 1:

// Input:
// int nums[] = {1, 3, 5, 6};
// int numsSize = 4;
// int target = 5;

// Output: 2
// Example 2:

// Input:
// int nums[] = {1, 3, 5, 6};
// int numsSize = 4;
// int target = 2;

// Output: 1
// Example 3:

// Input:
// int nums[] = {1, 3, 5, 6};
// int numsSize = 4;
// int target = 7;

// Output: 4

#include <stdio.h>

int searchInsert(const int* nums, int numsSize, int target)
{
    if (numsSize < 0 || (numsSize > 0 && nums == NULL)) {
        return -1;
    }
    if (numsSize == 0) {
        return 0;
    }

    int left = 0;
    int right = numsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(void)
{
    int nums[1000];
    int count;
    int target;

    printf("Enter the number of sorted elements (0-1000): ");
    if (scanf("%d", &count) != 1 || count < 0 || count > 1000) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d sorted integers: ", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &nums[i]) != 1 ||
            (i > 0 && nums[i] < nums[i - 1])) {
            printf("Invalid input: values must be sorted integers.\n");
            return 1;
        }
    }

    printf("Enter target: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target.\n");
        return 1;
    }

    printf("Insert position: %d\n", searchInsert(nums, count, target));
    return 0;
}
