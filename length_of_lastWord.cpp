class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();

        while (len > 0 && s[len - 1] == ' '){
            len--;
        }

        int lastWordLength = 0;

        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                lastWordLength++;
            }
            else {
                break;
            }
        }
        return lastWordLength;
    }
};
