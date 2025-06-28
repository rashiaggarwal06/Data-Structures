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
    //Reverse a linked list
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head){
        //Step1: reverse the head
        head = reverse(head);
        ListNode* curr = head;
        int maxVal = curr->val;
        //Step2: Compute the values
        while(curr != NULL && curr->next != NULL){
            if(maxVal > curr->next->val){
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxVal = curr->val;
            }
        }
        //Step3: reverse head again for correct output
        return reverse(head);
    }
};