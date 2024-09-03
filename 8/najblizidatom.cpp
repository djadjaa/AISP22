/*dodaj(x) - dodaj x u strukturu ako x nije prisutno
 * obrisi(x) - brise x iz strukture
 * najblizi(x) -vraca najblizi elem po vrednosti broju x iz strukture
 * operacije koje budemo implementirali bice slozenosti o(logn)
 * bice nalik primeni skupa
 */
#include <iostream>
#include <set>
using namespace std;
set<int> s;//globalna promenljiva

void dodaj(int x){
    s.insert(x);
}

void obrisi(int x){
    s.erase(x);
}

int najblizi(int x){
    auto it=s.lower_bound(x); //logn
    if(it == end(s)){
        return *(--it); //vracamo poslednji elem
    }
    if(it==begin(s)){
        return *it; //vracamo pocetak
    }
    int temp = *it //trenutni
    int pr=*(--it);  //prethodni
    if(abs(temp-x)< abs(pr-x)){
        return temp;
    }else{
        return pr;
    }
}
