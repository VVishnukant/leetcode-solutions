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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* m = new ListNode(100);
        ListNode* temp = m;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                temp->next = a;
                temp= temp->next;
                a = a->next;
            }
            else{
                temp->next = b;
                temp=temp->next;
                b = b->next;
            }
        }
        if(a==NULL) temp->next = b;
        else temp->next = a;
        return m->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a = lists[lists.size()-1];
            lists.pop_back();
            ListNode* b = lists[lists.size()-1];
            lists.pop_back();
            ListNode* c = merge(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};