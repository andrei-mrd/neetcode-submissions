class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vfreq(26, 0);

        int start = 0;
        int maxLength = 0;

        for(int i = 0; i < s.size(); i++) {

            // introducem caracterul curent
            vfreq[s[i] - 'A']++;

            // găsim frecvența maximă
            int maxi = 0;

            for(int j = 0; j < 26; j++) {
                maxi = max(maxi, vfreq[j]);
            }

            // lungimea ferestrei curente
            int length = i - start + 1;

            // dacă sunt necesare prea multe replacement-uri
            while(length - maxi > k) {
                vfreq[s[start] - 'A']--;
                start++;

                length = i - start + 1;

                // recalculăm maxi
                maxi = 0;
                for(int j = 0; j < 26; j++) {
                    maxi = max(maxi, vfreq[j]);
                }
            }

            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};