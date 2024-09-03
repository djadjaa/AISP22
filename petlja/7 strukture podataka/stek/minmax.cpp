#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    //( ) m M broj

    char c;
    stack<char>operacija;
    stack<char>vrednost;
    while(cin>>c) {
        if(c>='0' && c<='9')
            vrednost.push(c);
        else if(c=='m' || c=='M')
            operacija.push(c);
        else if(c==')'){
            int64_t vr1 = vrednost.top();
            vrednost.pop();
            int64_t vr2 = vrednost.top();
            vrednost.pop();
            if(operacija.top() == 'm'){
                vrednost.push(min(vr1,vr2));
            }else{
                vrednost.push(max(vr1,vr2));
            }
            operacija.pop();
        }
    }
    cout << vrednost.top() << endl;
    return 0;
}
