class Solution {
public:

    string encode(vector<string>& strs) {
        string sentence;
        for(auto& s : strs) {
            sentence += s;
            sentence.push_back('\n');
        }
        return sentence;
    }

    vector<string> decode(string s) {
        vector<string> words;
        string word;
        for(auto& c : s) {
            if(c != '\n') {
                word.push_back(c);
            }else {
                words.push_back(word);
                word.clear();
            }
        }
        return words;
    }
};
