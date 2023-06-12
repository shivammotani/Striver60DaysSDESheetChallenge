int calculateMinPatforms(int at[], int dt[], int n) {

    sort(at, at+n);
    sort(dt, dt+n);

    int cur_pltfrm = 1, ans = 1;
    int i=1, j=0;

    while(i<n && j<n){
        if(at[i] <= dt[j]){
            cur_pltfrm++;
            i++;
        }
        else if (at[i] > dt[j]){
            cur_pltfrm--;
            j++;
        }
        ans = max(ans, cur_pltfrm);
    }
    return ans;
}