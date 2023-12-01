class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (char bracket : s) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                parentheses.push(bracket);
            }
            else {
                if (parentheses.empty()) {
                    return false;
                }

                char top = parentheses.top();
                parentheses.pop();

                if ((bracket == ')' && top != '(') || (bracket == ']' && top != '[') || (bracket == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return parentheses.empty();
    }
};
