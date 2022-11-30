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
    int n,ans1 = 0, ans2=0,cnt0=0,cnt1=0,j=0;
    string s;
    cin >> s;
    n=s.size();
    int last = -1;
    for(int i = 0; i < n; i++) {
        if(s[i]=='a'&&last==-1) {
            last=i;
            ans1++;
            continue;
        }
        if(s[i]=='a'){
            j++;
            if(i%2!=last%2){
                swap(cnt0,cnt1);
            }
            if((i-last+1)%2==0){
                cnt0++;
            }
            else cnt1++;
            ans1++;
            ans1 += cnt1;
            ans2 += cnt0;
            last=i;

        }

    }
    cnt0 = 0;
    cnt1 = 0;
    j = 0;
    last = -1;
    for(int i = 0; i < n; i++) {
        if(s[i]=='b'&&last==-1) {
            last=i;
            ans1++;
            continue;
        }
        if(s[i]=='b'){
            j++;
            if(i%2!=last%2){
                swap(cnt0,cnt1);
            }
            if((i-last+1)%2==0){
                cnt0++;
            }
            else cnt1++;
            last=i;
            ans1++;
            ans1 += cnt1;
            ans2 += cnt0;

        }

    }
    cout << ans2 << " " << ans1;


}
