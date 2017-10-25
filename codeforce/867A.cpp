#include <bits/stdc++.h>
using namespace std;
int main(){
    int seatle = 0,sf = 0,n;
    cin>>n;
    string word;
    cin>> word;
    for(int i = 1;i<word.size();i++){
        if(word[i]!=word[i-1]){
            if(word[i-1]=='S')seatle++;
            else sf++;
        }

    }
    if(seatle>sf)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
