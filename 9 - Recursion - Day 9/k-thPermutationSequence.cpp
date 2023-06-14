// Easy Way
#include <bits/stdc++.h> 

string kthPermutation(int n, int k) {
    // Write your code here.
    int no = 0;
    for(int i=1; i<=n; i++){
        no = no*10 + i;
    }
    string ans = to_string(no);
    while(--k) next_permutation(ans.begin(), ans.end());

    return ans;
}


//Hard Way
#include <bits/stdc++.h> 

string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> no;
    int fact = 1;
    for(int i=1; i<n; i++){
        no.push_back(i);
        fact = fact*i;
    }
    no.push_back(n);
    k = k-1;
    string ans = "";
    while(true){
        ans += to_string(no[k/fact]);
        no.erase(no.begin() + k/fact);
        if(no.size() == 0) break;
        k=k%fact;
        fact = fact/no.size();
    }

    return ans;
}
