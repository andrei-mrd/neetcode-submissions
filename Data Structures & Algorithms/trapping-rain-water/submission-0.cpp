class Solution {
public:
    int trap(vector<int>& height) {
        unordered_map<int, pair<int, int>> minMax;
        int indexMaxi = 0;
        int maxi = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] > maxi) {
                maxi = height[i];
                indexMaxi = i;
            }
            minMax[i] = {indexMaxi, 0};
        }
        maxi = 0;
        indexMaxi = height.size() - 1;
        for(int i = height.size() - 1; i >= 0; i--) {
            if(height[i] > maxi) {
                maxi = height[i];
                indexMaxi = i;
            }
            minMax[i].second = indexMaxi;
        }
        
        int water = 0;
        for(int i = 0; i < height.size(); i++) {
            int cantity = (min(height[minMax[i].first], height[minMax[i].second]) - height[i]);
            if(cantity > 0) {
                water += cantity;
            }
        }
        return water;
        
    }
};