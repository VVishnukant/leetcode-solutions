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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempa = list1;
        ListNode* tempb = list2;
        ListNode* list3 = new ListNode(100);
        ListNode* tempc = list3;
        while(tempa!=NULL && tempb!=NULL){
            if(tempa->val <= tempb->val){
                ListNode* t = new ListNode(tempa->val);
                tempc->next = t;
                tempc = t;
                tempa = tempa->next;
            }
            else{
                ListNode* t = new ListNode(tempb->val);
                tempc->next = t;
                tempc = t;
                tempb = tempb->next;
            }
        }
        if(tempa==NULL) tempc->next = tempb;
        else tempc->next = tempa;
        return list3->next; // beta list3 mein 100 tha na
    }
};