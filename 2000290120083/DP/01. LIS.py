# https://leetcode.com/problems/longest-increasing-subsequence/

class Solution:
    def lengthOfLIS(self, nums):
        dp = [0] * len(nums)
        
        for i in range(len(nums)):
            temp = 0
            for j in range(i):
                if nums[j] < nums[i]:
                    temp = max(temp, dp[j])
            dp[i] = temp + 1
        
        res = 0
        for i in range(len(nums)):
            res = max(res, dp[i])
            
        return res
# Time Complexity = O(N*N/2) = O(N*N)
# Space Complexity = O(N)  # as we took a 1D array



