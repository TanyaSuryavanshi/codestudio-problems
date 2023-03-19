#include <bits/stdc++.h> 
#define MOD 1000000007
/*int solve(int nStairs,int i){
    if(i==nStairs)
        return 1;

    if(i>nStairs)
        return 0;
    return (solve(nStairs,i+1)+solve(nStairs, i+2))%MOD;
}*/
int countDistinctWays(int nStairs) {
    //  Write your code here.
    //int ans=solve(nStairs,0);
    //return ans;
    int dp[nStairs+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= nStairs; i++){
        if(i>nStairs)
            return 0;
        dp[i] = dp[i-1] + dp[i-2]%MOD;
    }
    return dp[nStairs];
}
