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
    void deleteNode(ListNode* node) {
        //Make a pointer curr that is used to point the node to be deleted
        ListNode* curr = node->next;
        //Copy the next nodes value to the current node so that the link can broke and we can remove the node that should be deleted
        node->val = node->next->val;
        //Make the link of node's next to the next of next node 
        node->next = node->next->next;
        //Delete the current node that we have to remove
        delete curr;
    }
};