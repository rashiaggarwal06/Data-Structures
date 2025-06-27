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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //base Cases:
        if(head == NULL || head->next == NULL) return nullptr;

        //Count the total length of the linked list
        ListNode* curr_len = head;
        int t_len = 0;
        while(curr_len != NULL){
            t_len++;
            curr_len = curr_len->next;
        } 
        
        // If the node to be deleted is the head
        if(n == t_len){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        //Iterate over the necessary part only and remove the given nth node
        ListNode* curr = head;
        for(int i = 1; i < t_len - n; i++){
            curr = curr->next;
        }

        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        return head;
    }
};