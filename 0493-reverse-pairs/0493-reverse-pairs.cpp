class Solution {
    int mergeSort(vector<int>& nums, int low , int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high)/2;
        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);
        cnt += countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    int countPairs(vector<int>& nums, int low , int mid, int high){
        int right = mid + 1;
        int cnt = 0;
        for(int i = low ; i <= mid; i++){
            while(right <= high && nums[i] >(long long) 2 * nums[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;    
    int right = mid + 1;  

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = mergeSort(nums,0,n-1);
        return cnt;
    }
};