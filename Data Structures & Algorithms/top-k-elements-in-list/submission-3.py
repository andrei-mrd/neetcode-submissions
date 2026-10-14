class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dict_freq = {}
        for i in nums:
            if i not in dict_freq:
                dict_freq[i] = 1
            else:
                dict_freq[i] += 1
        
        dict_freq = dict(sorted(dict_freq.items(), key=lambda x: x[1], reverse=True))

        l = 0
        v = []
        for key, value in dict_freq.items():
            if l == k:
                return v
            v.append(key)
            l+=1
            
        return v
