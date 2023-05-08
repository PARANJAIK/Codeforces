// https://codeforces.com/contest/1829/problem/D

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
        int n,m;
        cin>>n>>m;
        if(m > n) cout<<"NO\n";
        else if(m == n) cout<<"YES\n";
        else{
           if(n%3 != 0) cout<<"NO\n";
           else{
            //    unordered_set<int> s;
            //    s.insert(n);
            //    bool flag = false;
            //    for(auto it = s.begin();it != s.end();it++){
            //       int num = *it;
            //       if(num%3 == 0){
            //         int x = num/3;
            //         s.insert(2*x);
            //         s.insert(x);
            //         if(2*x == m || x == m){
            //             flag = true;
            //             break;
            //         }
            //       }
            //    }
               vector<int> v;
               v.push_back(n);
               bool flag = false;
               for(int i=0;i<v.size();i++){
                  int num = v[i];
                  if(num%3 == 0){
                     int x = num/3;
                    v.push_back(2*x);
                    v.push_back(x);
                    if(2*x == m || x == m){
                        flag = true;
                        break;
                    }
                  }
               }
               if(flag) cout<<"YES\n";
               else cout<<"NO\n";
           }
        }
    }
    return 0;
}
