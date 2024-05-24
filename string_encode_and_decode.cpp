class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for (const string& str: strs) {
            encodedString += to_string(str.length()) + "#" + str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        int i = 0;
        while (i < s.length()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            decodedStrings.push_back(str);
            i = j + 1 + length;
        }

        return decodedStrings;
    }
};
