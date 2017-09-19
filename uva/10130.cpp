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
int memo[1005][35];
int ks(int v[],int w[],int weight,int n){
    if(n==-1|| weight==0)return 0;
    if(memo[n][weight] !=-1)return memo[n][weight];
    if(w[n]>weight)return memo[n][weight] = ks(v,w,weight,n-1);
    if(w[n]<=weight)return memo[n][weight] = max(ks(v,w,weight,n-1),v[n]+ks(v,w,weight-w[n],n-1));
}
int main(){
//    #ifdef chris
//    freopen(freinput);
//    freopen(freoutput);
//    #endif // chris
    int tc;
    cin>>tc;
    for(int i = 0;i<tc;i++){
        int nItem;
        cin>>nItem;
        memset(memo, -1, sizeof memo);
        int v[nItem+5],w[nItem+5];
        for(int j = 0;j<nItem;j++){
            cin>>v[j]>>w[j];
        }
        int nPerson;
        cin>>nPerson;
        int maxW[nPerson+5];
        int total = 0;
        for(int j = 0;j<nPerson;j++){
            cin>>maxW[j];
            total+= ks(v,w,maxW[j],nItem-1);

        }
        cout<<total<<endl;
    }
}
