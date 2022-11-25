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
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n;
    vector<pair<int,int> > a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back({x,0});
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        a.push_back({x,1});
    }
    sort(a.begin(),a.end());
    int x = 0, y = 0,ans = 3*n - 3*m,cnt1 = 3*n,cnt2 = 3*m;
    for(int i = 0; i < a.size(); i++)
    {
        while(i+1 < a.size()&& a[i+1].first == a[i].first)
        {
            if(!a[i].second)x++;
            else y++;
            i++;
        }
        if(!a[i].second) x++;
        else y++;
        if(ans < 3*n-3*m-x+y)
        {
            ans = 3*n-3*m-x+y;
            cnt1 = 3*n-x;
            cnt2 = 3*m-y;
        }
    }
    cout << cnt1 << ':' << cnt2;



}
