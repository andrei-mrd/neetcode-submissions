class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int maxCapacity = 0;
        int capacity;
        while(i < j) {
            capacity = min(heights[i], heights[j]) * (j - i);
            if(capacity > maxCapacity) {
                maxCapacity = capacity;
            }
            if(heights[i] < heights[j]) {
                i++;
            }else {
                j--;
            }
        }
        return maxCapacity;
    }
};
