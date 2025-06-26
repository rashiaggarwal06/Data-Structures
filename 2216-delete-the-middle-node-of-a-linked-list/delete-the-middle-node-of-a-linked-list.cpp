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
    ListNode* deleteMiddle(ListNode* head) {
        //base Cases: if head is null or empty
        if(head == NULL || head->next == NULL) return NULL;

        //make a prev pointer to access the before node of slow
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        //Find the middle of the linked list
        while(fast != NULL && fast->next != NULL){
            //Update the prev pointer with every move so that prev can remain just before the slow pointer
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //Make the prev pointer's link to the next node just after the slow
        prev->next = slow->next;

        //Delete the slow node 
        delete slow;
        return head;        
    }
};