class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftProducts(n, 1);
        int leftProduct = 1;
        for (int i = 1; i < n; i++) {
            leftProduct *= nums[i - 1];
            leftProducts[i] = leftProduct;
        }

        int rightProduct = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightProduct *= nums[i + 1];
            leftProducts[i] *= rightProduct;
        }

        return leftProducts;
    }
};
