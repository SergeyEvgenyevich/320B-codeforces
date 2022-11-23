// O(N) two pointers
#include <bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    int n;
    cin >> n;
    n=n*2;
    int r=1e5;
    for(int l = 1; l <= 1e5; l++) {
        while(r > 1 && r*(r+1) + l*(l+1) > n) r--;
        if(r*(r+1)+l*(l+1) == n) {
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
}
