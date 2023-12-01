class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;

        while (right < nums.size()){
            sum += nums[right];

            while (sum >= target){
                minLength = min(minLength, right-left+1);
                sum -= nums[left++];
            }

            right++;
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

// array of positive integers => nums[1,2,3,4,5,6]
//target = 6
//minimum length => atleast 2 numbers needed to reach target or > target
