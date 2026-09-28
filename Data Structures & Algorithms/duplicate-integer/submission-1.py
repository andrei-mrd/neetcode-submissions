class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        freq_vect = {}
        for num in nums:
            if freq_vect.get(num) is None:
                freq_vect[num] = 1
            else:
                return True

        return False