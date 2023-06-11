#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-3; i++){
        if(i==0 || arr[i] != arr[i-1]){
            for(int j=i+1; j<n-2; j++){
                if(j==i+1 || arr[j] != arr[j-1]){
                    int left = j+1, right = n-1;
                    int search = target - (arr[i] + arr[j]);
                    while(left<right){
                        if(arr[left]+arr[right] == search){                          
                            return "Yes";
                        }
                        else if(arr[left]+arr[right] > search) {
                            while(left<right && arr[right] == arr[right-1]) right--;
                            right--;
                        }
                        else{
                            while(left<right && arr[left] == arr[left+1]) left++;
                            left++;
                        } 
                    }
                }
            }
        }
    }
    return "No";
}
