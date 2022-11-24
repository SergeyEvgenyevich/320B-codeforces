//O(N*K)
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
main()
{
    int n,k,d,ans=0;
    cin >> n >> k >> d;
    vector<vector<int> > dp(n+1,vector<int>(2,0));
    dp[0][0]=1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++){
            if(i-j<0)break;
            if(j >= d) {
                dp[i][1] = (dp[i][1]+dp[i-j][0])%MOD;
                dp[i][1] = (dp[i][1]+dp[i-j][1])%MOD;
            }
            else{
                dp[i][1]=(dp[i][1]+dp[i-j][1])%MOD;
                dp[i][0]=(dp[i][0]+dp[i-j][0])%MOD;
            }
        }
    }
    cout << dp[n][1];


}
