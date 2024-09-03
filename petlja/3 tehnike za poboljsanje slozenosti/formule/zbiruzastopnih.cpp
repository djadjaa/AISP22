/*ono što radimo grubo na početku je da za svaki početni član određujemo koliko sabiraka je potrebno do željenog zbira
 * međutim kako je broj sabiraka promenljiv možemo ispitati svaku situaciju za određen broj sabiraka. dobićemo najveći broj sabiraka za koji dobijamo željeni zbir. vidimo da za fiksirani br sabiraka, početni član se inkrementira, a zbir se uvećava za baš taj fiksirani broj sabiraka. vidimo da sabirci čine aritmetički niz, a da je d između zbirova baš fiksiran broj sabiraka, pa ćemo na osnovu formule za sumu aritmetičkog niza odrediti jednačinu za broj sabiraka koja će nam predstaviti upravo taj fiksirani broj.
 * međutim, kako će se odrediti kad tad najveći broj sabiraka, program će bespotrebno ići računati zbirove koji će prekoračiti željeni. početni član je takođe promenljiv, pa moramo na isti način odrediti jednačinu za početni član. pošto početni član mora biti prirodan broj, proverićemo da li je deljiv sa brojem sabiraka (na osnovu jednacine) dakle ostatak mora biti nula
 */
#include <iostream>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    int64_t uzastopni=0;
    for(int m=2; (m+m*(m-1))/2<=n; m++){ //br sabiraka
        if((n-(m*(m-1))/2)%m==0){ //početni fiksirani član
            uzastopni++;
        }
    }
    cout << uzastopni << endl;
    return 0;
}
/*
 početni član je a0, a m je broj sabiraka: a0+a0+1+...+a0+(m-1)
 vidimo da je u pitanju suma aritmetičkog niza pa dobijamo formulu
 m*a0+(m*(m-1))/2 što daje broj koji smo uneli na početku (n)
 kada je početni član 1, tada je n:
 m+(m(m-1))/2
 tada imamo najveći broj sabiraka
 i time dobijamo fiksirani početni član koji kad delimo sa m mora biti celobrojan
 */
