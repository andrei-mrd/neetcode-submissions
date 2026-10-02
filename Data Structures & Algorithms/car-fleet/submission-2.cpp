class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = 0;

        vector<pair<int, int>> p;

        for(int i = 0; i < position.size(); i++) {
            p.push_back({position[i], speed[i]});
        }

        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        vector<pair<int, double>> cars;

        for(auto& pa : p) {
            double time = (double)(target - pa.first) / pa.second;
            cars.push_back({pa.first, time});
        }

        double lastTime = -1;

        for(auto& car : cars) {
            double time = car.second;

            if(time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};