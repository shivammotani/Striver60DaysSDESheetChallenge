vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int el1 =0, el2=0, cnt1=0, cnt2=0;
    for(int i=0; i<arr.size(); i++){
        if(cnt1 == 0 && arr[i] != el2){
            cnt1++;
            el1 = arr[i];
        } 
        else if(cnt2 == 0 && arr[i] != el1){
            cnt2++;
            el2 = arr[i];
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        } 
    }
    vector<int> ans;
    cnt1=0, cnt2=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
    }
    if(cnt1 > arr.size()/3) ans.push_back(el1);
    if(cnt2 > arr.size()/3) ans.push_back(el2);
    return ans;

}