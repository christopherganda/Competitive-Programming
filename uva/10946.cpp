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

int x,y;
char arr[57][57];
bool visited[57][57];
char varG='#';
int cnt=0;
void dfs(int i,int j){
    if(i<0 || i>=x || j<0 || j>=y)return;
    if(visited[i][j])return;
    if(arr[i][j]!='.'&& varG!='#' && arr[i][j]!=varG)return;
    visited[i][j]=1;
    if(arr[i][j]=='.')return;
    if(arr[i][j]!='.' && varG=='#')varG=arr[i][j];
    if(arr[i][j]==varG)cnt++;
    dfs(i,j+1);
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
}
int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
//    ios::sync_with_stdio(false);
    int tc = 0;
    while(scanf("%d %d",&x,&y),(x||y)){
        tc++;
        for(int i = 0;i<x;i++){
            for(int j = 0;j<y;j++){
                cin>>arr[i][j];
                visited[i][j]=0;
            }
        }
        vector<pair<char,int> > v;
        for(int i = 0;i<x;i++){
            for(int j = 0;j<y;j++){
                if(!visited[i][j]){
                    cout<<arr[i][j]<<endl;
                    cnt=0;
                    varG='#';
                    dfs(i,j);
                    if(varG!='#')v.pb(mp(varG,cnt));
                }
            }
        }
        printf("Problem %d:\n",tc);
        for(int i = 0;i<v.size();i++){
            cout<<v[i].fi<<" "<<v[i].sc<<endl;
        }
    }

}
