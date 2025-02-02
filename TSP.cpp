#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int n = 4;

int dist[10][10] = {
                    {0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10},
                    {25,34,10,0}
                   };

int VISITED_ALL = (1 << n) - 1;

int dp[16][4];

int  tsp(int mask,int pos)
{
	if (mask == VISITED_ALL)
		return dist[pos][0];

	if (dp[mask][pos] != -1)
	   return dp[mask][pos];

	//From current node, visit all the unvisited cities and take the best route
	
    int ans = INF;

	for(int city = 0; city < n; city++)
    {
		if((mask & (1 << city)) == 0)
        {
			int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, newAns);
		}

	}
	return dp[mask][pos] = ans;
} 

int main()
{
    memset(dp, -1, sizeof(dp));
	cout << "Travelling Saleman Distance is :" << tsp(1, 0);
    return 0;
}
