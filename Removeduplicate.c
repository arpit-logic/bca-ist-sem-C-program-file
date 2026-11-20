// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize < 0 || (numsSize > 0 && nums == NULL)) {
        return -1;
    }
    if (numsSize == 0) {
        return 0;
    }

    int uniqueCount = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[uniqueCount - 1]) {
            nums[uniqueCount++] = nums[i];
        }
    }
    return uniqueCount;
}

int main(void)
{
    int nums[1000];
    int count;

    printf("Enter number of sorted elements (0-1000): ");
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

    int uniqueCount = removeDuplicates(nums, count);
    printf("Unique count: %d\nUnique values: [", uniqueCount);
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d%s", nums[i], i + 1 < uniqueCount ? ", " : "");
    }
    printf("]\n");
    return 0;
}