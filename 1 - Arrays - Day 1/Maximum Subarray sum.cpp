long long maxSubarraySum(int arr[], int n)
{
    long long cur = 0;
    long long max_so_far = 0;
    for(int i=0; i<n; i++){
        cur += arr[i];
        max_so_far = max(cur,max_so_far);
        if(cur < 0) cur = 0;
    }
    max_so_far = max(cur,max_so_far);
    return max_so_far;
}