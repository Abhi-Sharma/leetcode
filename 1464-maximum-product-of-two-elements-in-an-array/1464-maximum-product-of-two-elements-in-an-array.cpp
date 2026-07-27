class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN;
        int second = INT_MIN;

        for(int i = 0; i < n; i++){
            if(nums[i] > largest){
                second = largest;
                largest = nums[i];
            }
            else if(nums[i] > second){
                second = nums[i];
            }
        }
        return (largest - 1) * (second - 1);
    }
};