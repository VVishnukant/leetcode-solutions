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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int firstIdx = -1, secondIdx = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c==NULL) return {-1,-1};
        while(c){
            if(b->val > a->val && b->val > c->val  ||  b->val < a->val && b->val < c->val){
                if(firstIdx==-1) firstIdx = idx;
                else secondIdx = idx;
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        if(secondIdx==-1) return {-1,-1};
        int maxdist = secondIdx-firstIdx;
        int mindist = INT_MAX;
        firstIdx = -1,secondIdx = -1;
        a = head;
        b = head->next;
        c = head->next->next;
        int d;
        while(c){
            if(b->val > a->val && b->val > c->val  ||  b->val < a->val && b->val < c->val){
                firstIdx = secondIdx;
                secondIdx = idx;
                if(firstIdx!=-1){
                   int d = secondIdx - firstIdx;
                   mindist=min(mindist,d);
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        return {mindist,maxdist};
    }
};