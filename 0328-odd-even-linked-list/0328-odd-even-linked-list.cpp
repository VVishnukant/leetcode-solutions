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
        ListNode* odd = new ListNode(10);
        ListNode* even = new ListNode(20);
        ListNode* tempO = odd;
        ListNode* tempE = even;
        ListNode* temp = head;
        int n = 1;
        while(temp!=NULL){
            if(n % 2!=0){
                tempO->next = temp;
                temp = temp->next;
                tempO = tempO->next;
            }
            else{
                tempE->next = temp;
                temp = temp->next;
                tempE = tempE->next;
            }
            n++;
        }
        tempO->next = even->next;
        tempE->next = NULL;
        return odd->next;
    }
};