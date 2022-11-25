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
    int n;
    cin >> n;
    vector<vector<int > > a(n,vector<int>(n));
    vector<int> d1(2*n,0);
    vector<int> d2(2*n,0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            d1[i+j] += a[i][j];
            d2[n-i+j] += a[i][j];
        }
    int sum0 = 0;
    int sum1 = 0;
    int x0=1,y0=1,x1=1,y1=2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            int sum = d1[i+j] + d2[n-i+j] - a[i][j];
            if((i+j)%2==0 && sum > sum0) {
                sum0 = sum;
                x0 = i+1;
                y0 = j+1;
            }
            if((i+j)%2==1 && sum > sum1) {
                sum1 = sum;
                x1 = i+1;
                y1 = j+1;
            }

        }
    }
    cout << sum0 + sum1 << '\n';
    cout << x0 << " " << y0 << " " << x1 << " " << y1;





}
