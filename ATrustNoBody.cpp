//  https://codeforces.com/contest/1826/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

// bool check(int k, int a, int b, int c){

// }

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l[n];
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        int ans = -1;
        for(int liars = 0;liars <= n;liars++){
            int trueliars = 0;
            for(int i=0;i<n;i++){
                if(l[i] > liars) trueliars++;
            }
            if(trueliars == liars){
                ans = trueliars;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
