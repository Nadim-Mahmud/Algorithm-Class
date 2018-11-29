
///        Dynamic Programming

///   *** Subset Sum [m*n]

ll n,k,ara[105],dp[10005];

ll ways()
{
    ll i,j;
    memset(dp,0,sizeof dp);
    dp[0] = 1;
    for(j=1;j<=n;j++){
        for(i=1;i<=k;i++){
            if(i>=ara[j]){
                dp[i] = dp[i] + dp[i-ara[j]];
            }
        }
    }
    return dp[k];
}

