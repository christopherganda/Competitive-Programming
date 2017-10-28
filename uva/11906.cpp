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
char arr[107][107];
bool visited[107][107];
int cnt[107][107];
int total;
int r,c,m,n;
void dfs(int x,int y){
    if(x>=r || x >= c || y >=r || y>=c)return;
    if(x<0 || y<0)return;
    if(arr[x][y]=='#')return;
    if(visited[x][y]==1)return;
    visited[x][y] = 1;
//    cnt[x][y]++;
    if(x+m<r && y+n<c && x+m>=0 && y+n>=0 && arr[x+m][y+n]!='#'){cnt[x+m][y+n]++;}
    if(x+n<r && y+m<c && x+n>=0 && y+m>=0 && arr[x+n][y+m]!='#'&& m!=n && m!=0 && n!=0){cnt[x+n][y+m]++;}
    if(x-m<r && y-n<c && x-m>=0 && y-n>=0 && arr[x-m][y-n]!='#'){cnt[x-m][y-n]++;}
    if(x-n<r && y-m<c && x-n>=0 && y-m>=0 && arr[x-n][y-m]!='#'&& m!=n && m!=0 && n!=0){cnt[x-n][y-m]++;}
    if(x+m<r && y-n<c && x+m>=0 && y-n>=0 && arr[x+m][y-n]!='#'){cnt[x+m][y-n]++;}
    if(x-m<r && y+n<c && x-m>=0 && y+n>=0 && arr[x-m][y+n]!='#'){cnt[x-m][y+n]++;}
    if(x+n<r && y-m<c && x+n>=0 && y-m>=0 && arr[x+n][y-m]!='#'&& m!=n && m!=0 && n!=0){cnt[x+n][y-m]++;}
    if(x-n<r && y+m<c && x-n>=0 && y+m>=0 && arr[x-n][y+m]!='#'&& m!=n && m!=0 && n!=0){cnt[x-n][y+m]++;}
    dfs(x+m,y+n);//1
    dfs(x+n,y+m);//2
    dfs(x-m,y-n);//3
    dfs(x-n,y-m);//4
    dfs(x+m,y-n);//5
    dfs(x-m,y+n);//6
    dfs(x+n,y-m);//7
    dfs(x-n,y+m);//8

}
int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
//    ios::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int i = 1;i<=tc;i++){
        for(int j=0;j<=100;j++){
            for(int k = 0;k<=100;k++){
                arr[j][k]='.';
                visited[j][k]=0;
                cnt[j][k]=0;
            }
        }
        total = 0;
        cin>>r>>c>>m>>n;
        int w;
        cin>>w;
        for(int j = 0;j<w;j++){
            int x,y;
            cin>>x>>y;
            arr[x][y]='#';
        }
        dfs(0,0);
        int odd=0,even =0 ;
        for(int j=0;j<r;j++){
            for(int k = 0;k<c;k++){
//                cout<<cnt[j][k]<<" ";
                if(cnt[j][k]%2==0 && visited[j][k])even++;
                else if(cnt[j][k]%2==1 && visited[j][k]) odd++;
//                cout<<cnt[j][k]<<" ";
            }

//            cout<<endl;
        }
        printf("Case %d: %d %d\n",i,even,odd);
    }
}
