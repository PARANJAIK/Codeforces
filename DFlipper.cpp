Q) D. Flipper -> https://codeforces.com/contest/1833/problem/D

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
        vector<int> p(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        if(n == 1){
            cout<<p[0]<<endl;
            continue;
        }
        int search = n;
        if(p[0] == n) search = n-1;
        if(p[n-1] == search){
            int r = n-1;
            int l = n-2;
            int start = 0;
            while(l >= 0 && p[l] > p[start]){
                l--;
            }
            l++;
            vector<int> ans;
            for(int i=r+1;i<n;i++){
                // ans.push_back(p[i]);
                cout<<p[i]<<" ";
            }
            for(int i=r;i>=l;i--){
                // ans.push_back(p[i]);
                cout<<p[i]<<" ";
            }
            for(int i=0;i<l;i++){
                // ans.push_back(p[i]);
                cout<<p[i]<<" ";
            }
            cout<<"\n";
        }
        else{
            int index = 0;
            for(int i=0;i<n;i++){
                if(p[i] == search){
                    index=i;
                    break;
                }
            }
            int r = index-1;
            int l = r-1;
            int start = 0;
            while(l >= 0 && p[l] > p[start]){
                l--;
            }
            l++;
            vector<int> ans;
            for(int i=r+1;i<n;i++){
                // ans.push_back(p[i]);
                cout<<p[i]<<" ";
            }
            for(int i=r;i>=l;i--){
                // ans.push_back(p[i]);
                cout<<p[i]<<" ";
            }
            for(int i=0;i<l;i++){
                // ans.push_back(p[i]);
                cout<<p[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
