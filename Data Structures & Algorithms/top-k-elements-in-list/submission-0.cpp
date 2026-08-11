class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]] += 1;
        }
        vector<int> topFreq;
        for(int i = 0; i < k; i++) {
            int max = 0;
            int number = 0;
            for(auto& p: freq) {
                if(p.second > max) {
                    max = p.second;
                    number = p.first;
                }
            }
            topFreq.push_back(number);
            freq[number] = 0;
        }
        return topFreq;
    }
};
