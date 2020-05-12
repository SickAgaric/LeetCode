class MinStack {
public:
    /** initialize your data structure here. */

    stack<int> stack1,stack2;

    MinStack() {
       
    }
    



    void push(int x) {
        if(stack2.empty())
        {
            stack2.push(x);
        }
        else if(stack2.top() >= x)//注意这块的判断
            stack2.push(x);
        stack1.push(x);
    }
    
    void pop() {
        if(stack1.top() == stack2.top())
            stack2.pop();
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};


class Solution {
public:
	string compressString(string S) {
		int pre = 0, next = 0;

		string newS;
		while (pre < S.size())
		{
			int count = 0;
			while (S[pre] == S[next])
			{
				next++;
				count++;
			}
			newS.push_back(S[pre]);

            if(count>=10)
            {
                int num = count;
                vector<int> v;
                while(num)
                {
                    v.push_back((num%10));
                    num /= 10;
                }

                for(int i = v.size()-1;i>=0;--i)
                {
                    newS.push_back((v[i] + '0'));
                }
                v.clear();
            }
            else{
                newS.push_back((count+'0'));
            }
			pre = next;
		}

        if(newS.size() >= S.size())
            return S;
		return newS;
	}
	
};

