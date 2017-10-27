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

vector<int> data[100]; // data graph
bool visit[100] = {}; // menyimpan apakah suatu node telah di kunjungi
vector<int> ans; // menyimpan hasil dari topologi sort

void topologi_sort(int u) {
     if (visit[u]) return;
     visit[u] = true;
     int n = data[u].size();
     for (int i = 0; i < n; i++) topologi_sort(data[u][i]);
     ans.push_back(u);
}

// O(n) = V+E

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    return 0;
}
