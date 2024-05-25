class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        vector<int> occ;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                occ.push_back(i);
            }
        }
        
        vector<int>ans;
        
        for (int q: queries) {
            if (q > occ.size()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(occ[q-1]);
            }
        }
        
        return ans;
    }
};
