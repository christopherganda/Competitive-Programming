#include <bits/stdc++.h>
using namespace std;
vector<string> arr;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string word;
        cin>>word;
        if(find(arr.begin(),arr.end(),word) !=arr.end())cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
            arr.push_back(word);
        }

    }
}
