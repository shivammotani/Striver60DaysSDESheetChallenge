long long cnt = 0;
void merge(long long *arr, int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right <= high){
        if(arr[left] <= arr[right])
        temp.push_back(arr[left++]);
        else {
          temp.push_back(arr[right++]);
          cnt += (mid - left + 1);
        }
    }

    while(left<=mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i=low; i<=high; i++) arr[i] = temp[i-low];
}


void mergeSort(long long *arr, int left, int right){
    if(left < right){
        int mid = (left+right) >> 1;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }

}


long long getInversions(long long *arr, int n){
    // Write your code here.
    mergeSort(arr,0, n-1);
    return cnt;
}