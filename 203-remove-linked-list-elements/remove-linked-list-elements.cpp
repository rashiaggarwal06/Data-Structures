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
    ListNode* removeElements(ListNode* head, int val) {
        //If the list is empty, return a empty list
        if(!head) return head;
        //If list only has 1 element and it is that target element, then remove it
        if(head->next == NULL && head->val == val) return NULL;
        //if we found the values in the starting of the list so we will continue moving our head with one by one check
        while(head && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp; 
        } 
        //Make a curr pointer to iterate over the whole list
        ListNode* curr = head;
        //Iterate until curr and its next gets empty
        while(curr && curr->next){
            //if curr's next is that target value, so we will store it in  a new node name 'temp' and move the curr to next's next, and finally delete the temp node 
            if(curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; 
            } 
            //else make current move 1 step always
            else
                curr = curr->next;
        }
        //return the head of the new list
        return head;
    }
};