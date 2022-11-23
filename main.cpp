// O(N*K) dynamic programming
#include <bits/stdc++.h>
#define int long long
using namespace std;
int sum(int l, int r, vector<int>&a) {
    if(!l) return a[r];
    return a[r]-a[l-1];
}
main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n,0);
    vector<int> pref(n,0);
    vector<vector<int> > dp(n,vector<int>(k+1,0));
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) i==0?pref[0]=a[0]:pref[i]=pref[i-1]+a[i];
    dp[m-1][1]=sum(0,m-1,pref);
    for(int i = m; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i-m][j-1]+sum(i-m+1,i,pref)));
        }
    }
    cout << dp[n-1][k];

}
