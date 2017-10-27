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

struct edge {
    int src;
    int dest;
    int weight;
};

int MAX = 1000000000; // unlimited value
vector<edge> Edges; // semua data edge pada graph
long long dist[100]; // jarak terpendek dari source ke sebuah verteks

void BellmanFord(int src, int n) {
     // Step 1: Initialize distances from src to all other vertices
     // as INFINITE
     for (int i = 1; i <= n; i++) dist[i] = MAX;
     dist[src] = 0;
     int m = Edges.size();
     // Step 2: Relax all edges |V| - 1 times. A simple shortest
     // path from source to any other vertex can have at-most |V| - 1
     // edges
     for (int i = 1; i <= n-1; i++) { // Relax all edge E N-1 times
        for (int j = 0; j < m; j++) { // Check all edge in graph
            int u = Edges[i].src;
            int v = Edges[i].dest;
            int w = Edges[i].weight;
            if (dist[u] != MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
     }
     // Step 3: check for negative-weight cycles.  The above step
     // guarantees shortest distances if graph doesn't contain
     // negative weight cycle.  If we get a shorter path, then there
     // is a cycle.
     for (int i = 0; i < m; i++)
     {
         int u = Edges[i].src;
         int v = Edges[i].dest;
         int w = Edges[i].weight;
         if (dist[u] != MAX && dist[u] + w < dist[v]) printf("Graph contains negative weight cycle\n");
     }
}

// O(n) = V*E

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    return 0;
}
