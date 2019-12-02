class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        if(n==0 || gifts.size() < n)
            return 0;
        
        sort(gifts.begin(),gifts.end());
        
        int count = 0;
        for(int i = 0;i < gifts.size();i++)
        {
            if(gifts[i] == gifts[n/2])
                count++;
        }
        if(count < n/2)
            return 0;
        return gifts[n/2];
    }
};