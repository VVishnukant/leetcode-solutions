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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; // break ho gya
        ListNode* c = new ListNode(10);
        ListNode* tempc = c;
        ListNode* tempa = a;
        ListNode* tempb = b;
        while(tempa && tempb){
            tempc->next = tempa;
            tempc=tempc->next;
            tempa = tempa->next;
            tempc->next = tempb;
            tempc = tempc->next;
            tempb = tempb->next;
        }
        tempc->next = tempa;
        head = c->next;
    }
};