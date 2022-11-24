#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{

    int n;
    cin >> n;
    vector<int> a(n,0);
    int minx = 1e9, pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < minx) {
            minx = a[i];
            pos = i;
        }
    }
    int i = 0;
    while(pos==0&&i+1 < n && a[i+1]==a[0]) i++;
    for(int j = i+1; j < n; j++) {
        if(a[j]==minx) {
            pos = j;
            break;
        }
    }
    i = pos+1;
    int last=a[pos];

    while(i != pos){
        if(i==n) i=0;
        if(i==pos) break;
        if(a[i]<last) {
            cout << -1;
            return 0;
        }
        last = a[i];
        i++;
    }
    cout << (n-pos)%n;
}
