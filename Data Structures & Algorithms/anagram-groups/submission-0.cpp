class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, int> cnt;
        int unique = 0;
        for(int i = 0; i < strs.size(); i++) {
            int freq[26] = {};

            for(auto& c : strs.at(i)) {
                freq[c - 'a'] += 1;
            }

            string key;
            for(int j=0; j<26; j++) {
                key += "#" + to_string(freq[j]);
            }

            auto it = cnt.find(key);
            if(it != cnt.end()) {
                anagrams[it->second].push_back(strs.at(i));
            }else {
                cnt[key] = unique++;
                anagrams.push_back({strs.at(i)});
            }
        }
        return anagrams;
    }
};
