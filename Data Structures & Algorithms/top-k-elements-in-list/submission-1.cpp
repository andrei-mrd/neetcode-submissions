class Solution {
public:
    void insertionSort(vector<int>& nums) {
        for(int i = 1; i<nums.size(); i++) {
            int j = i;
            while(j > 0 && nums[j] < nums[j-1]) {
                swap(nums[j], nums[j-1]);
                j--;
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        // bucket[i] = numerele cu frecvența i
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, cnt] : freq)
            bucket[cnt].push_back(num);

        vector<int> result;
        for (int i = nums.size(); i >= 0 && (int)result.size() < k; i--)
            for (int num : bucket[i])
                if ((int)result.size() < k)
                    result.push_back(num);

        insertionSort(result);
        return result;
    }
};