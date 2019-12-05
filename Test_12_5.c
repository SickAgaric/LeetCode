class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        /*vector<int> v;
        if(input.empty() || k > input.size())
            return v;
        
        sort(input.begin(),input.end());
        
        
        
        for(int i = 0;i < k;++i)
            v.push_back(input[i]);
        return v;*/
         vector<int> v;
        if(input.empty() || k > input.size())
            return v;
        
        priority_queue<int, vector<int>, greater<int>> q1(input.begin(), input.end());
        
        
        for(int i = 0;i < k;i++)
        {
            
            v.push_back(q1.top());
            q1.pop();
        }
        
        return v;
        
    }
};