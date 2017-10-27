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

// Given two strings str1 and str2 and below operations that can performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.
// Insert
// Remove
// Replace

int editDistance(string str1, string str2)
{
    // Create a table to store results of subproblems
    int dp[100][100];
    int m = str1.size();
    int n = str2.size();

    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i==0) dp[i][j] = j;  // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0) dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];

            // If last character are different, consider all
            // possibilities and find minimum
            else dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                min(dp[i-1][j],  // Remove
                                    dp[i-1][j-1])); // Replace
        }
    }
    return dp[m][n];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    string str1;
    string str2;
    printf("Masukan teks 1 : ");
    cin>>str1;
    printf("Masukan teks 2 : ");
    cin>>str2;
    printf("Minimum number of edits (operations) required : %d", editDistance(str1, str2));
    return 0;
}
