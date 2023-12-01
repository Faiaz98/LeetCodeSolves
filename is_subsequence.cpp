class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        int sPointer = 0, tPointer = 0;

        while (sPointer < sLen && tPointer < tLen) {
            if (s[sPointer] == t[tPointer]) {
                sPointer++;
            }
            tPointer++;
        }

        return sPointer == sLen;
    }
};
