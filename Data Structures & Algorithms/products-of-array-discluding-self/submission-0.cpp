class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix;
        vector<int> prefix;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                prefix.push_back(1);
            }else {
                prefix.push_back(prefix[i-1] * nums[i-1]);
            }
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i == nums.size() - 1) {
                suffix.push_back(1);
            }else {
                suffix.push_back(suffix[suffix.size() - 1] * nums[i + 1]);
            }
        }
        reverse(suffix.begin(), suffix.end());
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            result.push_back(prefix[i] * suffix[i]);
        }
        return result;
    }
};