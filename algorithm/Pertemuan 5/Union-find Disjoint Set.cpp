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

int parent[100]; // menyimpan nilai parent
int rankk[100]; // menyimpan rankking suatu set

void init(int n) { for (int i = 1; i <= n; i++) parent[i] = i, rankk[i] = 1; }

int findd(int x) { return parent[x] == x ? x : parent[x] = findd(parent[x]); }

void unionn(int a,int b) {
     int x = findd(a), y = findd(b);
     if (x != y) {
        if (rankk[x] < rankk[y]) swap(x, y);
        rankk[x] += rankk[y];
        rankk[y] = 0;
        parent[y] = x;
     }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    return 0;
}
