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

int n; // Jumlah data
int data[100]; // Menyimpan data asli
int sp[100][6 + 1]; // tempat menyimpan sparse table ( int sp[N][log2(N) + 1] )

void SparseTable() {
    // We will keep an array M[0, N-1][0, logN] where M[i][j] is the index of the minimum value in the sub array starting at i having length 2^j.
     for (int i = 0; i < n; i++) sp[i][0] = i;
     for (int j = 1 ; 1 << j <= n; j++) {
         for (int i = 0; i + (1 << j) - 1 < n; i++) {
             if (data[sp[i][j - 1]] > data[sp[i + (1 << (j - 1))][j - 1]]) sp[i][j] = sp[i][j - 1];
             else sp[i][j] = sp[i + (1 << (j - 1))][j - 1];
         }
     }
}
int query(int l,int r) {
    // The idea is to select two blocks that entirely cover the interval [i..j] and  find the minimum between them.
    int k = log2 (r - l + 1);
    return max(data[sp[l][k]], data[sp[r - (int)pow(2, k) + 1][k]]);
}

// O(n) = <N LogN, 1>

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    int Q, T, A, B;
    printf("Masukan N : ");
    scanf("%d",&n);
    rep (i,1,n) {
        printf("Masukan data ke-%d : ", i);
        scanf("%d",&data[i-1]);
    }
    SparseTable();
    printf("Masukan jumlah query : ");
    scanf("%d",&Q);
    rep(i,1,Q) {
       printf("Query ke-%d :\n", i);
       printf("Masukan index left : ");
       scanf("%d",&A);
       printf("Masukan index right : ");
       scanf("%d",&B);
       printf("Max dari index %d sampai %d : %d\n", A, B, query(A - 1, B - 1));
    }
    return 0;
}
