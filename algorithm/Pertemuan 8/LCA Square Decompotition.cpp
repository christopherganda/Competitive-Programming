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
int topParent[100]; // menyimpan top parent dari setiap node
int parent[100]; // menyimpan parent dari setiap node
int level[100]; // menyimpan level dari node
bool visit[100] = {}; // menyimpan status visit node untu buildLCA
int maxLevel; // jumlah level maks dari tree
bool visitDFS[100] = {}; // menyimpan status visit node untuk dfs

int dfs(int node, int level) {
    visitDFS[node] = true;
    int maxLevel = level;
    int m = data[node].size();
    for (int i = 0; i < m; i++) {
        if (visitDFS[data[node][i]] == false) {
            maxLevel = max(maxLevel, dfs(data[node][i], level + 1));
        }
    }
    return maxLevel;
}

void buildLCA(int u,int ParentOfU,int AkarN,int Lvl = 0) {
     if (!visit[u]) {
        visit[u] = true;
        level[u] = Lvl;
        parent[u] = ParentOfU;
        if (Lvl < AkarN) topParent[u] = 1;
        else if (level[u] % AkarN == 0) topParent[u] = parent[u];
        else topParent[u] = topParent[parent[u]];
        int m = data[u].size();
        for (int v = 0; v < m; v++)
            if (!visit[data[u][v]])
               buildLCA(data[u][v], u, AkarN, Lvl + 1);
     }
}

int LCA(int u,int v) {
    while (topParent[u] != topParent[v]) {
          if (level[u] > level[v]) u = topParent[u];
          else v = topParent[v];
    }
    while (u != v) {
          if (level[u] > level[v]) u = parent[u];
          else v = parent[v];
    }
    return u;
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
    maxLevel = dfs(1, 1);
    buildLCA(1, 1, sqrt(maxLevel), 0);
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
