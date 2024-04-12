/*
Observation :-> Let’s try to fix the middle interval ;

Lets say you are at an interval i -> [start,end] -> now tell me which will be those intervals on the left side which won't touch or intersect with us? 

Answer :- All the intervals whose endpoint is less than start will never touch interval i->[start,end]  on the lefthand side. -> we need to maintain their count 


-> Which are those intervals on the right hand side which will not touch our interval i [start,end] 

-> all the intervals; whose start pointer is greater than the end pointer of the interval i [start,end]  right side. 

Analysis :-> Done above only
Conclusion :-> For each interval “i” ; all you need to know is ; number of lets intervals which do not touch it and the number of right intervals which do not touch it —> once you know them both answer = (left*right)

-> for(i=1;i<=n;i++){

left-> number of intervals not intersecting with interval i on left side. 
right-> number of intervals not intersecting with interval i on right side
Answer = answer + left*right

}

print(answer) 


Left = number of intervals whose endpoint is less than y -> you can do this using binary search. —>O(logN)

Right = number of intervals whose startpoint is greater than z→ O(logN) 

TC : O(N*logN) 

*/
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ; 

int upper_bound(vector <ll> arr, ll target) {
        int left = 0;
        int right = arr.size();
        right = right - 1 ; 
        while (left <= right) {
            int mid = (left + right)/2 ; 
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
               if(mid==0){
                   return 0; // here mid is not satifying the condition, so we returned 0
               }
 
               else{
               	   if(arr[mid-1]<=target){
               	   	return mid ; // here mid-1 is satifying the condition but array is 1 based so we returned mid
               	   }
               	   else{
               	   	right = mid - 1 ; 
               	   }
 
               }
            }
        }
 
        return left;
}
 




int main(){
    
    ll n ; 
    cin>>n ; 
    vector <ll> start;
    vector <ll> end;
    vector <pair<ll,ll>> g(n,{0,0});
    
    ll i = 0 ; 
    while(i<=n-1){
        ll y;cin>>y ; 
        start.push_back(y);
        g[i].first = y ; 
        i++;
    }
    
    i = 0 ; 
    while(i<=n-1){
        ll y;cin>>y ; 
        end.push_back(y);
        g[i].second = y ; 
        i++;
    }
    
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    ll count = 0 ; 
    i = 0 ; 
    while(i<=n-1){
        
        ll x = g[i].first ; 
        ll y = g[i].second ; 
        
        //cout<<x<<" "<<y;
        //cout<<"\n";
        ll v1 = upper_bound(end,x-1);
        ll v2 = abs(n-upper_bound(start,y));
        cout<<v1<<" "<<v2<<"\n";
        count = count + v1*v2;
        i++;
    }
    
    cout<<count ; 
    return 0 ; 
}