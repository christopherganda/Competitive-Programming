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
#define MAX_N 50005
int parent[MAX_N];
int rankk[MAX_N];
void init(int n) { for (int i = 1; i <= n; i++) parent[i] = i, rankk[i] = 1; }

int findd(int x) { return parent[x] == x ? x : parent[x] = findd(parent[x]); }

void gabung(int a,int b) {
     int x = findd(a), y = findd(b);
     if (x != y) {
        if (rankk[x] < rankk[y]) swap(x, y);
        rankk[x] += rankk[y];
        rankk[y] = 0;
        parent[y] = x;
     }
}
int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
//    ios::sync_with_stdio(false);
    int n,m;
    int tc= 0;
    while(scanf("%d %d",&n,&m),(n||m)){
        tc++;
        init(MAX_N);
        for(ll i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            gabung(b,a);
        }
        int total = 0;
        for(ll i = 1;i<=n;i++){
            if(rankk[i]>0)total++;
        }
        printf("Case %d: %d\n",tc,total);
    }

}
