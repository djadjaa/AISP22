#include <iostream>
#include <stack>

using namespace std;

int main(){

    string izraz;
    cin >> izraz;

    stack<char> opStek;
    stack<int> vrStek;

    for(auto c:izraz){
        if(isdigit(c)){
            vrStek.push(c-'0');
        }
        else if(c=='M' || c=='m'){
            opStek.push(c);
        }
        else if(c==')'){
            int a=vrStek.top();
            vrStek.pop();
            int b=vrStek.top();
            vrStek.pop();
            char op=opStek.top();
            opStek.pop();
            int r=op=='m' ? min(a,b) : max(a,b);
            vrStek(push(r));
        }
    }
    cout << vrStek.top() << '\n';
    return 0;
}
