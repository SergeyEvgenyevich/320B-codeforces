#include <bits/stdc++.h>
#define int long long
using namespace std;
//Solution + fenwick tree
vector<int> t;
int n;
void init (int nn)
{

    t.assign (nn, 0);
}

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += delta;
}

int sum (int l, int r)
{
    return sum (r) - sum (l-1);
}


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0;
    cin >> n;
    init(n+1);
    vector<int> a(n+1,0);
    vector<int> r(n+1,0);
    vector<int> rm(n+1,0);
    vector<int> mp(n+1,0);
    map<int,int> m;
    int q = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(!m[a[i]])
        {
            m[a[i]]=q;
            a[i]=q;

            q++;
        }
        else a[i]=m[a[i]];
    }

    for(int i = n-1; i >= 0; i--)
    {
        rm[a[i]]++;
        inc(rm[a[i]],1);
    }
    for(int i=0; i < n; i++)
    {
        mp[a[i]]++;
        inc(rm[a[i]],-1);
        rm[a[i]]--;
        ans += sum(0,mp[a[i]]-1);;
    }
    cout << ans;





}
