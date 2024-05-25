#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int main() {
    ll n;cin>>n;
    ll b[n+1]={0};
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    ll k;cin>>k;
    
    ll dp[n+1]={0};
    for(ll i=1;i<=n;i++){
        dp[i]=1;
    }
    
    
    
    ll p=1;for(ll i=2;i<=n;i++){
        
        for(ll j=i-1;j>=1;j--){
            if( (b[i]+b[j])%k==0){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        //cout<<dp[i]<<"\n";
        p = max(p,dp[i]);
    }
    
    
    
    
    cout<<p;
}