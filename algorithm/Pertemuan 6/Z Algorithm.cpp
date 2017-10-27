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

int ans[100]; // menyimpan hasil z algo
string data; // string yang akan di cek
int n; // data.size()

void z_algo() {
     int L = 0, R = 0;
     n = data.size();
     ans[0] = 0;
     for (int i = 1; i < n; i++) {
         if (i > R) {
            L = R = i;
            while (R < n && data[R-L] == data[R]) R++;
            ans[i] = R-L; R--;
         }
         else {
              int k = i-L;
              if (ans[k] < R-i+1) ans[i] = ans[k];
              else {
                   L = i;
                   while (R < n && data[R-L] == data[R]) R++;
                   ans[i] = R-L; R--;
              }
         }
     }
}

// O(n) = |N|

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    printf("Masukan teks : ");
    cin>>data;
    n = data.size();
    z_algo();
    rep (i,0,n-1) {
        printf("Mulai dari huruf %c : %d\n", data[i], ans[i]);
    }
    return 0;
}
