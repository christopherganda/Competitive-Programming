
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

string data1; // string pattern
string data2; // string teks yang akan di cek
int pat[100]; // menyimpan pattern
int m; // data1.size()
int n; // data2.size()

void kmppattern() {
     int i = 0, j = -1;
     pat[0] = -1;
     m = data1.size();
     while (i < m) {
           while (j >= 0 && data1[i] != data1[j]) j = pat[j];
           i++; j++;
           pat[i]=j;
     }
}

int kmpsearch() {
    int i = 0, j = 0, ans = 0;
    n = data2.size();
    while (i < n) {
          while (j >= 0 && data2[i] != data1[j]) j = pat[j];
          i++; j++;
          if (j == m) {
             ans++;
             j = pat[j];
          }
    }
    return ans;
}

// O(n) = |N| + |M|

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    printf("Masukan pattern : ");
    cin>>data1;
    printf("Masukan teks yang dicari : ");
    cin>>data2;
    kmppattern();
    printf("Jumlah pattern ditemukan pada teks : %d", kmpsearch());
    return 0;
}
