# https://leetcode.com/problems/rotate-array/

class Solution:
    def rotate(self, nums, k):
        n = len(nums)
        k = k % n
        
        # Step-1
        i = 0
        j = n-k-1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        i = n-k
        j = n-1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        

        i = 0
        j = n-1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1     
