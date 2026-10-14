class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict_nums = {}
        for i in range(len(nums)):
            dict_nums[target - nums[i]] = i
        
        for i in range(len(nums)):
            if nums[i] in dict_nums and i != dict_nums[nums[i]]:
                return [i, dict_nums[nums[i]]]