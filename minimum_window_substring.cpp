class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }

        int start = 0, end = 0;
        int minWindowLength = INT_MAX;
        int minWindowStart = 0;
        int requireChars = tFreq.size();
        int formedChars = 0;
        unordered_map<char, int> windowFreq;

        while (end < s.length()) {
            //expand window to the right
            char currentChar = s[end];
            windowFreq[currentChar]++;
            if (tFreq.count(currentChar) && windowFreq[currentChar] == tFreq[currentChar]) {
                formedChars++;
            }

            //contract window from the left
            while (formedChars == requireChars && start <= end) {
                // update minimum winodw size and start index
                if (end - start + 1 < minWindowLength) {
                    minWindowLength = end - start + 1;
                    minWindowStart = start;
                }

                char leftChar = s[start];
                windowFreq[leftChar]--;
                if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                    formedChars--;
                }

                //move window start to the right
                start++;
            }

            // move window end to the right
            end++;
        }

        return minWindowLength == INT_MAX ? "" : s.substr(minWindowStart, minWindowLength);
    }
};
