#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a,b,r,q,w,e;
double d,h;
int gcd(int a,int b)
{
    if(b==0 )
        return a;
    return b == 0 ? a : gcd(b,a%b);
}
int lcm(int a,int b)
{
    return  a / gcd(a,b) * b;
}
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if (a.second < b.second)
        return 1;
    return 0;
}
int f(char a, char b)
{

    if(a == b )
    {

        return 1;
    }
    else
    {

        return 0;
    }

}
int main()
{
    int n,m,d;
    cin >> n >> m >> d;
    vector<int> a;
    set<int> rest;
    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            a.push_back((x-x%d)/d);
            rest.insert(x%d);
        }
    }
    if(rest.size() != 1 ) {
        cout << -1;
        return 0;
    }
    n = n*m;
    sort(a.begin(),a.end());
    int mid = a[n/2],cnt=0;
    for(int i = 0; i < n; i++) {
        cnt += abs(a[i]-mid);
    }
    cout << cnt;
    return 0;


}
