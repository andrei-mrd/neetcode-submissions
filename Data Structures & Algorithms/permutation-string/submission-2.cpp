class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.find(s1) != string::npos) {
            return true;
        }
        unordered_map<char, int> freqs1;
        int start = 0;
        int i = 1;
        for(int i = 0; i<s1.size(); i++) {
            freqs1[s1[i]] += 1;
        }
        unordered_map<char, int> freqs2;
        freqs2[s2[start]]++;
        
        while(i < s2.size()) {
            freqs2[s2[i]]++;
            if(i + 1 - start == s1.size()) {
                bool ok = true;
                for(auto& p : freqs1) {
                    if(p.second != freqs2[p.first]) {
                        ok = false;
                        break;
                    }
                }
                if(ok == true) {
                    return true;
                }
                freqs2[s2[start]] -=1;
                start++;
            }
            i++;
        }
        return false;
    }
};