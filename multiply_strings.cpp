class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = product + result[p2];
                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }

        string res = "";
        for (int num : result) {
            if (!(res.empty() && num == 0)) {
                res += to_string(num);
            }
        }
        return res.empty() ? "0" : res;
    }
};
