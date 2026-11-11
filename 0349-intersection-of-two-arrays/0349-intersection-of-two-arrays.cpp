class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>v(1001,0);
        for(int i=0;i<nums1.size();i++){
            if(v[nums1[i]]==0) v[nums1[i]]=1;
        }
        for(int i=0;i<nums2.size();i++){
            if(v[nums2[i]]==1){
                ans.push_back(nums2[i]);
                v[nums2[i]]=0;
            }
        }
        return ans;
    }
};