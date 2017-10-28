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
vector<int>arr[205];
int color[205];
int n;
bool isBipartite = true;
void dfs(int i,int c){
    color[i]=c;
    if(isBipartite){
        for(int j = 0;j<arr[i].size();j++){
            if(color[arr[i][j]]==-1){
                dfs(arr[i][j],c ^ 1);
            }else if(color[arr[i][j]]==c)isBipartite=false;
        }
    }

}
int main(){
#ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
    while(true){
        int a;
        cin>>n;
        if(n==0)break;
        isBipartite=true;
        cin>>a;
        for(int i = 0;i<n;i++){
            arr[i].clear();
        }
        memset(color,-1,sizeof(color));
        for(int i = 0;i<a;i++){
            int k,l;
            cin>>k>>l;
            arr[k].push_back(l);
        }

        dfs(0,0);
        if(!isBipartite)cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;
    }
}
