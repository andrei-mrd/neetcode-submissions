class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_dict = {}
        for num in nums:
            if num not in freq_dict:
                freq_dict[num] = 1
            else:
                freq_dict[num] += 1

        sorted_dict = dict(sorted(freq_dict.items(), key = lambda item: item[1], reverse = True))
        numbers = []
        for item in sorted_dict:
            if k == 0:
                break
            numbers.append(item)
            k-=1

        return numbers