class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i'  || ch=='o' || ch=='u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int maxcount = 0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i])==true) maxcount++;
        }
        int i=0;
        int j=k-1;
        int count = maxcount;
        while(j<s.size()){
            if(isvowel(s[i])==true) count--;
            i++,j++;
            if(isvowel(s[j])==true) count++;
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};