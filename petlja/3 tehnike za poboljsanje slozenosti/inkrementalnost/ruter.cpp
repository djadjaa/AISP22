#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int64_t duzinaKabla=0,levo=0,desno=0;
    //prva zgrada
    for(int i=0; i<n; i++){
        duzinaKabla += i*a[i];
        desno += a[i];
    }
    //za prvu zgradu smo izračunali broj najmanjeg kabla za ruter
    int64_t minKabl=duzinaKabla;
    //razmatramo ostale zgrade
    for(int i=1; i<n; i++){
        levo+=a[i-1]; //do k
        desno-=a[i-1]; //od k+1 do n-1
        duzinaKabla+=levo-desno;
        if(duzinaKabla<minKabl)
            minKabl=duzinaKabla;
    }
    cout << minKabl << endl;

    return 0;
