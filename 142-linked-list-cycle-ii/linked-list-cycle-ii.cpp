/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        //Check if any cycle exixts or not
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }
        }
        //If cycle does not exists then return null
        if(!isCycle){
            return NULL;
        }
        //If cycle exists, start finding the point where the cycle starts existing
        slow = head;
        //When we move both slow and fast pointers by only 1 step, then they will definitely meet and will meet at a position where is cycle's loop starts
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        //return that node where cycle is starting
        return slow;
    }
};