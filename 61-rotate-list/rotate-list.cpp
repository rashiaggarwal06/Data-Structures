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
    //Function used to find the nth node means the new last node of the linked list
    ListNode* newLastNode(ListNode* lst, int k){
        int cnt = 1;
        while(lst != NULL){
            if(cnt == k) return lst;
            cnt++;
            lst = lst->next;
        }
        return lst;
    }
    //Function to rotate list by k times from right
    ListNode* rotateRight(ListNode* head, int k) {
        //Base Cases: If head or its next is null or k == 0 means we don't have to do any rotation, then generally return head
        if(!head || !head->next || k == 0) return head; 

        int len = 1;
        ListNode* curr = head;
        //Find the total length of the linked list
        while(curr->next != NULL){
            len++;
            curr = curr->next;
        }
        //If k is multiple of length of the linked list that means the rotations will give answer in the same head
        if(k % len == 0)
            return head;
        //Make k modulo len so that extra rotations can remove
        k = k % len;
        //Make the last node's link with the current head of the list
        curr->next = head;
        //Find the new last node by iterating the list and make its next node as new head that we have to return and make its link with null value as it is new end of the linked list
        ListNode* lNode = newLastNode(head, len - k);
        head = lNode->next;
        lNode->next = NULL;
        //return the new head of the list
        return head;
    }
};