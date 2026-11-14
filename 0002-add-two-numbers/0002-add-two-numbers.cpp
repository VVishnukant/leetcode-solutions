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
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* c = new ListNode(-1);
        ListNode* t = c;
        int carry=0;
        int sum, SUM;
        while(a!=NULL && b!=NULL){
            sum = a->val + b->val + carry;
            if(sum<10){
                carry=0;
                ListNode* x = new ListNode(sum);
                t->next = x;
                t = t->next;
            }
            else{
                SUM = sum;
                sum%=10;
                carry = SUM/10;
                ListNode* x = new ListNode(sum);
                t->next = x;
                t = t->next;
            }
            a=a->next;
            b=b->next;
        }
        while(a!=NULL){
            sum = a->val + carry;
            if(sum<9){
                carry=0;
                ListNode* x = new ListNode(sum);
                t->next = x;
                t = t->next;
            }
            else{
                SUM = sum;
                sum%=10;
                carry = SUM/10;
                ListNode* x = new ListNode(sum);
                t->next = x;
                t = t->next;
            }
            a=a->next;
        }
        while(b!=NULL){
            sum = b->val + carry;
            if(sum<9){
                carry=0;
                ListNode* x = new ListNode(sum);
                t->next = x;
                t = t->next;
            }
            else{
                SUM = sum;
                sum%=10;
                carry = SUM/10;
                ListNode* x = new ListNode(sum);
                t->next = x;
                t = t->next;
            }
            b=b->next;
        }
        while(carry) {
            ListNode* x = new ListNode(carry);
            t->next = x;
            t = t->next;
            carry /= 10;
        }
        return c->next;
    }
};