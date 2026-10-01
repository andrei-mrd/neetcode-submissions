class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.find(s1) != string::npos) {
            return true;
        }
        unordered_map<char, int> freqs1;
        for(int i = 0; i<s1.size(); i++) {
            freqs1[s1[i]] +=1;
        }
        unordered_map<char, int> freqs2;
        int i = 1, start = 0;
        freqs2[s2[start]] +=1;
        while(i < s2.size()) {
            freqs2[s2[i]]+=1;
            if(i + 1 - start == s1.size()) {
                if(freqs1 == freqs2) {
                    return true;
                }
                freqs2[s2[start]] -= 1;
                if (freqs2[s2[start]] == 0) {
                    freqs2.erase(s2[start]);
                }
                start++;
            }
            i++;
        }
        return false;
    }
};
