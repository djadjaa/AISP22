#include <iostream>
#include <iomanip> //doradjujemo izlaz
using namespace std;
int main(){

    //potrebni su nam broj dana, prvi dan i svaki dan koliko predju km
    ios_base::sync_with_stdio(false); cin.tie(0);
    int brDana, prviDan, svakiDan;
    cin >> brDana;
    while(cin >> prviDan >> svakiDan){
        int temp=prviDan, uk=prviDan;
        for(int i=1; i<brDana; i++){
            temp += svakiDan;
            uk += temp;
        }
        double rez = uk/1000.00;
        cout << fixed << setprecision(2) << showpoint << rez << '\n';
    }

    return 0;
}
