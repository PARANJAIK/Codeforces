// Q) Beautification of Array -> https://www.codechef.com/problems/BEAUTIFULARR

// Ans) 

// i) First point to observe is that changing the order of elements of the array doesn't change the beauty of array.
// ii) to maximize the beauty of array, we need to increase the lowest element by 1 until it gets equal to its right element, this way we increase the elements and max operations are k.
// iii) ***** One of the great thing i have used in this is the dp array, obviously it has nothing to do with dp . when i realised we have to increase all the elements less than and equal to that index by 1, i simply increased dp[i] by 1. And after the k operations, i traversed the dp array backwards and found by how much each element of the array has to be increased , and then updated them.
// iv) Then calculated the prefix sums of the array a[i], to avoid a O(n^2) loop in calculation of ans.

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<ll> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a.begin(),a.end());
	    ll M = 1e9 + 7;
	    vector<ll> diff(n);
	    for(int i=0;i<n-1;i++){
	        diff[i] = a[i+1] - a[i];
	    }
	    diff[n-1] = INT_MAX;
	    vector<ll> dp(n,0);
	    for(int i=0;i<n;i++){
	        int m = i+1; // no.of elements
	        ll x = 1LL*m*diff[i];
	        if(x < k){
	            dp[i] += diff[i];
	            k -= x;
	        }
	        else{
	            int y = k/m;
	            dp[i] += y;
	            y = k%m;
	            if(y!=0) dp[y-1] += 1;
	            k = 0;
	            break;
	        }
	    }
	    a[n-1] += dp[n-1];
	    for(int i=n-2;i>=0;i--){
	        dp[i] += dp[i+1];
	        a[i] += dp[i];
	    }
	    vector<ll> presum(n);
	    presum[0] = 0;
	    for(int i=1;i<n;i++){
	        presum[i] = presum[i-1] + a[i-1];
	    }
	    ll ans = 0;
	    for(int i=n-1;i>=0;i--){
	        ans = (ans%M + ((presum[i]%M)*(a[i]%M))%M)%M;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
