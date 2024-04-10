class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int j=g.size()-1;
        int i=s.size()-1;
        while(i>=0 &&  j>=0)
        {
            if((j>=0 && i>=0) && (s[i]>=g[j])) 
            {
                cnt++;
                j--;
                i--;
            }
            else 
            {
                j--;
            }
            
            
        }
        
        return cnt;
    }
};