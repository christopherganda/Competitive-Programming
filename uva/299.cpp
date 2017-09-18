#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    for(int i = 0;i<tc;i++){
        int n;
        cin>>n;
        int arr[n+5];
        for(int j = 0;j<n;j++){
            cin>>arr[j];
        }
        int hasil = 0;
        for(int j = 0;j<n-1;j++){
            for(int k = j+1;k<n;k++){
                if(arr[j]>arr[k]){
                    arr[j] = arr[j]+arr[k];
                    arr[k] = arr[j]-arr[k];
                    arr[j] = arr[j]-arr[k];
                    hasil++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<hasil<<" swaps."<<endl;
    }
}
