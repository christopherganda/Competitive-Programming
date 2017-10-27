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

int data[100][100]; // matriks dari graph

void floyd_warshall(int n) {
     for (int k = 0; k < n; k++) {
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
                 data[i][j] = min (data[i][j], data[i][k] + data[k][j]);
             }
         }
     }
}

// O(n) = N^3

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    return 0;
}
