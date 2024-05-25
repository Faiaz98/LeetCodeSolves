class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> countMap;
        
        for(int num: nums) {
            countMap[num]++;
        }
        
        int xorResult = 0;
        
        for (const auto& entry: countMap) {
            if (entry.second == 2) {
                xorResult ^= entry.first;
            }
        }
        
        return xorResult;
    }
};
