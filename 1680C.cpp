#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int mx = 1e7+2;
const int INF = 1e18;
int fact[mx];
vector<int> c0;
vector<int> c1;
int n;
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
int cnt0(int l, int r)
{
    if(l > r) return 0;
    if(!l) return c0[r];

    return (c0[r]-c0[l-1]+mod)%mod;
}
int cnt1(int l, int r)
{
    if(l > r) return 0;
    if(!l) return c1[r];
    return (c1[r]-c1[l-1]+mod)%mod;
}
int f1(int l, int r) {

    return cnt1(0,l-1)+cnt1(r+1,n-1);
}
int f2(int l, int r) {
    return cnt0(l,r);
}
void solve()
{
    int ans = INF;
    string s;
    cin >> s;
    n=s.size();
    c0.resize(n,0);
    c1.resize(n,0);
    c0[0] = (s[0]=='0');
    c1[0] = (s[0]=='1');
    for(int i = 1; i < n; i++)
    {
        c0[i] = c0[i-1] + (s[i]=='0');
        c1[i] = c1[i-1] + (s[i]=='1');
    }
    for(int l = 0; l < n; l++)
    {
        int lr = l;
        int rr = n;
    
        while(rr-lr>1) {
            int mid=(lr+rr)/2;
            if(f1(l,mid) < f2(l,mid)) {
                rr = mid;
            }
            else lr = mid;
        }

        ans=min(ans,max(f1(l,lr),f2(l,l)));

    }
    cout << min(ans,cnt1(0,n-1));
}
main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
        cout << '\n';
    }



}
