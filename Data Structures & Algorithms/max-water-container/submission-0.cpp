class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int k = heights.size() - 1;
        int maxi = 0;
        while(i < k) {
            int prod = (k - i) * min(heights[i], heights[k]);
            if(prod > maxi) {
                maxi = prod;
            }
            if(heights[i] < heights[k]) {
                i++;
            }else if(heights[i] > heights[k]) {
                k--;
            }else {
                i++;
                k--;
            }
        }
        return maxi;
    }
};