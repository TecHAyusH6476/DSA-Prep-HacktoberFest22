#include <bits/stdc++.h>
using namespace std;

// Using BST
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        int x1 = KnightPos[0];
        int y1 = KnightPos[1];
        int x2 = TargetPos[0];
        int y2 = TargetPos[1];

        int chess[1001][1001];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                chess[i][j] = 0;
            }
        }

        if (x1 == x2 && y1 == y2)
            return 0;

        queue<pair<int, int>> q;
        q.push(make_pair(x1 - 1, y1 - 1));

        while (!q.empty())
        {
            auto curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();

            // (x+1, y+2)
            if ((i - 2) >= 0 && (i - 2) < n && (j - 1) >= 0 && (j - 1) < n && chess[i - 2][j - 1] == 0)
            {
                chess[i - 2][j - 1] = chess[i][j] + 1;
                q.push(make_pair(i - 2, j - 1));
            }

            if ((i - 2) >= 0 && (i - 2) < n && (j + 1) >= 0 && (j + 1) < n && chess[i - 2][j + 1] == 0)
            {
                chess[i - 2][j + 1] = chess[i][j] + 1;
                q.push(make_pair(i - 2, j + 1));
            }

            if ((i - 1) >= 0 && (i - 1) < n && (j - 2) >= 0 && (j - 2) < n && chess[i - 1][j - 2] == 0)
            {
                chess[i - 1][j - 2] = chess[i][j] + 1;
                q.push(make_pair(i - 1, j - 2));
            }

            if ((i - 1) >= 0 && (i - 1) < n && (j + 2) >= 0 && (j + 2) < n && chess[i - 1][j + 2] == 0)
            {
                chess[i - 1][j + 2] = chess[i][j] + 1;
                q.push(make_pair(i - 1, j + 2));
            }

            if ((i + 2) >= 0 && (i + 2) < n && (j - 1) >= 0 && (j - 1) < n && chess[i + 2][j - 1] == 0)
            {
                chess[i + 2][j - 1] = chess[i][j] + 1;
                q.push(make_pair(i + 2, j - 1));
            }

            if ((i + 2) >= 0 && (i + 2) < n && (j + 1) >= 0 && (j + 1) < n && chess[i + 2][j + 1] == 0)
            {
                chess[i + 2][j + 1] = chess[i][j] + 1;
                q.push(make_pair(i + 2, j + 1));
            }

            if ((i + 1) >= 0 && (i + 1) < n && (j - 2) >= 0 && (j - 2) < n && chess[i + 1][j - 2] == 0)
            {
                chess[i + 1][j - 2] = chess[i][j] + 1;
                q.push(make_pair(i + 1, j - 2));
            }

            if ((i + 1) >= 0 && (i + 1) < n && (j + 2) >= 0 && (j + 2) < n && chess[i + 1][j + 2] == 0)
            {
                chess[i + 1][j + 2] = chess[i][j] + 1;
                q.push(make_pair(i + 1, j + 2));
            }
        }
        return chess[x2 - 1][y2 - 1];
    }
};
