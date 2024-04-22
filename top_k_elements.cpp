class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto& entry : freqMap) {
            pq.push(entry);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
