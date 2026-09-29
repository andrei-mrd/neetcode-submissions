class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for s in strs:
            vect_freq = [0] * 26
            for char in s:
                vect_freq[ord(char) - ord("a")] += 1

            t = tuple(vect_freq)
            if t not in groups:
                groups[t] = [s]
            else:
                groups[t].append(s)

        g = []

        for t in groups:
            g.append(groups[t])

        return g
        