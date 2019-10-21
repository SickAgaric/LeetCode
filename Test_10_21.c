class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
         
	    int i = 0;
		int j = 0;
	
	
	    stack<int> s;
		
		while(i<pushV.size())
		{
		   s.push(pushV[i]);
		   
		   while(!s.empty() && s.top()==popV[j])
			{
				s.pop();
				j++;
			}
            
		   i++;
		    
		
		}
        return s.empty();
    }
};