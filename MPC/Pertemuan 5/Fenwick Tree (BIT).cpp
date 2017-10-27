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
int fenwick[100005] = {}; // menyimpan hasil fenwick

// Actually, you don't need to know what each node contains. The only thing you should know is that how to solve this problem using Fenwick (and then you can change it and solve so many problems).

void updateFenwick(int indeks,int value) {
     for ( ; indeks <= n; indeks += indeks & -indeks) fenwick[indeks] += value;
}

int sumFenwick(int L, int R) {
    int sumL = 0, sumR = 0;
    L--;
    for ( ; L > 0 ; L -= L & -L) sumL += fenwick[L];
    for ( ; R > 0 ; R -= R & -R) sumR += fenwick[R];
    return sumR - sumL;
}

// O(n) = <N LogN, LogN>

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
        scanf("%d",&A);
        updateFenwick(i, A);
    }
    printf("Masukan jumlah query : ");
    scanf("%d",&Q);
    rep(i,1,Q) {
       printf("Query ke-%d :\n", i);
       printf("Masukan index left : ");
       scanf("%d",&A);
       printf("Masukan index right : ");
       scanf("%d",&B);
       printf("Sum dari index %d sampai %d : %d\n", A, B, sumFenwick(A, B));
    }
    return 0;
}
