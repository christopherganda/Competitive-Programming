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
    int tc;
    cin>>tc;
    while(tc--){
        string txt;
        cin>>txt;
        int cnt = 0;
        for(int i = 0;i<txt.size();i++){
            if(cnt==0 &&txt[i]=='h')cnt++;
            else if((cnt == 1 || cnt == 7) && txt[i]=='a')cnt++;
            else if((cnt == 2 && txt[i]=='c'))cnt++;
            else if((cnt == 3 || cnt == 9) && txt[i]=='k')cnt++;
            else if((cnt == 4 && txt[i]=='e'))cnt++;
            else if(cnt==8 &&txt[i]=='n')cnt++;
            else if((cnt == 5 || cnt == 6) && txt[i]=='r')cnt++;

        }
        if(cnt==10)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
