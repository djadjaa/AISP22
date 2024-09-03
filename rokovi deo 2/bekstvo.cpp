#include <bits/stdc++.h>

using namespace std;

char suprotan(char c){
    switch(c){
        case 'D':
            return 'U';
        case 'U':
            return 'D';
        case 'R':
            return 'L';
        case 'L':
            return 'R';
    }
    return 0; //terminirajuća nula
}

int main(){

    string str;
    cin >> str;
    string stack; //nećemo koristiti pravi stek zbog ispisa (u suprotnom bi se ispisao rezultat u obrnutom poretku)
    for(char c:str){
        if(!stack.empty() && stack.back()==suprotan(c)){
            stack.pop_back(); //izbacujemo onaj koji pravi dvosmerni put
        }else{
            stack.push_back(c);
        }
    }
    cout << stack << endl;


    return 0;
}
