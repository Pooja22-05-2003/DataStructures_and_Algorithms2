/*
1. It is a greedy problem.
2. First to make the continuous range , sort the arr.
3. Then calcaulte the number left between 1 and starting el index first element.and call the count set bit fun
4. Then calculate the number left between the last ind last el and n. and call the count set bit fun.
5. Then calculat the inbetween elements left and add them in ans by counting the 1 bit.

6. Remeber , it will give wrong ans, if u calculate all the numbers and then only call function count_set_bit 1 times.
7. Return that total count at last.

*/

// TC=O(mlognm)+O(m*31)
// SC=O(1)
#include <bits/stdc++.h>
using namespace std;
int count_set_bits(int num)
{
    int cnt=0;
   
     for(int i=30;i>=0;i--)
    {
        int k=(num>>i);

        if((k&1)==1)
        {
            cnt++;
        }
        else 
        {
            
        }
    }
    return cnt;
}
int solve(int n, int m , vector<vector<int>>arr)
{
    sort(arr.begin(),arr.end());
    int ans=0;

   
    int x=abs(1-arr[0][0]);
    ans+=count_set_bits(x);
     
    x=abs(n-arr[m-1][1]);
    ans+=count_set_bits(x);
    
   
    for(int i=1;i<m;i++)
    {
       
        int x=abs(arr[i][0]-arr[i-1][1]);
        ans+=count_set_bits(x);
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
    // cout<<"n:"<<n<<endl;
    int m;
    cin>>m;
    //   cout<<"m:"<<m<<endl;
    vector<vector<int>>arr(m,vector<int>(2,0));
    for(int i=0;i<m;i++)
    {
        int lr;


        int ur;
        cin>>lr>>ur;

        arr[i][0]=lr;
        arr[i][1]=ur;

    }
  
    
    int ans=solve(n,m,arr);
    cout<<"ans:"<<ans<<endl;
    return 0;
}

/*
Input1:
10 
2
5 5  
9 10 


Output:
ans:2


Input2:
5
1
1 2

Output:
ans:2



*/