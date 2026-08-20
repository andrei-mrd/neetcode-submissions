class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> palindrome;

        for(auto& c : s) {
            if(c >= 'A' && c <= 'Z' ||
               c >= 'a' && c <= 'z' ||
               c >= '0' && c <= '9') {
                palindrome.push_back(tolower(c));
            }
        }
    

        int i = 0, j = palindrome.size() - 1;

        while(i < j) {
            if(palindrome[i] != palindrome[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};