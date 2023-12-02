class Solution {
public:
    int longestValidParentheses(string s) {
        int max_length = 0;
        stack<int> parenthesesStack;
        parenthesesStack.push(-1); //push -1 as a base for the substring calculation

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                parenthesesStack.push(i); //push index of '(' to the stack
            } else {
                parenthesesStack.pop(); //pop the previous '('
                if(parenthesesStack.empty()) {
                    parenthesesStack.push(i); //push current index as a new base
                } else{
                    max_length = max(max_length, i - parenthesesStack.top());
                }
            }
        }
        return max_length;
    }
};
