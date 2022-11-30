#include <bits/stdc++.h>
#define int long long
using namespace std;
//Solution + fenwick tree
int f(int x, vector<int>&a, vector<int>&b)
{
    int d = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] < x) d += (x-a[i]);
    }
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i]>x)d+=(b[i]-x);
    }
    return d;
}
main()
{
    int n,m;
    cin >> n  >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int l = 1;
    int r = 1e10;
    while (r - l > 1)
    {

        int m1 = l + (r - l) / 3,
            m2 = r - (r - l) / 3;
//        cout <<l << " "<<r << " " << m1 << " " << m2 << endl;;
        if (f(m1,a,b) > f(m2,a,b)){
            if(l==m1)break;
            l = m1;
        }
        else{
            if(r==m2)break;
            r = m2;
        }
    }
    int minx = 1e18;
    for(int i = l-10; i <= r+10; i++) {
        minx=min(minx,f(i,a,b));
    }
    cout << minx;

}
