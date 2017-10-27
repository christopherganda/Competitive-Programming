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

int n;
int data[100]; // Berisi data asli

int LIS()
{
    vi tmp; // vector untuk menampung LIS terpanjang
    vi::iterator it;
    for (int i = 1; i <= n; i++) {
        it = lower_bound(tmp.begin(), tmp.end(), data[i]);
        if (it == tmp.end()) tmp.push_back(data[i]);
        else *it = data[i];
        // upper_bound => non-decreasing
        // lower_bound => increasing
    }
    return tmp.size();
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    printf("Masukan N : ");
    scanf("%d",&n);
    rep (i,1,n) {
        printf("Masukan data ke-%d : ", i);
        scanf("%d",&data[i]);
    }
    printf("Longest Increasing Subsequence : %d", LIS());
    return 0;
}
