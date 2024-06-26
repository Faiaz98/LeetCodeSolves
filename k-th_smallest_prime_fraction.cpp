class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        vector<int> result(2, 0);

        // binary search for the kth smallest fraction value
        while (left < right) {
            double mid = left + (right - left) / 2;
            int count = 0;
            double maxFraction = 0.0;

            //sliding window to count fractions less than or equal to mid
            int j = 1;
            for (int i = 0; i < n - 1; i++) {
                while (j < n && arr[i] >= mid * arr[j])
                j++;
                count += n - j;
                if (j < n && maxFraction < (double)arr[i] / arr[j]) {
                    maxFraction = (double)arr[i] / arr[j];
                    result[0] = arr[i];
                    result[1] = arr[j];
                }
            }

            if (count == k) break;
            if (count < k) left = mid;
            else right = mid;

        }

        return result;
    }
};
