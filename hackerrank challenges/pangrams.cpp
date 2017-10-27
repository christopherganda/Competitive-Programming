#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#define freinput "input.txt","r",stdin
#define freoutput "output.txt","w",stdout
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
typedef long long ll;
typedef unsigned long int uld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
struct comp {
       bool operator() (int a,int b) {
            return a>b;
       }
};

int main(){
//    #ifdef chris
//    freopen(freinput);
//    freopen(freoutput);
//    #endif // chris
//    ios::sync_with_stdio(false);
    string txt;
    bool arr[26];
    memset(arr,0,sizeof(arr));
    getline(cin,txt);
    for(int i = 0;i<txt.size();i++){
        if(txt[i]!=' ')arr[tolower(txt[i])-'a']=1;
    }
    for(int i = 0;i<26;i++){
        if(!arr[i]){
            cout<< "not pangram\n";
            return 0;
        }
    }
    cout<< "pangram\n";
}
