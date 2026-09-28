class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i in range(len(nums)):
            dict[target - nums[i]] = i

        print(dict)

        for i in range(len(nums)):
            if nums[i] in dict.keys() and dict[nums[i]] != i:
                return [i, dict[nums[i]]]