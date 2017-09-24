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
int n;
int arr[107][107];
bool visited[107][107];
bool check[107];
int m;
void flood(int i,int j){
    if(i<0 || i>=n || j<0 || j>=n)return;
    if(visited[i][j])return;
    if(arr[i][j]!=m){
        return;
    }
    visited[i][j]=1;
    flood(i+1,j);
    flood(i-1,j);
    flood(i,j+1);
    flood(i,j-1);
}
int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
//    ios::sync_with_stdio(false);
    while(scanf("%d",&n)==1){
        memset(visited,0,sizeof(visited));
        memset(arr,0,sizeof(arr));
        memset(check,0,sizeof(check));
        for(int i =1;i<n;i++){
            for(int j = 0;j<n;j++){
                int x,y;
                cin>>x>>y;
                arr[x-1][y-1] = i;
            }
        }
        bool ans = true;
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    m=arr[i][j];
                    if(check[m]){
                        ans = false;
                        check[m]=0;
                        break;
                    }
                    else{
                        flood(i,j);
                        check[m]=1;
                    }
                }
            }
        }
//        for(int i = 0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<visited[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        for(int i = 0;i<n;i++){
//            if(!check[i]){
//                cout<<"wrong"<<endl;
//                break;
//            }else if(i==n-1)cout<<"good"<<endl;
//        }
        if(!ans)cout<<"wrong"<<endl;
        else cout<<"good"<<endl;
    }
}

