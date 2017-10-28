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
int parent[100007];
int rankk[100007];
int arr[100007];
void init(int n) { for (int i = 0; i < n; i++) parent[i] = i, rankk[i] = 1; }

int findd(int x) { return parent[x] == x ? x : parent[x] = findd(parent[x]); }

void unionn(int a,int b) {
     int x = findd(a), y = findd(b);
     if (x != y) {
        if (rankk[x] < rankk[y]) swap(x, y);
        rankk[x] += rankk[y];
        rankk[y] = 0;
        parent[y] = x;
        arr[x]++;
     }
}
int main(){
//    #ifdef chris
//    freopen(freinput);
//    freopen(freoutput);
//    #endif // chris
//    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    init(n);
    int result = 0;
    memset(arr,0,sizeof arr);
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        unionn(x,y);
    }
//    for(int i = 0;i<n;i++){
//        arr[parent[i]]++;
//    }
    sort(arr,arr+100007,comp());
    for(int i = 0;arr[i]!=0;i++){
        cout<<arr[i]<<endl;
    }
    cout<<result<<endl;

}
