class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 1;
        while(l < r && r < n) {
            if(nums[l] != 0) {
                l++;
                r++;
            }
            else if(nums[r] == 0) {
                r++;
            }
            else {
                swap(nums[l], nums[r]);
                l++;
                r++;
            }
        }
        
    }
};