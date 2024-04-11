#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ;

ll v(ll g1,vector<pair<ll,ll>> & g){
    
    ll n = g.size();
    ll low = 0 ; 
    ll high = n-1;
    while(low<=high){
        ll mid = (low+high)/2;
        //cout<<low<<" "<<high<<'\n';
        if(mid==0){
            if(g[mid].first<g1){
                
                if(mid+1<=n-1){
                    if(g[mid+1].first>=g1){
                    return 0;
                    }
                    else{
                        low = mid + 1 ;
                    }
                }
                else{
                return 0;
                }
        }
        else{
            return -1;
        }
            
        }
        
        if(g[mid].first<g1){
            
            if(mid+1<=n-1){
                if(g[mid+1].first>=g1){
                    return mid;
                }
                else{
                    low = mid + 1 ; 
                }
                
            }
            else{
                return mid;
            }
        }
        else{
            high = mid-1;
        }
        
        
    }
    
    return -1 ; 
    
}


int main() {
    ll n;
    cin>>n;
    ll b[n+1][3];
    
    vector<pair<ll,ll>> g ; 
    ll i = 1 ;
    while(i<=n){
        cin>>b[i][0]>>b[i][1]>>b[i][2];
        g.push_back({b[i][1],b[i][2]});
        i++;
    }
    
    sort(g.begin(),g.end());
    
    ll pmin[n];
    ll pmax[n];
    
    pmin[0]=g[0].second;
    pmax[0]=g[0].second;
    
    i = 1 ; 
    while(i<=n-1){
        pmin[i]=min(pmin[i-1],g[i].second);
        pmax[i]=max(pmax[i-1],g[i].second);
        i++;
    }
    
    
    ll answer = 1e18;
    i = 1 ;
    while(i<=n){
        ll g1 = b[i][0];
        ll cost = b[i][2];
        ll id = v(g1,g);
        //cout<<g1<<" "<<id<<'\n';
        if(g1!=-1){
        if(cost>=0){
            ll bb = cost*pmin[id];
            answer = min(answer,bb);
        }
        else{
            ll bb = cost*pmax[id];
            answer = min(answer,bb);
        }
        }
        i++;
    }
    
    cout<<answer ; 
    return 0;
}

