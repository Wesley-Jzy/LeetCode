/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {return NULL;}
        ListNode* last = NULL;
        ListNode* now = head;
        ListNode* next = NULL;
        while (now) {
            next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        return last;
    }
};