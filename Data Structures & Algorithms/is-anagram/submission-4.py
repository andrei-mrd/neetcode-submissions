class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        freq_dict_s = {}
        freq_dict_t = {}

        for c in s:
            if c in freq_dict_s:
                freq_dict_s[c] += 1
            else:
                freq_dict_s[c] = 1

        for c in t:
            if c in freq_dict_t:
                freq_dict_t[c] += 1
            else:
                freq_dict_t[c] = 1

        for i in freq_dict_s:
            if i not in freq_dict_t or freq_dict_s[i] != freq_dict_t[i]:
                return False
        
        return True
        