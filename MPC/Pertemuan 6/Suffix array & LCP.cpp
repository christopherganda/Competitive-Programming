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

char data[100]; // string yang akan di suffix
int n; // strlen(data)
int range; // jarak pengecekan pada saat compare
int sa[100]; // hasil suffix array
int rank[100]; // ranking pada saat compare suffix
int tmp[100]; // untuk menampung sementara hasil ranking suffix

bool SufCmp(int x,int y) {
     if (rank[x] != rank[y]) return rank[x] < rank[y];
     x += range;
     y += range;
     return (x < n && y < n) ? rank[x] < rank[y] : x > y;
}

void SuffixArray() {
     n = strlen(data);
     for (int i = 0; i < n; i++) sa[i] = i, rank[i] = data[i];
     tmp[0] = 0;
     for (range = 1; ; range *= 2) {
         sort(sa, sa+n, SufCmp);
         for (int i = 0; i < n-1; i++) tmp[i+1] = tmp[i] + SufCmp(sa[i], sa[i + 1]);
         for (int i = 0; i < n; i++) rank[sa[i]] = tmp[i];
         if (tmp[n-1] == n-1) break;
     }
}

// O(n) = N log^2 N)


int lcp[100]; // hasil LCP

void LCP() {
     SuffixArray();
     for (int i = 0, k = 0; i < n; i++) if (rank[i] != n-1) {
         for (int j = sa[rank[i] + 1]; data[i + k] == data[j + k]; ) ++k;
         lcp[rank[i]] = k;
         if (k) --k;
     }
}

// O(n) = N

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    printf("Masukan teks : ");
    scanf("%s",&data);
    n = strlen(data);
    SuffixArray();
    LCP();
    printf("Hasil suffix array dan LCP :\n");
    rep (i,0,n-1) printf("%d : %s\n", lcp[i], data + sa[i]);
    return 0;
}
