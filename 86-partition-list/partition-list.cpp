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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);

        ListNode* bef = beforeHead;
        ListNode* aft = afterHead;

        while(head != NULL){
            if(head->val < x){
                bef->next = head;
                bef = bef->next;
            }
            else{
                aft->next = head;
                aft = aft->next;
            }
            head = head->next;
        }
        aft->next = NULL; //Important to end the list properly
        bef->next = afterHead->next; //Join both lists
        return beforeHead->next;
    }
};