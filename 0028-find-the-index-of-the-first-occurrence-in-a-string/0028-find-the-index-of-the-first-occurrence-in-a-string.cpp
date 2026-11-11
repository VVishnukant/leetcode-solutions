class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m>n) return -1;
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                bool flag = false;
                for(int j=0;j<m;j++){
                    if(haystack[j+i] == needle[j]){
                        flag=true;
                        continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag) return i;
            }
        }
        return -1;

    }
};