#include <bits/stdc++.h>

using namespace std;

struct cvor{
    char c;
    cvor *l, *d;
};

cvor *obidji(const string& str, int &i){
    cvor *c = new cvor();
    c->c = str[i++]; //ubacujemo u čvor karakter sa stringa
    if(isupper(c->c)){ //ako je veliko slovo ono je list
        c->l = c->d = nullptr;
    }else{ //inače prolazimo kroz levo i desno podstablo
        c->l = obidji(str,i);
        c->d = obidji(str,i);
    }
    return c;
}

void ispisi(string &stack, cvor *c){
    stack.push_back(c->c);
    if(isupper(c->c)){ //ako smo dosli do lista ispisujemo
        cout << stack << endl;
    }else{
        ispisi(stack,c->l); //inace prolazimo kako kroz levo tako kroz desno podstablo
        ispisi(stack,c->d);
    }
    stack.pop_back();
}

void brisi(cvor *c){
    if(c!=nullptr){
        brisi(c->l); //brisi levo podstablo pa desno pa potom ceo cvor
        brisi(c->d);
        delete(c);
    }
}

int main(){

    string str;
    cin >> str;
    int i=0; //indeks odakle krecemo sa nasim stringom
    cvor *c = obidji(str,i);
    string stack;
    ispisi(stack,c);

    return 0;
}
