class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> lettersS;
        std::map<char, int> lettersT;

        for(char c: s) {
            lettersS[c]++;
        }

        for(char c: t) {
            lettersT[c]++;
        }

        auto it1 = lettersS.begin();
        auto it2 = lettersT.begin();

        if(lettersS.size() != lettersT.size()) {
            return false;
        }

        while(it1 != lettersS.end() && it2 != lettersT.end()) {
            if(it1->first != it2->first || it1->second != it2 -> second) {
                return false;
            }else {
                ++it1;
                ++it2;
            }
        }

        return true;
    }
};
