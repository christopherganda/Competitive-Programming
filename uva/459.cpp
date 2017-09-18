#include <bits/stdc++.h>
using namespace std;
#define freinput "input.txt","r",stdin
#define freoutput "output.txt","w",stdout
#define mp make_pair
#define fi first
#define sc second
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
typedef long long ll;
typedef unsigned long int uld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
struct comp {
       bool operator() (int a,int b) {
            return a>b;
       }
};

int parent[100]; // menyimpan nilai parent
int rankk[100]; // menyimpan rankking suatu set

void init(int n) { for (int i = 0; i <= n; i++) parent[i] = i, rankk[i] = 1; }

int findd(int x) { return parent[x] == x ? x : parent[x] = findd(parent[x]); }

void gabung(int a,int b) {
     int x = findd(a), y = findd(b);
     if (x != y) {
        if (rankk[x] < rankk[y]) swap(x, y);
        rankk[x] += rankk[y];
        rankk[y] = 0;
        parent[y] = x;
     }
}
int main(){
    #ifdef chris
    freopen(freinput);
    freopen(freoutput);
    #endif // chris
    int tc;
    cin>>tc;
    for(int i = 0;i<tc;i++){
        char a;
        cin>>a;
//        cout<<a<<endl;
        int d = a-'A';
        init(26+5);
        string kata;
        getchar();
        while(getline(cin,kata) && !kata.empty()){
            int b = kata[0]-'A';
            int c = kata[1]-'A';
            gabung(c,b);
        }
        int hasil = 0;
        for(int j = 0;j<=d;j++){
            findd(j);
            if(rankk[j]>0)hasil++;
//            cout<<rankk[j]<<endl;
        }
        cout<<hasil<<endl;
        if(i!=tc-1)cout<<endl;
    }
}
