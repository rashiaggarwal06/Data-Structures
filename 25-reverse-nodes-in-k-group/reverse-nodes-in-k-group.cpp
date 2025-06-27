/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;
        // Check if at least k nodes remain
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }
        // Reverse k nodes
        ListNode* prev = NULL;
        while(cnt < k && curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            cnt++;
        }
        //Recursively reverse next group of k
        if(curr)
            head->next = reverseKGroup(curr, k);
        return prev;
    }
};