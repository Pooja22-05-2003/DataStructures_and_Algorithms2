#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int ans=target[0]-'0'; // we are starting string with all zero, so if the traget 0 index string is 1, then add 1 in ans,
        for (int i=0;i<target.size()-1;i++) ans+=(target[i]!=target[i+1]); // i=0 is checkig for next index, similary n-2 index will store the ans for index n-1
        return ans;
    }
};

int main() {
	string s;cin>>s;
	Solution ans;
	cout<<ans.minFlips(s);
	return 0;
}

/*
Input1:
0110101

Output:
5



Input2:
01011

Output:
3



Input3:
1011011101 // here 6 state changes are there but ans is 7 because the first index el also we need to change from 0 to 1.

Output:
7


*/