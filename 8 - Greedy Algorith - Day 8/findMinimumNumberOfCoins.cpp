#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int ans = 0,i=0;
    int demo[9]  = {1000,500,100,50,20,10,5,2,1};
    while(amount > 0 && i<9){
        if(demo[i] > amount) i++;
        else{
            // cout << amount << "-" << demo[i] << endl;
            ans++;
            amount = amount-demo[i];
        }
    }
    return ans;
}
