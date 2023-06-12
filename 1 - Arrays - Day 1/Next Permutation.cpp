vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int breakpoint = -1;
    for(int i=n-2; i>=0; i--){
        if(permutation[i]<permutation[i+1]){
            breakpoint = i;
            break;
        }
    }
    if(breakpoint != -1){
        for(int i=n-1; i>=0; i--){
            if(permutation[breakpoint]<permutation[i]){
                swap(permutation[i], permutation[breakpoint]);
                break;
            }
        }
    }
    reverse(permutation.begin()+breakpoint+1, permutation.end());
    return permutation;
}
