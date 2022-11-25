#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18+7;
const int max_size = 1e5+1;
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

main()
{
    int n,sum = 0,ans=0;
    vector<int> a(26,0);
    map<int,int> mp[26];
    vector<vector<int> > d(26,vector<int>());
    for(int i = 0; i < 26; i++) cin >> a[i];
    string s;
    cin >> s;
    n = s.size();
    for(int i=0; i < n; i++)
    {
        ans+=mp[s[i]-'a'][sum];
        sum += a[s[i]-'a'];
        mp[s[i]-'a'][sum]++;

    }
    cout<<ans;

}
