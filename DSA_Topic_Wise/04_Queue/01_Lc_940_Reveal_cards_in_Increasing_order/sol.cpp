class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        for(int i=0;i<deck.size();i++) q.push(i);
         int n=deck.size();
        vector<int>res(n);
        sort(deck.begin(),deck.end());
       
        for(int i=0;i<n;i++)
        {
            int ind=q.front();
            q.pop();
            res[ind]=deck[i];
            
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        return res;
    }
};