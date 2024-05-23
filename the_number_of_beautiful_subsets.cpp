unordered_map<int, int> count; // To keep track of elements in the current subset
        return backtrack(nums, k, 0, count) - 1; // Subtract 1 to exclude the empty subset
    }
    
private:
    int backtrack(vector<int>& nums, int k, int index, unordered_map<int, int>& count) {
        if (index == nums.size()) {
            return 1; // Each valid subset is counted as 1
        }
        
        // Don't include the current element in the subset
        int withoutCurrent = backtrack(nums, k, index + 1, count);
        
        // Check if including the current element keeps the subset beautiful
        bool canInclude = true;
        if (count[nums[index] - k] > 0 || count[nums[index] + k] > 0) {
            canInclude = false;
        }
        
        int withCurrent = 0;
        if (canInclude) {
            count[nums[index]]++;
            withCurrent = backtrack(nums, k, index + 1, count);
            count[nums[index]]--;
        }
        
        return withoutCurrent + withCurrent;
    }
};
