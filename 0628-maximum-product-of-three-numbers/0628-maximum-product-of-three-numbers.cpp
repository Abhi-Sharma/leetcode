class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        int smallest = INT_MAX;
        int secondsmallest = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums[i] >= largest ){
                third = second;
                second = largest;
                largest = nums[i];
            }
            else if(nums[i] >= second){
                third = second;
                second = nums[i];
            }
            else if(nums[i] > third){
                third = nums[i];
            }

            if(nums[i] <= smallest){
                secondsmallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < secondsmallest){
                secondsmallest = nums[i];
            }
        }

        return max(largest * second * third, smallest * secondsmallest * largest);
    }
};