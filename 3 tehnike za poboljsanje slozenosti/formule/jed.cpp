#include <iostream>
using namespace std;
int main(){

    string s;
    cin >> s;
    long long brjed=0;
    for(int i=0; s[i]!=0; i++){
        if(s[i]=='1'){
            brjed++;
        }
    }
    long long rez = (brjed*(brjed-1))/2;
    cout << rez << '\n';
    return 0;
}
/*
 prvo odredimo koliko imamo jedinica u binarnom zapisu. zatim preko binomnog koeficijenta, odnosno kombinacije bez ponavljanja, možemo izvući 2 jedinice i na taj način odrediti koliko ima podstringova sa baš dve jedinice
 (n 2) gde je n uk broj jedinica, a 2 je željeni broj jedinica u svakom podstringu:=> kako zamenjujemo n sa ukupnim brojem jedinica i kako budemo sređivali jednakost, dobijamo u svakom slučaju formulu (n(n-1))/2 koju ćemo i koristiti
 */
