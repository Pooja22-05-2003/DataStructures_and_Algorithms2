class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        int x=tickets[k];
        for(int i=0;i<tickets.size();i++)
        {
            if(i==k) 
            {
                ans+=x;
                continue;
            }
            else if(tickets[i]>=x)
            {
                if(i>k) ans+=tickets[k]-1; // after wale ko last wala ticket buy krne ka chance nhi milega, usse pehle hi tickets[k]=0 ho jayega.
                else ans+=tickets[k];
            }
            else if(tickets[i]<x) 
            {
               ans+=tickets[i];
            }
        }
        
        return ans;
    }
};