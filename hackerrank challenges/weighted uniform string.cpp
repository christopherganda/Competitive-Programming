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
    string word;
    int cnt[26];
    memset(cnt,0,sizeof cnt);
    cin>>word;
    int n;
    cin>>n;
    int length = word.size();
    int siz = 1;
    for(int i = 1;i<length;i++){
        if(word[i]!= word[i-1]){
            cnt[word[i-1]-'a'] = max(cnt[word[i-1]-'a'],siz);
            siz = 1;
        }else siz++;
    }
    cnt[word[length-1]-'a'] = max(cnt[word[length-1]-'a'],siz);
    while(n--){
        int tc;
        cin>>tc;
        bool cek = false;
        for(int i =0;i<26;i++){
            if(tc%(i+1)==0 && tc/(i+1)<= cnt[i]){
                cout<<"Yes"<<endl;
                cek=1;
                break;
            }
        }
        if(!cek)cout<<"No"<<endl;
    }
}
