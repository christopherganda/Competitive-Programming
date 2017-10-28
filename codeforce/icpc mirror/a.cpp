#include <bits/stdc++.h>
using namespace std;

int main(){
    bool cek[30];
    bool used[30];
    memset(used,0,sizeof used);
    memset(cek,0,sizeof cek);
    int n,m;
    cin>>n;
    string txt;
    cin>>txt;
    for(int i = 0;i<n;i++){
//        cout<<(int)txt[i]-'a';
        if(txt[i]!='*')cek[(int)txt[i]-'a']=1,used[(int)txt[i]-'a']=1;
    }
    cin>>m;
    string arr[m+5];
    int cnt=0;
    for(int i = 0;i<m;i++)cin>>arr[i];
    for(int i = 0;i<n;i++){
        if(txt[i]=='*'){
            for(int j = 0;j<m;j++){
                string wrd = arr[j];
                if(cek[(int)wrd[i]-'a'] && !used[(int)wrd[i]-'a']){
//                    cout<<wrd[i]<<endl;
                    cnt++;
                    used[(int)wrd[i]-'a']=1;
                }else cek[(int)wrd[i]-'a']=1;
            }
        }
    }
    cout<<cnt;
}
