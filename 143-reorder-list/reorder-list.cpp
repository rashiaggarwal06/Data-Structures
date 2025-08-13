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
    //Function to find the middle element of the linked list
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //Function to reverse the linked list
    ListNode* reverse(ListNode* right_half){
        ListNode* prev = NULL;
        ListNode* curr = right_half;
        ListNode* nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    //Main Function
    void reorderList(ListNode* head){
        //If the head is Null or having only 1 element then we will return the list as it is 
        if(!head || !head->next) return;
        //Find the mid element to break the list in two halves
        ListNode* mid = middle(head);
        //Now, reverse the right half of the list
        ListNode* right_half = reverse(mid->next);
        //Break the connection of left and right both halves
        mid->next = NULL; 
        //Make a pointer for left half on head
        ListNode* left_half = head;
        //Start iterating until right half does not gets empty
        while(right_half){
            //Take two pointers for both the halves to iterate (Set them at the next positions for both) 
            ListNode* t1 = left_half->next;
            ListNode* t2 = right_half->next;
            //Link the left_half element with right half elements alternatively one by one
            left_half->next = right_half;
            right_half->next = t1;
            left_half = t1;
            right_half = t2;
        }
    }
};