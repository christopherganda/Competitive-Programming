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

int ans[100][100];
int LCS(string X, string Y)
{
    // Build L[m+1][n+1] in bottom up fashion
    int m = X.size();
    int n = Y.size();
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) ans[i][j] = 0;
            // Jika karakter sama maka ambil diagonal kiri atas tambah 1
            else if (X[i - 1] == Y[j - 1]) ans[i][j] = ans[i - 1][j - 1] + 1;
            // Jika karakter tidak sama maka ambil maks dari kiri atau atas
            else ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
        }
    }
    return ans[m][n];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    string teks1;
    string teks2;
    printf("Masukan text 1 : ");
    cin>>teks1;
    printf("Masukan text 2 : ");
    cin>>teks2;
    printf("Longest Common Subsequence : %d\n", LCS(teks1, teks2));
    return 0;
}
