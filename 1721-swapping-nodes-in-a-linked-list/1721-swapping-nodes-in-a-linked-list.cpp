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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=1;i<k;i++){
            fast=fast->next;
        }
        ListNode* a = fast;
        fast=fast->next;
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* b = slow;
        int temp=b->val;
        b->val = a->val;
        a->val = temp;
        return head;
    }
};