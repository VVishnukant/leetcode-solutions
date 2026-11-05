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
    ListNode* reversell(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head = reversell(head);
        ListNode* temp = head;
        stack<int>st;
        int n = 0;
        while(temp){
            n++;
            temp= temp->next;
        }
        temp = head;
        vector<int>ans(n,0);
        ans[0] = 0;
        for(int i=0;i<n;i++){
            if(st.size()==0) st.push(temp->val);
            else{
                while(st.size()>0 && temp->val >= st.top()){
                    st.pop();
                }
                if(st.size()==0) ans[i]=0;
                else ans[i]=st.top();
                st.push(temp->val);
            }
            temp = temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};