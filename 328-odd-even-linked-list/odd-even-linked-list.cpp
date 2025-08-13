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
    ListNode* oddEvenList(ListNode* head) {
        //If head if NULL, or having only 1 element then return list as it is
        if(!head || !head->next) return head;
        //Make a o pointer to keep track odd indices and e pointer to track even indices
        ListNode* o = head;          
        ListNode* e = head->next;  
        //Tostore the head of even list make a pointer even_h
        ListNode* even_h = e;         
        //Iterate until even and its next gets NULL
        while(e && e->next){
            //Link odd element to next odd 
            o->next = e->next;   
            //Move o 1 step ahead
            o = o->next;      
            //Link even element to next even   
            e->next = o->next;  
            //Move e 1 step ahead
            e = e->next;        
        }
        //Link the whole odd elements list to the even elements list
        o->next = even_h;
        return head;
    }
};