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

int N; // Jumlah data
int data[100]; // Menyimpan data asli
int tree[4*100]; // Menyimpan data tree

int Segment_Tree(int start,int end,int indeks) {
    if (start == end) return tree[indeks] = data[start];
    else {
         int mid = (start + end) / 2;
         return tree[indeks] = max (Segment_Tree(start, mid, indeks*2), Segment_Tree(mid+1, end, indeks*2 + 1));
    }
}
void update(int start,int end,int change,int indeks) {
     if (start == end) tree[indeks] = data[change];
     else {
          int mid = (start + end) / 2;
          if (change <= mid) update(start, mid, change, indeks*2);
          else update(mid+1, end, change, indeks*2 + 1);
          tree[indeks] = max (tree[indeks*2], tree[indeks*2 + 1]);
     }
}
int query(int start,int end,int L,int R,int indeks) {
    if (L <= start && end <= R) return tree[indeks];
    else {
         int mid = (start + end) / 2;
         if (R <= mid) return query(start, mid, L, R, indeks*2);
         else if (L >= mid + 1) return query(mid+1, end, L, R, indeks*2 + 1);
         else return max (query(start, mid, L, R, indeks*2), query(mid+1, end, L, R, indeks*2 + 1));
    }
}

// O(n) = <N LogN, LogN>

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    int Q, T, A, B;
    printf("Masukan N : ");
    scanf("%d",&N);
    rep (i,1,N) {
        printf("Masukan data ke-%d : ", i);
        scanf("%d",&data[i]);
    }
    Segment_Tree(1, N, 1);
    printf("Masukan jumlah query : ");
    scanf("%d",&Q);
    rep(i,1,Q) {
       printf("Tipe query (1 : Update, 2 : Max) : ");
       scanf("%d",&T);
       if(T == 1) {
            printf("Masukan index data : ");
            scanf("%d",&A);
            printf("Masukan value : ");
            scanf("%d",&data[A]);
            update(1, N, A, 1);
            printf("Update berhasil.\n");
       }
       else{
           printf("Masukan index left : ");
           scanf("%d",&A);
           printf("Masukan index right : ");
           scanf("%d",&B);
           printf("Max dari index %d sampai %d : %d\n", A, B, query(1, N, A, B, 1));
       }
    }
    return 0;
}
