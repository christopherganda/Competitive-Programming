#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s="";
    while(cin>>s && s!= "#"){
        bool val = next_permutation(s.begin(), s.end());
        if (val == false)
            cout << "No Successor" << endl;
        else
            cout << s << endl;
    }
    return 0;
}
