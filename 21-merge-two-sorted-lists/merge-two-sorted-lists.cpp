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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        //Base Cases:
        if(l1 == NULL || l2 == NULL){
            return l2 == NULL ? l1 : l2;
        }
        //Case-1:
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        //Case-2:
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};