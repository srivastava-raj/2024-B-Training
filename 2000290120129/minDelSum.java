class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int n=s1.length();
        int m=s2.length();
        int[][] dp=new int[n+1][m+1];
        return res(s1,s2,n,m,dp);
    }
    public int res(String s1,String s2, int n,int m,int[][] dp){
        if(m==0){
            int charSum=get(s1,n);
            return dp[n][m]=charSum;
        }if(n==0){
            return dp[n][m]=get(s2,m);
        }
        if(dp[n][m]!=0) 
            return dp[n][m];

        if(s1.charAt(n-1)==s2.charAt(m-1)){
            return dp[n][m]=res(s1,s2,n-1,m-1,dp);
        }else{
            int ans1=s1.charAt(n-1)+ res(s1,s2,n-1,m,dp);
            int ans2=s2.charAt(m-1) + res(s1,s2,n,m-1,dp);

            return dp[n][m]= Math.min(ans1,ans2);
        }
    }
    public int get(String s,int k){
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=(int)s.charAt(i);
        }
        return ans;
    }
}  
