#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 

ll sol(vector <ll> b,ll point){
    
    ll n = b.size();
    ll low = 0 ; 
    ll high = n - 1 ; 
    ll kk = -1 ; 
    while(low<=high && kk==-1){
        ll mid = (low+high)/2 ;
        
        if(b[mid]<point){
            
            if((mid+1)<n && b[mid+1]<point){
                low = mid + 1 ; 
            } else {
                
                kk = mid ; 
            }
        } else {
            high = mid - 1 ; 
        }
    }
    
    
    
    
    return kk ; 
    
}



ll sl(vector <ll> b,ll point){
    ll n = b.size();
    ll low = 0 ; 
    ll high = n - 1 ; 
    ll kk = -1 ; 
    while(low<=high && kk==-1){
        ll mid = (low+high)/2 ;
        
        if(b[mid]>point){
            
            if((mid-1)>=0 && b[mid-1]>point){
                 high = mid - 1 ;  
            } else {
                kk = mid ; 
            }
        } else {
            low = mid + 1 ; 
        }
    }
    return kk ; 
}



int main() {
    
    ll n ; 
    cin>>n ; 
    
    vector <ll> start_x,end_x,s(n,0),g(n,0),sy(n,0),gy(n,0),start_y,end_y; 
    vector <ll> x,y; 
    
    ll i = 1 ; 
    while(i<=n){
        ll x1,y1,x2,y2 ; 
        cin>>x1>>y1 ; 
        cin>>x2>>y2 ; 
        
        start_x.push_back(x1);
        end_x.push_back(x2);
        x.push_back(x1);
        x.push_back(x2);
        
        start_y.push_back(y1);
        end_y.push_back(y2);
        y.push_back(y1);
        y.push_back(y2);
        
        
        i++;
    }
    
    sort(start_x.begin(),start_x.end());
    sort(end_x.begin(),end_x.end());
    
    sort(start_y.begin(),start_y.end());
    sort(end_y.begin(),end_y.end());
    
    i = 0 ; 
    while(i<=n-1){
        
        if(i==0){
            s[i] = end_x[i];
        } 
        else {
            s[i] = end_x[i] + s[i-1] ; 
        }
        
        if(i==0){
            sy[i] = end_y[i];
        } 
        else {
            sy[i] = end_y[i] + s[i-1] ; 
        }
        
        
        i++;
    }
    
    

    i = n - 1 ;
    while(i>=0){
        
        if(i!=n-1){
        g[i] = start_x[i] + 
        g[i+1] ;}
        else 
        {
            g[i] = start_x[i] ; 
        }
        
        
        if(i!=n-1){
        gy[i] = start_y[i] + 
        gy[i+1] ;}
        else 
        {
            gy[i] = start_y[i] ; 
        }
        
        i--;
    }
    
    
    ll KK = x.size();
    i = 0 ; ll min_x = 1e18 ;
    while(i<KK){
        ll start = x[i];//iterating through all possible points ....  
        ll index = sol(end_x,start);// points which are strictly less than start 
        ll iy = sl(start_x,start); //points which are strictly greater than start
        ll pp = 0 ; 
        if(index>=0){
            ll sum = ((index+1)*(start) - s[index]);
            pp+=(sum);
        }
        
        if(iy>=0){
            ll l = abs(iy-n);
            ll u = abs((l)*(start) - g[iy]); //
            pp+=(u);
        }
        //cout<<i<<" ";
        //cout<<pp<<'\n';
        //cout<<'\n';
        min_x = min(min_x,pp);
        i++;
    }
    
    
    KK = y.size(); ll miny = 1e18 ;
    i = 0 ; 
    while(i<KK){
        ll start = y[i]; 
        ll index = sol(end_y,start);// points which are strictly less than start 
        ll iy = sl(start_y,start); //points which are strictly greater than start
        ll pp = 0 ; 
        if(index>=0){
            ll sum = ((index+1)*(start) - sy[index]);
            pp+=(sum);
        }
        
        if(iy>=0){
            ll l = abs(iy-n);
            ll u = abs((l)*(start) - gy[iy]);
            pp+=(u);
        }
        //cout<<i<<" ";
        //cout<<pp<<'\n';
        //cout<<'\n';
        miny = min(miny,pp);
        i++;
    }
    
    
    
    ll ooKK = min_x + miny;
    
    
    cout<<ooKK ; 
    cout<<'\n';
    
    
    
    
    return 0 ; 
}

/*


3
0 0 2 0 
0 2 3 2
3 1 3 4 

output:
3 (sum of point p corodinate and the line min dist) and its not x and y cordinate value of point p


4 2 4 5
3 3 5 3
0 3 0 4

output:
4
Manhattan dist from point p(3,3) to the line segment 0,1 and 2 are 1,0,3 (1+0+3)=4

*/