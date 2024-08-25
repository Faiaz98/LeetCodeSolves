class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); //number of cars
        if (n == 0) return 0; //no cars = no fleets

        //vector to store pairs of position and time to reach the target
        vector<pair<int, double>> cars(n);

        //fill the cars vector with positions and time to reach the target
        for(int i = 0; i < n; i++) {
            double timeToTarget = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], timeToTarget};
        }

        //sort cars by their positions in decending order (from nearest to farthest from the destination)
        sort(cars.begin(), cars.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.first > b.first; //sort by position decending
        });

        int fleets = 0;
        double lastTime = 0.0;

        for (int i = 0; i < n; i++) {
            if(cars[i].second > lastTime) {
                fleets++;
                lastTime = cars[i].second;
            }
        }

        return fleets;
    }
};
