

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        X = text1; Y = text2; n = len(text1); m = len(text2)
        def LCS(X, Y, n, m):
          
            if n == 0 or m == 0:
                return 0
            
         
            if X[n - 1] == Y[m - 1]: 
                return 1 + LCS(X, Y, n-1, m-1)
            
          
            else:
                return max(LCS(X, Y, n-1, m), LCS(X, Y, n, m-1))
        
        return LCS(X, Y, n, m)


