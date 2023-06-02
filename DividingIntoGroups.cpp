// Q) Dividing Into Groups -> https://www.codechef.com/problems/DIVIDE_GROUP?tab=statement

// ans)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

// i) better implementation : 

bool check(ll grps,int k,vector<ll>& a){
    ll cursum = 0;
    for(int i=0;i<a.size();i++){
        cursum += min(grps,a[i]);
    }
    return (k*grps <= cursum);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<ll> a(n);
	    ll sum = 0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum += a[i];
	    }
	    ll low = 0,high = sum/k;
	    while(high-low > 1){
	        ll mid = (low+high)>>1;
	        if(check(mid,k,a)){
	            low = mid;
	        }
	        else high = mid-1;
	    }
	    if(check(high,k,a)) cout<<high<<endl;
	    else cout<<low<<endl;
	}
	return 0;
}

// ii) Other implementation : (SAME APPROACH)

bool check(ll grps,int k,vector<ll>& a,vector<ll>& pre){
    int n = a.size();
    ll cursum = 0;
    ll low = 0,high = n-1;
    int index = -1;
    while(high-low>1){
        ll mid = (low + high)>>1;
        if(a[mid] >= grps){
            high = mid-1;
        }
        else{
            low = mid;
        }
    }
    if(a[high] < grps) index = high;
    else if(a[low] < grps) index = low;
    if(index == -1){
        cursum = n*grps;
    }
    else{
        cursum = pre[index] + (n-1-index)*grps;
    }
    return (k <= cursum/grps);
}

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    vector<ll> a(n);
	    vector<ll> pre(n,0);
	    ll sum = 0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a.begin(),a.end());
	    pre[0] = a[0];
	    for(int i=1;i<n;i++){
	        pre[i] = pre[i-1] + a[i];
	    }
	    sum = pre[n-1];
	    ll low = 0,high = sum/k;
	    ll ans = 0;
	    while(high-low > 1){
	        ll mid = (low+high)>>1;
	        if(check(mid,k,a,pre)){
	           low = mid;
	        }
	        else high = mid-1;
	    }
	    if(check(high,k,a,pre)) cout<<high<<endl;
	    else cout<<low<<endl;
	   //cout<<ans<<endl;
	}
	return 0;
}
