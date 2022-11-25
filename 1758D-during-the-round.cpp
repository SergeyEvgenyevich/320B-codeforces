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
int sum(int l, int r)
{

    int n= r-l+1;
    return ((l+r)*n)/2;
}
void solve()
{
    int n;
    cin>>n;
    if(n==2) {
        cout << 3 << " " << 1;
        return;
    }
    for(int x=1; x <= 1e7; x++)
    {
        int l = -1;
        int r = 1e7;
        while(r-l > 1)
        {
            int minx = (r+l)/2;

            int mx = minx+x;
            if((mx-1)-(minx+1)+1 < n-2) break;
            int s1 = sum(minx+1,minx+n-2) + mx + minx;
            int s2 = sum(mx-(n-2),mx-1) + mx + minx;

            if(x*x <= s2&& x*x >= s1)
            {   n = n-2;
                int d = x*x-s1;

                int m = d%n;
                d = d /n ;
                vector<int> q;
                q.push_back(mx);
                l = minx+1;
                r = minx+n;
                for(int i = r; i >= l; i--) {

                    q.push_back(i + d + min(1ll,m));
                    if(m!=0)
                    m--;
                }
                q.push_back(minx);
                for(int i = q.size()-1; i >= 0; i--) cout << q[i] << " ";
                return;
            }
            if(x*x >= s2) l = minx;
            else r = minx;

        }

    }
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
