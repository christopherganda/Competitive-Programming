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
    int length,sum;
    string txt;
    cin>>length>>txt>>sum;
    for(int i = 0;i<length;i++){
        if(txt[i]>='a'&&txt[i]<='z')cout<<(char)('a'+(txt[i]+sum%26)%'a'%26);
        else if(txt[i]>='A'&&txt[i]<='Z')cout<<(char)('A'+(txt[i]+sum%26)%'A'%26);
        else cout<<txt[i];
    }
    cout<<endl;
}
