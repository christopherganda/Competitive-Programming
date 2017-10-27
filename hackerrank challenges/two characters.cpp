#include <bits/stdc++.h>
using namespace std;
#define freinput "input.txt","r",stdin
#define freoutput "output.txt","w",stdout
#define mp make_pair
#define fi first
#define sc second
#define pb push_back
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
string word;
int length;
int sum(char a,char b){
    string newWord="";
    for(int i=0;i<length;i++){
        if(word[i]==a || word[i]==b){
            newWord+=word[i];
            if(newWord.size()>1 && newWord[newWord.size()-2]==newWord[newWord.size()-1])return 0;
        }
    }
    return newWord.size();
}
int main(){
//    #ifdef chris
//    freopen(freinput);
//    freopen(freoutput);
//    #endif // chris
//    ios::sync_with_stdio(false);
    cin>>length>>word;
    set<char> setOfWord;
//    for(int i = 0;i<length;i++){
//        setOfWord.insert(word[i]);
//    }
    int maxTot = 0;
    int setSize = setOfWord.size();
    for(int i = 0;i<25;i++){
        for(int j = i+1;j<26;j++){
            maxTot = max(maxTot,sum('a'+i,'a'+j));
        }
    }
    if(length==1)cout<<0<<endl;
    else cout<<maxTot<<endl;
}
