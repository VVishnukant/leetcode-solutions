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
    ListNode*merge(ListNode*x,ListNode*y){

        if(x==NULL)return y;
        if(y==NULL)return x;
        if(x->val<=y->val){
            x->next=merge(x->next,y);
            return x;
        }
        else{
            y->next=merge(x,y->next);
            return y;
        }
    }
    ListNode* mergeTwoLists(ListNode* x, ListNode*y) {
        
        return merge(x,y);
    }
};