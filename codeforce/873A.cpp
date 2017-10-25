#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> arr;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    int sum = 0;
    for(int i = 0;i<n-k;i++){
        sum+= arr[i];
    }
    cout<<sum+(k*x)<<endl;
}
