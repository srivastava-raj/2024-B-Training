# https://leetcode.com/problems/sort-colors/

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        left = 0
        mid = 0
        right = len(nums) - 1
        
        while mid <= right:
            if nums[mid] == 0:   # need to keep this 0 at low's place
                nums[left], nums[mid] = nums[mid], nums[left]
                left += 1

            elif nums[mid] == 2: # need to keep 2 this 2 at high's place
                nums[mid], nums[right] = nums[right], nums[mid]
                right -= 1
                mid -= 1

            mid += 1
        
        return nums

# Time: O(N)  # One Pass Solution
# Space: O(1)

