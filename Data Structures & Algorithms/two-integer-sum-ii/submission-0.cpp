class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> difIndex;
        for(int i = 0; i < numbers.size(); i++) {
            difIndex[target - numbers[i]] = i;
        }
        
        int first = 0, second = 0;
        
        for(int i = 0; i < numbers.size(); i++) {
            first = i + 1;
            auto index = difIndex.find(numbers[i]);
            if(index != difIndex.end()) {
                second = index->second + 1;
                break;
            }
        }
        
        return {first, second};
    }
};