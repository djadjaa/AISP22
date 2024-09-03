/* POTREBNO JE ZNATI SLEDEĆE POJMOVE:
    -h(v)=max(h(v->levo),h(v->desno))+1 -> visina nepraznog drveta = 1+max(visinalevog,visinadesnog)
    -faktor ravnoteze korena je apsolutna razlika između visina levog i desnog potomka koji formiraju poddrva
    -najveći faktor ravnoteže definisan je: max( najveći faktor levog poddrveta, najveći faktor desnog poddrveta, faktor ravnoteže korena)
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct Cvor {
  int vrednost;
  Cvor *levo, *desno;
};

Cvor* napravi_Cvor(int x, Cvor* levo = nullptr, Cvor* desno = nullptr) {
  Cvor* novi = new Cvor();
  novi->vrednost = x;
  novi->levo = levo;
  novi->desno = desno;
  return novi;
}

Cvor* ucitaj() {
  char c;
  cin >> c;
  if (c == '-')
    return nullptr;
  else {
    // ucitali smo [
    int vrednost;
    cin >> vrednost >> ws; // ucitavamo vrednost u korenu i preskacemo beline
    Cvor* levo = ucitaj(); // rekurzivno ucitvamo levo poddrvo
    cin >> ws; // preskacemo beline
    Cvor* desno = ucitaj(); // rekurzivno ucitvamo desno poddrvo
    cin >> ws; // preskacemo beline
    // ucitavamo ]
    cin >> c;
    // kreiramo koreni Cvor i vracamo celo ucitano drvo
    return napravi_Cvor(vrednost, levo, desno);
  }
}

/*
int visina(Cvor *koren){
    if(koren==nullptr){
        return 0;
    }
    return 1+max(visina(koren->levo), visina(koren->desno));
}

int maxFaktorRavnoteze(Cvor *koren){
    if(koren==nullptr){
        return 0;
    }
    int maxFaktorLevo=maxFaktorRavnoteze(koren->levo);
    int maxFaktorDesno=maxFaktorRavnoteze(koren->desno);
    int visinaLevo=visina(koren->levo);
    int visinaDesno=visina(koren->desno);
    int faktorKorena=abs(visinaLevo-visinaDesno);
    return max({faktorKorena,maxFaktorLevo,maxFaktorDesno})
}
*/
//efikasnije je računati i visinu i maksimalni faktor odjednom

void maxFaktorIVisina(Cvor* koren, int &visina, int &maxFaktor){
    if(koren==nullptr){ //ako je stablo prazno, visina je nula, pa i njegov maksimalni faktor takođe 0; baza indukcije
        visina=maxFaktor=0;
        return;
    }
    int visinaLevo,maxFaktorLevo;
    maxFaktorIVisina(koren->levo,visinaLevo,maxFaktorLevo); //za levo podstablo radimo i najveći faktor i njegovu visinu
    int visinaDesno,maxFaktorDesno;
    maxFaktorIVisina(koren->desno,visinaDesno,maxFaktorDesno); //isto i za desno podstablo

    //i tako idemo sve dok ne dođemo do lista i idemo odozdo ka gore
    //odozgo vidimo kako se šta zapravo računa (lakši pregled mada neefikasan kod)

    int faktor=abs(visinaLevo-visinaDesno); //ravnoteža korena
    maxFaktor=max({faktor,maxFaktorLevo,maxFaktorDesno}); //maksimalni faktor ravnoteže
    visina=1+max(visinaLevo,visinaDesno); //visina nepraznog drveta
    //pritom ove vrednosti šaljemo po referenci pa pri vraćanju rezultata (maksimalnog faktora) u narednoj funkciji znaćemo koja je zvanično visina i koji je zvanično faktor ravnoteze korena
}

int maxFaktorRavnoteze(Cvor *koren){
    int visina, maxFaktor;
    maxFaktorIVisina(koren,visina,maxFaktor); //s obzirom na to da smo poslali reference u fju maxFaktorIVisina kod vrednosti visine i vrednosti maksimalnog faktora, dobićemo rezultujuće vrednosti i vratićemo maxFaktor
    return maxFaktor;
}

int main(){

    ios_base::sync_with_stdio(false);
    Cvor* koren = ucitaj();
    cout << maxFaktorRavnoteze(koren) << endl;
    obrisi(koren);
    return 0;
}
