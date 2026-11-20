//  Example 1:

// Input:
// int nums[] = {3, 2, 2, 3};
// int numsSize = 4;
// int val = 3;

// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input:
// int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
// int numsSize = 8;
// int val = 2;

// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    if (numsSize < 0 || (numsSize > 0 && nums == NULL)) {
        return -1;
    }

    int kept = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[kept++] = nums[i];
        }
    }
    return kept;
}

int main(void)
{
    int nums[1000];
    int count;
    int value;

    printf("Enter number of elements (0-1000): ");
    if (scanf("%d", &count) != 1 || count < 0 || count > 1000) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d integers: ", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("Enter value to remove: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid value.\n");
        return 1;
    }

    int newSize = removeElement(nums, count, value);
    printf("New length: %d\nRemaining values: [", newSize);
    for (int i = 0; i < newSize; i++) {
        printf("%d%s", nums[i], i + 1 < newSize ? ", " : "");
    }
    printf("]\n");
    return 0;
}