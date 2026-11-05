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
    int n = 0;
    ListNode* reversell(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr){
            n++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head = reversell(head);
        stack<int>st;
        vector<int>ans(n,0);
        int i = 0;
        while(head){
            while(!st.empty() && head->val >= st.top()) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(head->val);
            head = head->next;     
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};