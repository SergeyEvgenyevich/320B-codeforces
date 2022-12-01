#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int mx = 1e7+2;
const int INF = 1e18;
int fact[mx];
int binpow(int a,int n)
{
    if(!n) return 1;
    if(n==1) return a;
    if(n%2==1) return a*binpow(a,n-1);
    else
    {
        int t = binpow(a,n/2);
        return t*t;
    }
}
int inverse(int x)
{
    return binpow(x,mod-2);
}
int div_mod(int a, int b)
{
    return a*inverse(b)%mod;
}
int cnk(int n, int k)
{
    if(n<k) return 0;
    return div_mod(fact[n],fact[k]*fact[n-k]%mod);
}

int gcd(int a, int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int sum(int l, int r,vector<int>&a)
{
    if(l > r) return 0;
    if(!l) return a[r];

    return (a[r]-a[l-1]+mod)%mod;

}
main()
{
    string s;
    cin >> s;
    int m,n = s.size();
    cin >> m;
    vector<int> a;
    vector<vector<int> > dp((1<<n),vector<int>(m,0));
    vector<bool> mp((1<<n),0);
    vector<int> cnt(10,0);
    for(int i = 0; i < s.size(); i++)
    {
        int x=s[i]-'0';
        a.push_back(x);
    }

    int x = 1;
    for(int i = 0; i < 19; i++) {
        mp[x]=1;
        x=x*2;
        if(x>=mp.size())break;
    }
    dp[0][0]=1;
    for(int mask = 1; mask < (1<<n); mask++)
    {
        for(int i = 0; i < n; i++)
        {
            if (!((mask >> i) & 1) || (mp[mask] && !a[i])) continue;
            int new_mask = mask ^ (1<<i);
            for(int j = 0; j < m; j++)
            {
                dp[mask][(j*10+a[i])%m] += dp[new_mask][j];
            }
        }
    }
    int ans = dp[(1<<n)-1][0];
    vector<int> fact(n+1,1);
    for(int i = 2; i <= n; i++) fact[i] = fact[i-1]*i;
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for(int i = 0; i < 10; i++) ans = ans/fact[cnt[i]];
    cout << ans;




}
