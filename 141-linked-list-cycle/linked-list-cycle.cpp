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
    bool hasCycle(ListNode *head) {
        //Make 2 pointers to move in the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        //If fast pointer gets null that means we do not have any loop in the linked list 
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            //If fast and slow pointers meet in the traversal, that means loop exists in our linked list so we will simply return true
            if(slow == fast) return true;
        }
        return false;
    }
};