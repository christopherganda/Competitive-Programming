#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int maxx = arr[0];
    int minn = arr[0];
    int hasil = 0;
    for(int i = 1;i<n;i++){
        if((arr[i]>maxx && arr[i]>minn)||(arr[i]<maxx && arr[i]<minn)){
//            cout<<arr[i]<<" "<<maxx<<" "<<minn<<endl;
            hasil++;
        }
        if(maxx<arr[i])maxx=arr[i];
        if(minn>arr[i])minn=arr[i];
    }
    cout<<hasil<<endl;
}
