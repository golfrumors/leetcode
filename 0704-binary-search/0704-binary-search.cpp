class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(high - low > 1){
           int middle = (low+high)/2;
            if(nums[middle] < target){
                low = middle + 1;
            } else {
                high = middle;
            }
        }
        if(nums[low] == target){
            return low;
        } else if(nums[high] == target){
            return high;
        }

        return -1;
    }
};