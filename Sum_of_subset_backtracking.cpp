#include <bits/stdc++.h>
using namespace std;
void print_sum(int i, int n, vector<int>&arr, int tar_s, vector<int>&ss)
{
    // cout<<i<<" "<<n<<" "<<tar_s<<" "<<ss.size()<<endl;
    if(tar_s==0)
    {
        for(int j=0; j<ss.size(); ++j)
        {
            cout<<ss[j]<<" ";
        }
        cout<<endl;
        return;
    }
    if(i==n) return;
    print_sum(i+1,n,arr,tar_s,ss);
    if(arr[i]<=tar_s)
    {
        ss.push_back(arr[i]);
        print_sum(i+1,n,arr,tar_s-arr[i],ss);
        ss.pop_back();
    }
}
int main()
{
    int n; 
    cin>>n;
    vector<int>arr(n);
    for(auto &it:arr) cin>>it;
    vector<int>ss;
    int sum;
    cin>>sum;
    print_sum(0,n,arr,sum,ss);
    return 0;
}