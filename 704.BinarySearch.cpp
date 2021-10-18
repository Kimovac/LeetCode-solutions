class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l <= r) {
            int m = (r+l)/2;
            if(nums[m] == target) {
                return m;
            }
            else if(nums[m] < target)
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
};