class Solution {
public:
    long int factorial(int n) {
        if(n == 0)
            return 1;
        
        long int result = n;
        while(--n) {
            result *= n;
        }
        
        return result;
    }
    
    bool check_permutation(const vector<int> &curr_permutation, int i) {
        if(i == 0)
            return true;
        
        for(int j = 0; j<i; j++)
            if(curr_permutation[j] == curr_permutation[i])
                return false;
        
        return true;
    }
    
    void generate_permutations(const vector<int> & permutation_pool, vector<vector<int>> &permutations, vector<int> &curr_permutation, int i) {
        if(i == curr_permutation.size()) {
            permutations.push_back(curr_permutation);
            return;
        }
        
        for(int j=0; j<permutation_pool.size(); j++) {
            curr_permutation[i] = permutation_pool[j];
            if(check_permutation(curr_permutation, i))
                generate_permutations(permutation_pool, permutations, curr_permutation, i+1);
        }
    }
    
    vector<vector<int>> generate_permutations(const vector<int> &permutation_pool) {
        int number_of_permutations = factorial(permutation_pool.size());
        vector<vector<int>> permutations;
        permutations.reserve(number_of_permutations);
        
        vector<int> curr_permutation(permutation_pool.size());
        generate_permutations(permutation_pool, permutations, curr_permutation, 0);
        
        return permutations;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        return generate_permutations(nums);
    }
};



