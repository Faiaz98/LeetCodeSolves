class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratios; //to store wage-to-quality ratio
        for (int i = 0; i < n; i++) {
            ratios.push_back({static_cast<double>(wage[i]) / quality[i], quality[i]});
        }
        sort(ratios.begin(), ratios.end());

        priority_queue<int> maxHeap;
        double minCost = numeric_limits<double>::max();
        int totalQuality = 0;

        for (auto& ratio : ratios) {
            totalQuality += ratio.second;
            maxHeap.push(ratio.second);
            if (maxHeap.size() > k) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                minCost = min(minCost, totalQuality * ratio.first);
            }
        }

        return minCost;
    }
};
