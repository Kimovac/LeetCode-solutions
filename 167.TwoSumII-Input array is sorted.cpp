class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indices(2);
        int n = numbers.size();
        int l = 0;
        int r = n-1;
        while(l < r) {
            if(numbers[l] + numbers[r] == target) {
                indices[0] = l+1;
                indices[1] = r+1;
                break;
            }
            else if(numbers[l] + numbers[r] > target) {
                r--;
            }
            else {
                l++;
            }
        }
        
        return indices;
    }
};