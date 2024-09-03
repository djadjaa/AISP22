#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    char c;
    set<int64_t> s;
    int64_t x,lg,dg;
    while(n--){
        cin >> c;
        if(c=='t'){
            cin >> x;
            s.insert(x);
        }else if(c=='i'){
            cin >> lg >> dg;
            int64_t_ umanjilac = s.lower_bound(lg);
            if(umanjilac == s.end()){
                cout << 0 << endl;
            }
            int64_t umanjenik = s.lower_bound(dg);
            if(umanjenik!=dg){

            }else{

            }

        }
    }

    return 0;
}
