class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeftPosition(nums, target);
        int right = findRightPosition(nums, target);

        if (left > right) {
            return {-1, -1};
        }

        return {left, right};
    }

private:
    //function to find the leftmost occurrence of the target
    int findLeftPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftmost = nums.size();

        while (left <= right) {
            int mid = left + (right - left) /2;

            if (nums[mid] >= target) {
                leftmost = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return leftmost == nums.size() ? -1 : leftmost;
    }

    //function to find the rightmost occurrence of the target
    int findRightPosition(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightmost = -1;

        while (left <= right) {
            int mid = left + (right - left) /2;

            if(nums[mid] <= target) {
                rightmost = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return rightmost;
    }
};
