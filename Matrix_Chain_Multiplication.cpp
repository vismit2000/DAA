#include <bits/stdc++.h>
using namespace std;
int tdp[100][100];

int MatrixChain(int m[], int i, int j)
{
    //Base case
    if(i==j)
        return 0;
        
    //Overlapping subproblem
    if(tdp[i][j] != -1)
        return tdp[i][j];
    
    int ans = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int temp = MatrixChain(m, i, k) + MatrixChain(m, k+1, j) + m[i-1]*m[k]*m[j];
        ans = min(ans, temp);
    }
    tdp[i][j] = ans;
    return ans;
}

int main() 
{
    int matrices[] = {1, 2, 3, 4};
    int n = sizeof(matrices)/sizeof(int);
    memset(tdp, -1, sizeof(tdp));
    cout << MatrixChain(matrices, 1, n-1) << endl;
}
