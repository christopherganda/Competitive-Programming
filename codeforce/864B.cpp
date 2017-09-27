#include <bits/stdc++.h>
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
int main(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    string txt;cin>>txt;
    int a=0,b=0;
    bool check[30];
    memset(check,0,sizeof(check));
    for(int i = 0;i<n;i++){
        if(txt[i]>='a' && txt[i]<='z' && !check[txt[i]-97]){
            check[txt[i]-97]=1;
            b++;
        }else if(txt[i]<'a' || txt[i]>'z'){
            b=0;
            memset(check,0,sizeof(check));
        }
        a=max(b,a);
    }
    cout<<a<<endl;
}
