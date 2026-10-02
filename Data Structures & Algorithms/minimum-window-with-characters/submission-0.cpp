class Solution {
public:
    string minWindow(string s, string t) {
        if(s.find(t) != string::npos) {
            return t;
        }

        if(s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> freqt;
        for(char& c : t) {
            freqt[c] += 1;
        }

        unordered_map<char, int> freqs;
        int i = 0;
        int start = 0;
        int bestStart = -1;
        int minLength = INT_MAX;
        while(i < s.size()) {
            freqs[s[i]] += 1;
            bool ok = true;

            for(auto& p : freqt) {
                if(p.second > freqs[p.first]) {
                    ok = false;
                    break;
                }
            }
            while(ok == true) {
                int length = i - start + 1;
                if(length < minLength) {
                    minLength = length;
                    bestStart = start;
                }

                freqs[s[start]]--;
                start++;

                ok = true;
                for(auto& p : freqt) {
                    if(p.second > freqs[p.first]) {
                        ok = false;
                        break;
                    }
                }
            }
            i++;
        }
        if(bestStart == -1) {
            return "";
        }

        return s.substr(bestStart, minLength);
    }
};
