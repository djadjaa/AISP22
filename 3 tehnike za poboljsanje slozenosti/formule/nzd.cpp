#include <iostream>
using namespace std;

int64_t nzd(int64_t a, int64_t b){
    while(b!=0){
        int64_t ost= a%b;
        a=b;
        b=ost;
    }
    return a;
}

int main(){
    int64_t m,p,k;
    cin >> m >> p >> k;
    cout << nzd(nzd(m,p),k) << endl;
    return 0;
}
/*
 jedan od načina za određivanje nzda je da od većeg oduzimamo manje (a>b) sve dok je a različit od b i kada su jednaki vraćamo jedan od ta dva. međutim složenost zavisi od dimenzija brojeva a i b (odn koji je veći). međutim desiće se da se kroz dugi niz koraka oduzima jedan broj pa potom drugi. efikasnije je deljenjem, jer se koraci smanjuju za duplo, a oba broja se istovremeno ažuriraju. takođe kada je prvi broj manji od drugog, tada će ostatak pri deljenju ta dva broja biti baš prvi broj (a), stoga u prvom koraku zamenjujemo ta dva broja (ako je prvi manji od drugog) i računamo klasično nzd deljenjem.
 ako dobijemo nzd(a,0) tada je nzd baš a (zato je uslov da je drugi broj različit od 0 jer 0 ne može da deli nijedan broj) i tad se zaustavljamo
 */
