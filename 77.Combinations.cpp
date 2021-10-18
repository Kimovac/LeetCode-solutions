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
    
    bool check_combination(const vector<int> &curr_combination, int i) {
        if(i == 0)
            return true;
        
        for(int j = 0; j<i; j++)
            if(curr_combination[j] == curr_combination[i] || 
              curr_combination[j] > curr_combination[i])
                return false;
        
        return true;
    }
    
    void generate_combinations(vector<vector<int>> &combinations, vector<int> &curr_combination, const int n, int i) {
        if(i == curr_combination.size()) {
            combinations.push_back(curr_combination);
            return;
        }
        
        for(int num=1; num<=n; num++) {
            curr_combination[i] = num;
            if(check_combination(curr_combination, i))
                generate_combinations(combinations, curr_combination, n, i+1);
        }
    }
    
    vector<vector<int>> generate_combinations(int n, int k) {
        int number_of_combinations = factorial(n) / (factorial(k)*factorial(n-k));
        
        vector<vector<int>> combinations;
        combinations.reserve(number_of_combinations);
        vector<int> curr_combination(k, 0);
        generate_combinations(combinations, curr_combination, n, 0);
        
        return combinations;
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        return generate_combinations(n, k);
    }
};