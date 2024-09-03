#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,d,rez;
    cin >> n;
    while(cin >> a >> d){
        rez = a+(n-1)*d;
        cout << rez <<'\n';
    }
}
