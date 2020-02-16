// Kadane Algorithm - O(n)

int MaxSubarraySum(vector <int> array)
{
    int n = array.size();

    int best = 0, sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    
    return best;
}
