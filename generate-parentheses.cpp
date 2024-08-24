class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        //base case: when the current string has used up all parentheses
        if (current.length() == max * 2) {
            result.push_back(current); //add the valid combination to the result
            return;
        }

        //if we can still add an opening parentheses
        if (open < max) {
            backtrack(result, current + '(', open + 1, close, max);
        }

        //if we can still add a closing parenthese and maintain balance
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, max);
        }
    }
};
