class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, int> frecventa;
        for(auto x: nums) {
            frecventa[x]++;
        }
        for(auto pereche: frecventa) {
            if(pereche.second > 1) {
                return true;
            }
        }
        return false;
    }
};