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
        ListNode* low = new ListNode(10);
        ListNode* high = new ListNode(20);
        ListNode* tempL = low;
        ListNode* tempH = high;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                tempL->next = temp;
                tempL=tempL->next;
                temp=temp->next;
            }
            else{
                tempH->next = temp;
                tempH=tempH->next;
                temp=temp->next;
            }
        }

        tempL->next = high->next;
        tempH->next = NULL;
        return low->next;
    }
};