int knapsackDP(int wt[],int price[],int N,int W)
{
    int dp[100][100] = {0};

    for(int n = 0; n <= N; n++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(n == 0 || w == 0)
                dp[n][w] = 0;
            else
            {
                int inc = 0, exc = 0;
                if(wt[n-1] <= w)             
                    inc = price[n-1] + dp[n-1][w - wt[n-1]];                
                exc = dp[n-1][w];

                dp[n][w] = max(inc, exc);
            }
        }
    }
    return dp[N][W];
}
