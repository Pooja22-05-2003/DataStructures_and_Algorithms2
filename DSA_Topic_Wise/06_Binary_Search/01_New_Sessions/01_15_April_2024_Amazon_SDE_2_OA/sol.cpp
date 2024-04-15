/*
TC - O(N*log(limit))

Takes O(1) size.


*/

#include <bits/stdc++.h>
using namespace std;
bool check(int mid,vector<int> arr, int day)
{
    int x=0;
    for(int i=0;i<arr.size();i++)
    {
        if((arr[i]%mid)==0) x+=((arr[i])/mid);
        else x+=(((arr[i])/mid)+1);
    }
    // cout<<"mid:"<<mid<<" x:"<<x<<endl;
    return (x<=day)? true: false;
}
int solve(int n, vector<int> arr, int day)
{
    if(day<n) return -1;
    int l=n;
    int h=100000;

    while(l<=h)
    {
        int mid=(l+h)/2;
        // cout<<"l:"<<l<<" h:"<<h<<" Mid:"<<mid<<","<<"check:"<<check(mid,arr,day)<<endl;
        if(check(mid,arr,day)==false) 
        {
            l=mid+1;
        }
        else 
        {
            if(mid==0) return 0;
            if(check(mid-1,arr,day)==false) return mid;
            else h=mid-1;
        }
       
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    int n;
    cin >> n;

     int x;
    cin>>x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   
    
    int ans = solve(n, arr,x);

    cout << "ans:" << ans << endl;
    // for(auto it: ans) cout<<it<<",";
    cout<<endl;
    return 0;
}

/*
Input1:
4
5
2 3 4 5


Output:
ans:4


Input2:
3
4
5 3 4

Output:
ans:4


Input3:
3
4
2 4 3

Output:
ans:3



*/