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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == NULL) return NULL;
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr && curr->next){
            if(s.find(curr->next->val) != s.end()){
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        } 
        return dummy->next;
    }
};