class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1 || s.size() == 0) {
            return s.size();
        }
        unordered_map<char, int> freq;
        int length = 0;
        int max_length = 0;
        int i = 0, start = 0;
        while(i < s.size()) {
            if(freq[s[i]] == 0) {
                freq[s[i]] += 1;
                i++;
                length += 1;
            }else {
                if(length > max_length) {
                    max_length = length;
                }
                freq[s[start]] = 0;
                start++;
                length -= 1;
            }
        }
        if(length > max_length) {
            max_length = length;
        }
        return max_length;
    }
};
