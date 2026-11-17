// q = 0 1 2 3 4 5 6
// q = 2 3 4 5 6 1
// ans = 2 _ 3 _ 5 _ 7  

// q = 3 5 1
// =>  2 _ 3 11 5 _ 7  


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        vector<int>ans(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int i=0;i<n;i++){
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;

    }
};