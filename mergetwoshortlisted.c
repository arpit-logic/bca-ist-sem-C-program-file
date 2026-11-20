#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 != NULL ? list1 : list2;
    return dummy.next;
}

static void freeList(struct ListNode* head)
{
    while (head != NULL) {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

static int readList(const char* name, struct ListNode** head)
{
    long count;
    struct ListNode* tail = NULL;

    *head = NULL;
    printf("Enter the number of elements in %s: ", name);
    if (scanf("%ld", &count) != 1 || count < 0 || count > INT_MAX) {
        return 0;
    }

    printf("Enter %ld sorted integers: ", count);
    for (long i = 0; i < count; i++) {
        int value;
        if (scanf("%d", &value) != 1 || (tail != NULL && value < tail->val)) {
            freeList(*head);
            *head = NULL;
            return 0;
        }

        struct ListNode* node = malloc(sizeof(*node));
        if (node == NULL) {
            freeList(*head);
            *head = NULL;
            return -1;
        }

        node->val = value;
        node->next = NULL;
        if (tail == NULL) {
            *head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    return 1;
}

int main(void)
{
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    int status = readList("list 1", &list1);

    if (status != 1) {
        printf(status == -1 ? "Memory allocation failed.\n" : "Invalid input. Enter a non-negative size and sorted integers.\n");
        return 1;
    }

    status = readList("list 2", &list2);
    if (status != 1) {
        freeList(list1);
        printf(status == -1 ? "Memory allocation failed.\n" : "Invalid input. Enter a non-negative size and sorted integers.\n");
        return 1;
    }

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Merged list: [");
    for (struct ListNode* node = merged; node != NULL; node = node->next) {
        printf("%d%s", node->val, node->next != NULL ? ", " : "");
    }
    printf("]\n");

    freeList(merged);
    return 0;
}
