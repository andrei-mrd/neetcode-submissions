class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        if(s.size() == 1) {
            return 1;
        }
        unordered_map<char, int> freq;
        int length = 0;
        int maxLength = 0;
        int start = 0;
        int i = 0;
        while(i < s.size()) {
            if(freq[s[i]] == 0) {
                length++;
                freq[s[i]] += 1;
                i++;
            }else {
                if(length > maxLength) {
                    maxLength = length;
                }
                freq[s[start]] = 0;
                start++;
                length --;
            }
        }
        
        if(length > maxLength) {
            maxLength = length;
        }
        return maxLength;
    }
};
