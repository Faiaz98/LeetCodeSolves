class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;  // Stack to store indices of the bars
        int maxArea = 0;

        // Iterate through all bars
        for (int i = 0; i < n; ++i) {
            // While the current bar is shorter than the bar at the top of the stack
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int height = heights[stk.top()];  // The height of the bar to be popped
                stk.pop();
                
                int width = stk.empty() ? i : i - stk.top() - 1;
                
                maxArea = max(maxArea, height * width);
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            int height = heights[stk.top()];
            stk.pop();
            int width = stk.empty() ? n : n - stk.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
