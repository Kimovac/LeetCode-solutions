class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;
        while(l < r) {
            int m = l + (r-l)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        if(l < n && target > nums[l])
            return l+1;
        else
            return l;
    }
};