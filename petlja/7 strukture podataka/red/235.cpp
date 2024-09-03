#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int64_t n;
    cin >> n;
    queue<int64_t> dvojke,trojke,petice;
    dvojke.push(2);
    trojke.push(3);
    petice.push(5);
    int64_t rez=1;
    for(int i=0; i<n; i++){
        rez=min({dvojke.front(),trojke.front(),petice.front()});
        dvojke.push(2*rez);
        trojke.push(3*rez);
        petice.push(5*rez);
        while(dvojke.front() == rez){
            dvojke.pop();
        }
        while(trojke.front() == rez){
            trojke.pop();
        }
        while(petice.front() == rez){
            petice.pop();
        }
    }
    cout << rez << endl;
}
