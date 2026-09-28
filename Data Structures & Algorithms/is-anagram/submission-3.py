class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        freq_let_s = {}
        freq_let_t = {}
        for c in s:
            if c in freq_let_s:
                freq_let_s[c] += 1
            else:
                freq_let_s[c] = 1

        for c in t:
            if c in freq_let_t:
                freq_let_t[c] += 1
            else:
                freq_let_t[c] = 1

        for i in freq_let_s:
            if i not in freq_let_t or freq_let_s[i] != freq_let_t[i]:
                return False

        return True