// Learnt like if n is odd other than 1, then the sum of all numbers from 1 to n is divisible by n. And this is not true if n is even.  

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        if(n == 1) cout<<"1\n";
        else if(n % 2 == 1) cout<<"-1\n";
        else{
            int a = n-1;
            int b = n;
            int x = n/2;
            while(x--){
                cout<<a<<" "<<b<<" ";
                a-=2;
                b-=2;
            }
            cout<<"\n";
        }
    }
    return 0;
}
