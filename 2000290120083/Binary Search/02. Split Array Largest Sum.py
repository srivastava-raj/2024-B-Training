# https://leetcode.com/problems/split-array-largest-sum/

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        
        l = max(nums);  r = sum(nums);  ans = -1
        
        if len(nums) < m: return -1  
        def isValid(nums, m, mid):
            currSum = 0             
            countOfSubarrays = 1     
            
            for val in nums:
                currSum += val
                if currSum > mid:          
                    countOfSubarrays += 1  
                    currSum = val          
            
            if countOfSubarrays > m: return False
            else: return True
        
        
        while l <= r:
            mid = (r+l) // 2
            if isValid(nums, m, mid):
                ans = mid          
                r = mid - 1        
            else:
                l = mid + 1        
        
        return ans                   
            
            
            
