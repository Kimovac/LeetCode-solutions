class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> merged(nums.size());
        auto it = lower_bound(nums.begin(), nums.end(), 0);
        int d = distance(nums.begin(), it);
        
        transform(nums.begin(), nums.end(), nums.begin(), [](int x) { return x*x; });
        merge(nums.rend()-d, nums.rend(), nums.begin()+d, nums.end(), merged.begin());
        
        return merged;
    }
};