class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1, j=num2.length()-1;
        int carry=0;
        string ans="";
        int sum;
        while(i>=0 || j>=0 || carry){
            int d1=0,d2=0;
            if(i>=0)  d1=num1[i]-'0';
            if(j>=0)  d2=num2[j]-'0';
            sum = d1+d2+carry;
            carry=sum/10;
            ans += (sum%10)+'0';
            i--,j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};