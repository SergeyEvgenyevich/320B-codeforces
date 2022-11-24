//O(N*K^2)
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
main()
{
    int n,k,d,ans=0;
    cin >> n >> k >> d;
    vector<vector<int> > dp(201,vector<int>(201,0));
    for(int i = 1; i <=k; i++) dp[i][i]=1;

    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= k; j++) {

            for(int c = 1; c <= k; c++) {
                dp[i+c][max(j,c)] =  (dp[i+c][max(j,c)]+dp[i][j])%MOD;
            }
        }
    }
    for(int i = d; i <= k; i++) ans=(ans+dp[n][i])%MOD;
    cout << ans;

}
