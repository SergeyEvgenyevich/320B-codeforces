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
    bool f=0;
    int n,a,b,d=2e18,c0=0,c1=0;
    cin >> n >> a >> b;
    if(a>b)
    {
        swap(a,b);
        f=1;
    }
    for(int x = a; x <= a+1e5; x++)
    {
        int y = (6*n+x-1)/x;
        if(x*max(y,b)< d)
        {
            d=x*max(y,b);
            c0=x,c1=max(y,b);
        }
    }
    cout << c0*c1 << endl;
    if(f)swap(c0,c1);
    cout << c0 << " " << c1;

}
