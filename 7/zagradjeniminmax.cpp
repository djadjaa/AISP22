/*
 citamo jedan po jedan karakter, kada procitamo ), potrebno je izracunati izraz i celokupan izraz zamenimo sa rezultatom
 imacemo dva steka za operaciju i za vrednost
 push <=> push_back
 pop <=> pop_back
 top <=> back
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    char k;
    vector<char> op;
    vector<char> vr;
    while(cin >> k){
        if(k>='0' && k<='9'){
            vr.push_back(k);
        }
        else if(k=='m' || k=='M'){
            op.push_back(k);
        }
        else if(k==')'){
            int64_t vr1 = vr.back();
            vr.pop_back();
            int64_t vr2 = vr.back();
            vr.pop_back();
            if(op.back()=='m'){
                vr.push_back(min(vr1,vr2));
            }
            else{
                vr.push_back(max(vr1,vr2));
            }
            op.pop_back(); //kad zavrsimo operaciju brisemo je sa steka
        }
    }

    cout << vr.back() << '\n';

    return 0;
}
