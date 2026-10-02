class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temps;
        vector<int> v(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i>=0; i--) {
            while(!temps.empty() && temperatures[temps.top()] <= temperatures[i]) {
                temps.pop();
            }

            if(!temps.empty()) {
                v[i] = temps.top() - i;
            }

            temps.push(i);

        }
        return v;
    }
};
