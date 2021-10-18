class Solution {
public:
    void generate_permutations(vector<string> &permutations, string &curr_permutation, int i) {
        if(i == curr_permutation.size())
            return;
        
        if(isalpha(curr_permutation[i])) {
            curr_permutation[i] = toupper(curr_permutation[i]);
            generate_permutations(permutations, curr_permutation, i+1);
            permutations.push_back(curr_permutation);
            curr_permutation[i] = tolower(curr_permutation[i]);
        }

        generate_permutations(permutations, curr_permutation, i+1);
}
    
    vector<string> generate_permutations(string s) {
        int number_of_permutations = 1;
        string curr_permutation = s;
        for(int i=0; i<curr_permutation.size(); i++) {
            if(isalpha(curr_permutation[i])) {
                curr_permutation[i] = tolower(curr_permutation[i]);
                number_of_permutations <<= 1;
            }
        }
        
        vector<string> permutations;
        permutations.reserve(number_of_permutations);
        
        permutations.push_back(curr_permutation);
        generate_permutations(permutations, curr_permutation, 0);
        
        cout << permutations.size();
        
        return permutations;
    }
    
    vector<string> letterCasePermutation(string s) {
        return generate_permutations(s);
    }
};