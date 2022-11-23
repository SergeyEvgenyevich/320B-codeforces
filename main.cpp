#include<bits/stdc++.h>
#define int long long
const int N = 1e5;
using namespace std;
typedef long long ll;
main()
{
    int n;
    cin >> n;
    vector<int> a(N+1,0);
    vector<int> dp(N+1,0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }

    for(int i = 1; i <= N; i++) {
        dp[i] = max(dp[i-1],dp[max(0ll,i-2)] + i*a[i]);
    }
    cout<<dp[N];

}
