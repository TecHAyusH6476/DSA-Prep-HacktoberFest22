/* Author: G Pala Venki Reddy */
/* Algorithm: Dijkstra's Algorithm */

/* Problem Description */

/*
    There are n cities and m flight connections between them. 
    Your task is to determine the length of the shortest route from Syrjälä to every city.
*/

/*

    Input:
    The first input line has two integers n and m: the number of cities and flight connections. 
    The cities are numbered 1,2,…,n, and city 1 is Syrjälä.

    After that, there are m lines describing the flight connections. 
    Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. 
    Each flight is a one-way flight.

    You can assume that it is possible to travel from Syrjälä to all other cities.

    Output:
    Print n integers: the shortest route lengths from Syrjälä to cities 1,2,…,n.

    Constraints:
    1 ≤ n≤ 105 
    1 ≤ m ≤ 2⋅105
    1 ≤ a,b ≤ n
    1 ≤ c ≤109

*/

/*
    Example test Case:

    Input:
    3 4
    1 2 6
    1 3 2
    3 2 3
    1 3 4

    Output:
    0 5 2

    Explanation:
    The shortest route from Syrjälä to city 1 is 0, which has length 0.
    The shortest route from Syrjälä to city 2 is 0→3→2, which has length 2+3=5.
    The shortest route from Syrjälä to city 3 is 0→3, which has length 2.

*/

/*-------------------- Solution ----------------------*/

#include <bits/stdc++.h>
 
using namespace std;
#define vi vector<int>
#define lli long long int
#define MAX 1e15
 
int main() 
{
    int n, m;
    cin >> n >> m;
    unordered_map<lli, vector<pair<int, int>>> adj;
    lli u, v, w;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
 
    /* we will use dijkstra's algorithm to find shortest distance between the start node and all other nodes */
    vector<lli> d(n+1, MAX);
    /* mark the start node distance as 0 */
    d[1] = 0;
    set<pair<lli, lli>> s;
    s.insert(make_pair(0, 1));
    while(!s.empty())
    {
        /* get the node which is having smallest distance */
        lli p = s.begin()->second;
        /* erase that pair from that set , as it was processed */
        s.erase(s.begin());
 
        /* now traverse through all the edges reached from curr node */
        for(auto e: adj[p])
        {
            if(d[e.first] > d[p] + e.second)
            {
                s.erase(make_pair(d[e.first], e.first));
                d[e.first] = d[p] + e.second;
                s.insert(make_pair(d[e.first], e.first));
            }
        }
    }
 
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
	return 0;
}