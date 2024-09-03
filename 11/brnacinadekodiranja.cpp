/*
 21213
 deo po deo stringa intepretiracemo kao pojedinacni karakter ili kao podniska ili kao ceo string
 2 1 2 1   3
 2 1 2    13

            212      13
            /  \
        2 12  2 1 2
 mozemo ici od kraja ili od pocetka stringa
 rekurzivna veza: uklanjamo prvi karakter pa za duzinu n -1 kazemo koliko imamo mogucnosti kodiranja ili prva dva pa posmatramo duzinu n-2, medjutim u drugom slucaju moze da se desi da su prva dva karaktera >= 26, pa cemo u tom slucaju uvesti uslov da karakter mora biti izmedju 1 i 26
 imamo izuzetke: 212 __ -> 05, 80 ili 2128 _ ->0 <-> dakle nemamo ascii kodove 05 i 80 a ni za 0
 */
#include <iostream>
#include <string>
using namespace std;

uint64_t brDekodiranja(string &s, int n){
    if(n<=1){//tada imamo samo 1 karakter
        return 1;
    }
    int b1=s[n-1]-'0'; //ako uzimamo 1 cifru
    int b2=(s[n-2]-'0')*10 + (s[n-1]-'0'); //a potom drugu cifru
    uint64_t br=0;
    if(br!=0){ //jedini nacin da nece dekodiranje uspeti je da imamo 0 kao ascii kod
        br += brDekodiranja(s,n-1);
    }
    if(b2>=10 && b2<=26){ //ako ne pocinje nulom i ako sadrzi cifru kojom mozemo kodirati
        br+=brDekodiranja(s,n-2);
    }
    return br;
}

int main(){

    string s;
    cin >> s;
    cout << brDekodiranja(s,s.size()) << '\n';
    return 0;
}

/*
 2124:
    212 4
    21 24
 ako prebrojimo dekodiranja koja se zavrsavaju sa 4 i ona sa 24 mi smo prebrojili sva dekodiranja broja 2124
 jer desice se da se u rekurzivnim pozivima racuna ponovo br kodiranja za 212 ili 21
 br kodiranja zavisice od broja n
 */
