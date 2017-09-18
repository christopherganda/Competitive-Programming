#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string kata;
        cin>>kata;
        if(kata.size()>10)cout<<kata[0]<<kata.size()-2<<kata[kata.size()-1]<<endl;
        else cout<<kata<<endl;
    }
}
