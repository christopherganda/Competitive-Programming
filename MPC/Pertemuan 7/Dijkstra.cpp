#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define gettime printf("\nTime : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repp(i,a,b) for(int i=a;i>=b;i--)
#define Set(x,a) memset(x,a,sizeof(x));

#define vs vector<string>
#define vi vector<int>
#define ll long long
#define ff first
#define ss second
#define pii pair<int,int>

struct comp {
       bool operator() (int a,int b) {
            return a>b;
       }
};

struct edge {
    int v;
    int w;
};

int MAX = 1000000000; // unlimited value
vector<edge> data[100]; // data edge pada graph
long long dist[100]; // jarak terpendek dari source ke sebuah verteks
priority_queue<pii, vector<pii>, greater<pii> > next; // queue berdasarkan jarak terpendek berikutnya

void dijkstra(int start,int n) {
     for (int i = 1; i <= n; i++) dist[i] = MAX;
     dist[start] = 0;
     next.push(MP(0, start));
     while (!next.empty()) {
           int u = next.top().ss;
           int n = data[u].size();
           next.pop();
           for (int i = 0; i < n; i++) {
               int v = data[u][i].v;
               int w = data[u][i].w;
               if (w + dist[u] < dist[v]) {
                  dist[v] = w + dist[u];
                  next.push(MP(dist[v], v));
               }
           }
     }
}

// O(n) = N LogN

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    int n, m, a, b, c;
    edge tmp;
    printf("Masukan N : ");
    scanf("%d",&n);
    printf("Masukan jumlah edge : ");
    scanf("%d",&m);
    printf("Format edge : Sumber Tujuan Nilai\n");
    rep (i,0,m-1) {
        printf("Masukan edge ke-%d : ", i+1);
        scanf("%d %d %d", &a, &b, &c);
        tmp.w = c;
        tmp.v = b;
        data[a].PB(tmp);
        tmp.v = a;
        data[b].PB(tmp);
    }
    printf("Masukan start : ");
    scanf("%d",&a);
    printf("Masukan tujuan : ");
    scanf("%d",&b);
    dijkstra(a, b);
    printf("Jarak terpendek adalah ");
    cout<<dist[b];
    return 0;
}
