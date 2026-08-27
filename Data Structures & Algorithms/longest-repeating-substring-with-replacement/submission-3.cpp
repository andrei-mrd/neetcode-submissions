class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) {
            return 0;
        }

        int start = 0;
        int i = 0;
        int maxLength = 0;

        unordered_map<char, int> freq;

        while(i < s.size()) {
            freq[s[i]]++;

            int maxi = 0;
            for(auto& p : freq) {
                maxi = max(maxi, p.second);
            }

            int length = i - start + 1;

            while(length - maxi > k) {
                freq[s[start]]--;
                start++;

                // trebuie recalculat maxi pentru noua fereastra
                maxi = 0;
                for(auto& p : freq) {
                    maxi = max(maxi, p.second);
                }

                length = i - start + 1;
            }

            maxLength = max(maxLength, length);

            i++;
        }

        return maxLength;
    }
};