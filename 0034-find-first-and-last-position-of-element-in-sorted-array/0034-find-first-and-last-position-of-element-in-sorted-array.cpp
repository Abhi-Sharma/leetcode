class Solution {
    int firstPos(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return first;
    }

    int lastPos(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int last = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPos(nums,target);
        int last = lastPos(nums,target);
        return {first,last};
    }
};