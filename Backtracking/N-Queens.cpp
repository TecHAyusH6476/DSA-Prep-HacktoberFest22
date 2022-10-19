/*
https://leetcode.com/problems/n-queens/description/
51. N-Queens
Leetcode Hard
*/
class Solution {

    bool isPossible(vector<string>& partialAns, int row, int col, int n) {


        int len = partialAns.size();

        for(int i = 0;i<len;i++) {

            if(partialAns[i][col] == 'Q') return 0;

        }

        int i=row-1, j = col + 1;

        while(i>=0 and j<n) {

            if(partialAns[i][j]=='Q') return 0;

            i--;j++;

        }

        i=row - 1, j = col -1;

        while(i>=0 and j>=0) {

            if(partialAns[i][j]=='Q') return 0;

            i--;j--;

        }

        

        return 1;

    }

    void helper(vector<vector<string>>& ans, int n, int row, vector<string>& partialAns) {

        

        if(row >= n) {

            ans.push_back(partialAns);

            return;

        }

        string s = "";

        for(int col=0;col < n;col++) {

            if(isPossible(partialAns,row,col,n)) {

                string temp = s;

                temp+='Q';

                int i = col;

                while(i<n-1){

                    temp+='.';

                    i++;

				}
                partialAns.push_back(temp);

                helper(ans,n,row+1,partialAns);

                partialAns.pop_back();

            }

            s+=".";

        }

    }

public:

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> partialAns;

        helper(ans,n,0,partialAns);

        return ans;

    }

};
