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
    cin>>word;
    int length = word.size();
    int cnt[26];
    memset(cnt,0,sizeof cnt);
    for(int i = 0;i<length;i++){
        cnt[word[i]-'a']++;
    }
    sort(cnt,cnt+26,comp());
    int tot=0,same=0,nSame=0,diff=0;
    bool cek =0;
    map<int,int> val;
    for(int i = 1;i<26;i++){
        if(cnt[i]==0)break;
        else if(cnt[i]!= cnt[i-1])tot++,cek=1,diff=max(diff,cnt[i-1]-cnt[i]);
        else if(cek && cnt[i]==cnt[i-1])nSame++;
        else if(cnt[i]==cnt[i-1])same++;
    }
    if(tot>1)cout<<"NO"<<endl;
    else {
        if((nSame==0 && same>=0) || (same==0 && nSame>=0) &&diff<=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
