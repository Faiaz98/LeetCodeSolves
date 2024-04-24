class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> freqS1(26, 0);
        vector<int> freqWindow(26, 0);

        for (char c : s1) {
            freqS1[c - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            freqWindow[s2[i] - 'a']++;
        }

        if (freqS1 == freqWindow) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            freqWindow[s2[i] - 'a']++;
            freqWindow[s2[i - s1.length()] - 'a']--;
            
            if (freqS1 == freqWindow) return true;
        }

        return false;
    }
};
