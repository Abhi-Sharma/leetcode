class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int l = 0;
        int r = 0;
        int mini = INT_MAX;
        while(l < n && r < m){
            if(nums1[l] == nums2[r]){
                mini = min(mini,nums1[l]);
                l++;
                r++;
            }
            else if(nums1[l] != nums2[r] && nums1[l] > nums2[r]) r++;
            else l++;
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};