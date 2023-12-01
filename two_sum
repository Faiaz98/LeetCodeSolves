class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex;  // create an unordered map to store the number and its index

        for (int i = 0; i < nums.size(); i++){ // Iterate thru input vector 'nums'
            int c = target - nums[i]; // calculate the compliment - the number needed to reach the target

            if(numIndex.find(c) != numIndex.end()){ // check if the compliment is present
                return {numIndex[c], i}; // if exists return the indices of the two numbers
            }
            numIndex[nums[i]] = i; // If the complement is not found, store the current number and its index in the map
        }

        return {};
    }
};
