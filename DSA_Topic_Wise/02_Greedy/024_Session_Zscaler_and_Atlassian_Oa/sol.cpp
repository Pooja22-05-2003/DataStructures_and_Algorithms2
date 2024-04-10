class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>len;
        for(auto it : words)
        {
            len.push_back(it.size());
        }
        
        sort(len.begin(),len.end());
        
        vector<int>freq(26);
        
        for(int i=0;i<words.size();i++)
        {
            string curr=words[i];
            for(int j=0;j<curr.size();j++)
            {
                freq[(curr[j]-'a')]++;
            }
        }
        
        int even=0;
        int odd=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]%2==0)
            {
                even+=freq[i]/2;
            }
            else odd+=freq[i];
        }
        
        
        int res=0;
       for(auto it : len)
       {
           int req_even=it/2;
           int req_odd=0;
           if(it%2!=0)
           {
               req_odd=1;
           }
           
           // if the even we have is less than even_req, we will never able to achieve that
           if(req_even>even) break;
           even-=req_even;
           
           if(req_odd>odd)
           {
               even--;
               odd+=2;
               
           }
           
           odd-=req_odd;
           res++;
       }
        
        return res;
    }
};