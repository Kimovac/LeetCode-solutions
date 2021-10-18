class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        vector<int> move_k(k);
        
        copy(nums.end()-k, nums.end(), move_k.begin());
        copy(nums.begin(), nums.end()-k, nums.begin()+k);
        copy(move_k.begin(), move_k.end(), nums.begin());
    }
};