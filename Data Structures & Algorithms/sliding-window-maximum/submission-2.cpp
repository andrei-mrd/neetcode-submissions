class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxis;
        deque<int> actualMax;

        for(int i = 0; i<nums.size(); i++) {
            while(!actualMax.empty() && actualMax.front() <= i - k) {
                actualMax.pop_front();
            }

            while(!actualMax.empty() && nums[actualMax.back()] <= nums[i]) {
                actualMax.pop_back();
            }

            actualMax.push_back(i);

            if(i >= k - 1) {
                maxis.push_back(nums[actualMax.front()]);
            }
        }
        return maxis;
    }
};
