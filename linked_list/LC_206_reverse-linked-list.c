/*
 * https://leetcode.com/problems/reverse-linked-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *rhead = NULL, *t;
    while (head != NULL) {
        t = head;
        head = head->next;
        t->next = rhead;
        rhead = t;
    }
    return rhead;
}
