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

struct comp {
       bool operator() (int a,int b) {
            return a>b;
       }
};


int n; // jumlah node
vi data[100]; // data graph
int topParent[100][7]; // menyimpan top parent dari setiap node
int parent[100]; // menyimpan parent dari setiap node
int level[100]; // menyimpan level dari node
bool visit[100] = {}; // menyimpan status visit node untu buildLCA

void dfs(int u = 1,int ParentOfU = 1,int Lvl = 0) {
     if (!visit[u]) {
        visit[u] = true;
        level[u] = Lvl;
        parent[u] = ParentOfU;
        int m = data[u].size();
        for (int v = 0; v < m; v++)
            if (!visit[data[u][v]])
               dfs(data[u][v], u, Lvl+1);
     }
}

void buildLCA() {
    dfs(1, 1, 0);
     for (int i = 1; i <= n; i++)
         for (int j = 0; 1 << j < n; j++)
             topParent[i][j] = (j == 0 ? parent[i] : -1);
     for (int j = 1; 1 << j < n; j++)
         for (int i = 1; i <= n; i++)
             if (topParent[i][j - 1] != -1)
                topParent[i][j] = topParent[topParent[i][j - 1]][j - 1];
}

int LCA(int u,int v) {
    if (level[u] < level[v]) swap(u, v);
    int k = log2 (level[u]);
    for (int i = k; i >= 0; i--)
        if (level[u] - (1 << i) >= level[v]) u = topParent[u][i];
    if (u == v) return u;
    for (int i = k; i >= 0; i--)
        if (topParent[u][i]!= topParent[v][i]) u = topParent[u][i], v = topParent[v][i];
    return parent[u];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    n = 8;
    data[1].PB(2);
    data[1].PB(3);
    data[1].PB(4);
    data[2].PB(5);
    data[2].PB(6);
    data[4].PB(7);
    data[7].PB(8);
    buildLCA();
    printf("LCA dari 5 dan 6 : %d\n", LCA(5, 6));
    printf("LCA dari 2 dan 4 : %d\n", LCA(2, 4));
    printf("LCA dari 2 dan 7 : %d\n", LCA(2, 7));
    printf("LCA dari 2 dan 8 : %d\n", LCA(2, 8));
    printf("LCA dari 6 dan 7 : %d\n", LCA(6, 7));
    printf("LCA dari 7 dan 8 : %d\n", LCA(7, 8));
    printf("LCA dari 4 dan 7 : %d\n", LCA(4, 7));
    printf("LCA dari 4 dan 8 : %d\n", LCA(4, 8));
    return 0;
}
