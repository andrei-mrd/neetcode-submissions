class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dif;

        for (int i = 0; i < nums.size(); i++) {
            dif[target - nums[i]] = i;
        }

        int pos1 = 0, pos2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            auto it = dif.find(nums[i]);

            if (it != dif.end() && i != it->second) {
                if (nums[i] + nums[it->second] == target) {
                    pos1 = i;
                    pos2 = it->second;
                    break;
                }
            }
        }

        if (pos1 > pos2)
            swap(pos1, pos2);

        return {pos1, pos2};
    }
};