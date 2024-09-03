#include <bits/stdc++.h>

using namespace std;

int main(){

    map<string, string> spijuni;
    string s1,s2;
    set<string> potencijalni;
    int64_t n;
    cin >> n;
    while(n--){
        cin >> s1 >> s2;
        spijuni[s1] = s2;
        potencijalni.insert(s2);
    }
    int64_t num=0;
    for(auto it : spijuni){
        if(spijuni.find(it.second) == spijuni.end() && potencijalni.find(it.first) != potencijalni.end())
            num++;
    }
    cout << num << endl;
    return 0;
}
