//oblik 2^a3^b5^c
//o(n)
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(){

    int64_t n;
    cin >> n;

    queue<int64_t> dvojke;
    queue<int64_t> trojke;
    queue<int64_t> petice;

    int64_t t=1;

    dvojke.push(2);
    trojke.push(3);
    petice.push(5);

    while(n--){
        t=min({dvojke.front(),trojke.front(),petice.front()});//minimum ce biti u nizu
        if(dvojke.front()==t){ //uklanjamo iz reda brojeve koje smo smestili u niz
            dvojke.pop();
        }
        if(trojke.front()==t){
            trojke.pop();
        }
        if(petice.front()==t){
            petice.pop();
        }
        dvojke.push(2*t);
        trojke.push(3*t);
        petice.push(5*t);
    }
    cout << t << '\n';
    return 0;
}

/*
 1 - baza ind
2:2
3:3
5:5
minimum{2,3,5}=2
1 2
2*2=4, 2*3=6, 2*5=10
2: 4
3: 3,6
5: 5,10
itd...
trazimo najmanji od elemenata u podskupovima, mnozimo sa 2 3 i 5 i ubacujemo u podskupove, kada taj minimalni elem ubacimo u niz brisemo sa podskupa
spisak brojeva pomnozenih sa 2 3 i 5 predstavljaju red
 */
