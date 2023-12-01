class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();

        if (needleLength == 0) {
            return 0;
        }
        
        for (int i = 0; i <= haystackLength - needleLength; i++) {
            if (haystack.substr(i, needleLength) == needle) {
                return i;
            }
        }

        return -1;
    }
};
