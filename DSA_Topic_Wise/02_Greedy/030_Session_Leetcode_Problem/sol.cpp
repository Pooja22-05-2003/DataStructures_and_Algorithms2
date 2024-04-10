// TC=O(n)
// SC=O(n)
class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        
        int cnt=1;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=1;
            }
            else
            {
                // found that string,
                cnt++;
                mp.clear();
                mp[s[i]]=1;
            }
        }
        
        return cnt;
    }
};