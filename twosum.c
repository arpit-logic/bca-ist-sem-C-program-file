// Example 1:

// Input: nums = [2,7,11,15], target = 9

// Output: [0,1]

// Explanation:

// The sum of nums[0] and nums[1] is 2 + 7 = 9, which equals the target. Therefore, the indices [0, 1] are returned.

// Example 2:

// Input: nums = [3,2,4], target = 6

// Output: [1,2]

// Explanation:

// The sum of nums[1] and nums[2] is 2 + 4 = 6, which equals the target. Therefore, the indices [1, 2] are returned.

// Example 3:

// Input: nums = [3,3], target = 6

// Output: [0,1]

// Explanation:

// The sum of nums[0] and nums[1] is 3 + 3 = 6, which equals the target. Therefore, the indices [0, 1] are returned.

 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if (returnSize == NULL) {
        return NULL;
    }

    *returnSize = 0;
    if (nums == NULL || numsSize < 2) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if ((long long)nums[i] + nums[j] == target) {
                int* result = malloc(2 * sizeof(int));
                if (result == NULL) {
                    *returnSize = -1;
                    return NULL;
                }
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    return NULL;
}

int main(void)
{
    int numsSize;
    int target;

    printf("Enter number of elements: ");
    if (scanf("%d", &numsSize) != 1 || numsSize < 1) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    if ((size_t)numsSize > SIZE_MAX / sizeof(int)) {
        printf("Number of elements is too large.\n");
        return 1;
    }

    int* nums = malloc((size_t)numsSize * sizeof(*nums));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input.\n");
            free(nums);
            return 1;
        }
    }

    printf("Enter target: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target.\n");
        free(nums);
        return 1;
    }

    int returnSize = 0;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result);
    } else if (returnSize == -1) {
        printf("Memory allocation failed.\n");
        free(nums);
        return 1;
    } else {
        printf("No solution found.\n");
    }

    free(nums);
    return 0;
}