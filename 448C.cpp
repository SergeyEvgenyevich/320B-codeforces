#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18+7;
const int max_size = 1e5+1;
const int INF = 1e18;
int fact[max_size];
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
    return a[r]-a[l-1];

}
vector<int> a;
int rec(int l, int r)
{
    if(l>r)return 0;
    if(l==r) return 1;
    int minx=INF;
    for(int i = l; i <= r; i++) minx = min(minx,a[i]);
    int ans = minx,last=l;
    for(int i = l; i <= r; i++)
    {
        a[i] -= minx;
        if(!a[i])
        {
            if(i-1>=last)
                ans += min(i-last,rec(last,i-1));
            last = i+1;
        }
    }
    return min(r-l+1,rec(last,r)+ans);

}
main()
{
    int n;
    cin >> n;
    a.resize(n,0);
    for(int i =0; i < n; i++) cin >> a[i];
    cout << rec(0,n-1);
}
