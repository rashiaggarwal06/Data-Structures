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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Make two pointers individually for both the lists
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        //Create a dummy node to make the resultant list
        ListNode* dummy = new ListNode(0);
        //Make a pointer curr and set it to dummy node initially
        ListNode* curr = dummy;
        //Make a variable carry to track the carry values
        int carry = 0;
        //Iterate until both the lists not get null
        while(h1 != NULL || h2 != NULL){
            //Set sum to previous remaining carry
            int sum = carry;
            //If h1 pointer has any value, then add in sum, else skip
            if(h1) sum = sum + h1->val;
            //If h2 pointer has any value, then add in sum, else skip
            if(h2) sum = sum + h2->val;
            //Make a new node next to dummy to store added values and sent the carry value to variable we have made, only add the remainder value in 1 node and rest store in the variable carry to use further
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10; //rest is stored in carry
            curr->next = newNode; //make a link of curr to newnode
            curr = curr->next;
            //if h1, h2 has still values means it is not null, then refer it to its next value
            if(h1) h1 = h1->next;
            if(h2) h2 = h2->next;
        }
        //As last, if carry contains some value, so print it in a newnode too
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode; //make the link of curr to newNode
            curr = curr->next;
        }
        //Just return the nextnode to dummy so that we dont return the initial null node in the result
        return dummy->next;
    }
};