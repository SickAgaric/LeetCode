class Solution {
public:
    	bool validMountainArray(vector<int>& A) {
		if (A.size() < 3)
			return false;

		int max = A[0];
		int index = 0;
		for (int i = 1; i < A.size(); ++i)
		{
			if (A[i] > max)
			{
				index = i;
				max = A[i];
			}
		}
//------------------------------------------判断临界条件，升序或者降序
        if(index == 0)
            return false;

		if (index == (A.size() - 1))
			return false;


		for (int i = 0; i < index - 1; ++i)
		{
			if (A[i] >= A[i + 1])
				return false;
		}

		for (int i = index; i < A.size() - 1; ++i)
		{
			if (A[i] <= A[i + 1])
				return false;
		}

		return true;
	}
};
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        sort(nums.begin(),nums.end());

        int i = 0;
        int min = 0;

        for(int i = 0;i<nums.size();i+=2)
            min += nums[i];

        return min;
    }
};
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max = candies[0];
		vector<bool> res;

        
        if(candies.size() == 1)
        {
            res.push_back(true);
            return res;
        }

		for (int i = 1; i < candies.size(); ++i)
		{
			if (candies[i] > max)
				max = candies[i];
		}

		for (int i = 0; i < candies.size(); ++i)
		{
			if ((candies[i] + extraCandies) >= max)
				res.push_back(true);
			else
				res.push_back(false);
		}

		return res;
	}
};

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        for(int i = 0;i < target.size();++i)
        {
            if(target[i] != arr[i])
                return false;
        }

        return true;
    }
};


class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int number = k * threshold;

        int sum = 0,count = 0;
        for(int i = 0;i < arr.size(); ++i)
        {
            sum += arr[i];
            if(i + 1 >= k)
            {
                if(i - k >= 0)
                    sum -= arr[i - k];
                if(sum >= number)
                    count++;
            }
        }
        return count;
    }
};


class Solution {
public:
    string tictactoe(vector<string>& board) {
		int time = board.size();
		int space = 0;
		int sumX = 0, sumO = 0;
		for (int i = 0; i < time; ++i)
		{
			sumX = 0, sumO = 0;
			for (int row = 0; row < board.size(); ++row)
			{
				if (board[row][i] == 'X')
					sumX++;
				if (board[row][i] == ' ')
					space++;
			}
			if (sumX == board.size())
				return "X";


			for (int col = 0; col < board.size(); ++col)
			{
				if (board[col][i] == 'O')
					sumX++;
				if (board[col][i] == ' ')
					space++;
			}
			if (sumX == board.size())
				return "O";
		}

		for (int i = 0; i < time; ++i)
		{
			sumX = 0, sumO = 0;
			for (int row = 0; row < board.size(); ++row)
			{
				if (board[i][row] == 'X')
					sumX++;
				if (board[i][row] == ' ')
					space++;
			}
			if (sumX == board.size())
				return "X";


			for (int col = 0; col < board.size(); ++col)
			{
				if (board[i][col] == 'O')
					sumO++;
				if (board[i][col] == ' ')
					space++;
			}
			if (sumO == board.size())
				return "O";
		}
		int n = 2;
		sumX = 0, sumO = 0;

		//判断右斜
		for (int rowBegin = 0; rowBegin < board.size(); rowBegin++)
		{
			if (board[rowBegin][rowBegin] == 'X')
				sumX++;
		}
		if (sumX == board.size())
			return "X";

		for (int colBegin = 0; colBegin < board.size(); colBegin++)
		{
			if (board[colBegin][colBegin] == 'O')
				sumO++;
		}
		if (sumO == board.size())
			return "O";
		//判断左斜
		/*for (int rowBegin = board.size() - 1; rowBegin >= 0; rowBegin--)
		{
			if (board[rowBegin][rowBegin] == 'X')
				sumX++;
		}
		if (sumX == board.size())
			return "X";

		for (int colBegin = board.size() - 1; colBegin >= 0; colBegin--)
		{
			if (board[colBegin][colBegin] == 'O')
				sumO++;
		}
		if (sumO == board.size())
			return "O"*/;
		sumX = 0, sumO = 0;
		for (int row = 0, col = board.size() - 1; row < board.size(); row++, col--)
		{
			if (board[row][col] == 'X')
				sumX++;
		}
		if (sumX == board.size())
			return "X";

		for (int row = 0, col = board.size() - 1; row < board.size(); row++, col--)
		{
			if (board[row][col] == 'O')
				sumO++;
		}
		if (sumX == board.size())
			return "O";


		if (space == 0)
			return "Draw";
		else
			return "Pending";
	}
};
class Solution {
public:
    string tictactoe(vector<string>& board) {
        //检查行
        int sumX = 0,sumO = 0,sumSp;
        int len = board.size();
        for(int row = 0;row < board.size(); ++row)
        {
            sumX = 0,sumO = 0;
            for(int col = 0;col < len;++col)
            {
                if(board[row][col] == 'X')
                    sumX++;
                else if(board[row][col] == 'O')
                    sumO++;
                else if(board[row][col] == ' ')
                    sumSp++;
            }

            if(sumX == board.size())
                return "X";
            if(sumO == board.size())
                return "O";
        }
        //检查列
        for(int col = 0;col < board.size();++col)
        {
            sumX = 0,sumO = 0;
            for(int row = 0;row < len;++row)
            {
                if(board[row][col] == 'X')
                    sumX++;
                if(board[row][col] == 'O')
                    sumO++;
            }

            if(sumX == board.size())
                return "X";
            if(sumO == board.size())
                return "O";
        }
        //检查左起点
        sumX = 0,sumO = 0;
        for(int row = 0,col = 0;row < len; ++row,++col)
        {
            if(board[row][col] == 'X')
                sumX++;
            if(board[row][col] == 'O')
                sumO++;
        }
        if(sumX == board.size())
                return "X";
        if(sumO == board.size())
            return "O";

        sumX = 0,sumO = 0;
        //检查右起点
        for(int row = 0,col = len-1;row < len; ++row,--col)
        {
            if(board[row][col] == 'X')
                sumX++;
            if(board[row][col] == 'O')
                sumO++;
        }
        if(sumX == board.size())
                return "X";
        if(sumO == board.size())
            return "O";
        
        if(sumSp == 0)
            return "Draw";
        else
            return  "Pending";
    }
};

