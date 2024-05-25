class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColors;
        unordered_set<int> distinctColors; 
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];
            if (ballColors.find(ball) != ballColors.end()) {
                int oldColor = ballColors[ball];

                bool stillInUse = false;
                for (const auto& pair : ballColors) {
                    if (pair.second == oldColor && pair.first != ball) {
                        stillInUse = true;
                        break;
                    }
                }
                if (!stillInUse) {
                    distinctColors.erase(oldColor);
                }
            }

            ballColors[ball] = color;
            distinctColors.insert(color);

            result.push_back(distinctColors.size());
        }

        return result;
    }
};
