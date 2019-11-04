class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {{}};
        vector<vector<int> > res(n,vector<int>(n,0));
        int down=0,up=n-1,left=0,right=n-1;
        int itm=1;
        while(left<=right && down<=up){
            for(int i=left;i<=right;i++) res[down][i]=itm++;
            for(int i=down+1;i<=up;i++) res[i][right]=itm++;
            for(int i=right-1;i>=left;i--) res[up][i]=itm++;
            for(int i=up-1;i>=down+1;i--) res[i][left]=itm++;
            down++;
            up--;
            left++;
            right--;
        }
        return res;
    }
};

class Solution {
    public String convert(String s, int numRows) {

        if(numRows == 1) return s;
        int[] rowIdx = new int[numRows];
        char[] chars = new char[s.length()];
        int n = 0;
        int burketSize = numRows * 2 - 2;
        int burketNum = chars.length / burketSize; 
        int rem = chars.length % burketSize;
        for(int i = 1; i < numRows; i ++){
        	int flag = i == 1 ? 1 : 2;
        	n = flag * burketNum + (rem >= i ? ( 1 + (burketSize - rem + 1 < i ? 1 : 0)) : 0);
        	rowIdx[i] = rowIdx[i-1] + n;
        }
        int flag = -1;
        int curRow = 0;
        for(char c : s.toCharArray()){
        	chars[rowIdx[curRow]] = c;
        	rowIdx[curRow] = rowIdx[curRow] + 1;
        	 if (curRow == 0 || curRow == numRows - 1) flag = -flag;
             curRow += flag;
        }
        return new String(chars);
    }
}
