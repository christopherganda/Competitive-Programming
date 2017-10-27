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
        string word;
        cin>>word;
        bool cek=true;
        int length = word.size();
        for(int i = 0;i<(length%2==0?length/2:length/2+1);i++){
            int a,b,c,d;
            a = word[i]-'a';
            b = word[i+1]-'a';
            c = word[length-i-1]-'a';
            d = word[length-i-2]-'a';
            if(abs(a-b)!=abs(c-d)){
                cek=false;break;
            }
        }
        if(cek)cout<<"Funny"<<endl;
        else cout<<"Not Funny"<<endl;
    }

}
