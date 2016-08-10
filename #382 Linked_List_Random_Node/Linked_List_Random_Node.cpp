class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
        _NodeNum = 0;
        while (head) {
            _NodeNum++;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand() % _NodeNum;
        ListNode* node = _head;
        for (int i=0;i<pos;i++) {
            node = node->next;
        }
        return node->val;
    }
private:
    ListNode* _head;
    int _NodeNum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */