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

string data; // Data yang akan di buat trie
int n; // data.size()

struct Tries {
       bool end;
       Tries *next[26];
};

// Menambah string ke dalam trie yang sudah ada
void buildTrie(Tries *trie,int indeks = 0) {
     if (indeks >= n) (*trie).end = true;
     else {
          if ((*trie).next[data[indeks]-'a'] == NULL) {
             Tries *node = new Tries();
             (*trie).next[data[indeks]-'a'] = node;
          }
          buildTrie((*trie).next[data[indeks]-'a'], indeks+1);
     }
}

// Mengecek apakah suatu string ada di dalam trie
bool query(Tries *trie,int indeks = 0) {
     if (indeks >= n) return (*trie).end;
     else {
          if ((*trie).next[data[indeks]-'a'] == NULL) return false;
          else return query((*trie).next[data[indeks]-'a'], indeks+1);
     }
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(false);
    return 0;
}
