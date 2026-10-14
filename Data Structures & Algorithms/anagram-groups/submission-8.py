
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict_word = {}

        for s in strs:
            key = ''.join(sorted(s))

            if key not in dict_word:
                dict_word[key] = []

            dict_word[key].append(s)

        out = []
        for k, v in dict_word.items():
            out.append(v)

        return out
