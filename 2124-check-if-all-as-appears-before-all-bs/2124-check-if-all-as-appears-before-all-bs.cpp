class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        bool flag = false;
        for(int i=0;i<n;i++){
            if(s.substr(i,2)=="ba") return false;
        }
        return true;
    }
};