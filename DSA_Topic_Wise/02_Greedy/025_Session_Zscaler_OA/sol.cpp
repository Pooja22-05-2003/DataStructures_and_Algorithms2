/*
1. First store all the el , with its index in the set, set will store value in ascending order.
2.Then keep 1 visited array and pic the set el one by one, and if ind-1 and ind+1 is not visited of the current element, then mark it as visited
3. Follow this for all set elemeent
4. Finally return the ans.
*/


// TC=O(nlogn)
// SC=O(n)
#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>arr)
{
    vector<int>vis(n,0);
    int ans=0;
    set<pair<int,int>>s;
    for(int i=0;i<n;i++) s.insert({arr[i],i});

    for(auto it :s)
    {
        auto curr=it;
        int val=curr.first;
        int ind=curr.second;
        if(vis[ind]==0)
        {
            vis[ind]=1;
            ans+=val;

            if(ind-1>=0) vis[ind-1]=1;
            if(ind+1<=n-1) vis[ind+1]=1;
          
        }
    }

    return ans;


}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //**********
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  
    
    int ans=solve(n,arr);
    cout<<"ans:"<<ans<<endl;
    return 0;
}

/*
Input1:
7
6 4 9 10 34 56 54


Output:
ans:68





*/