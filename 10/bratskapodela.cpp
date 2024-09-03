//1-uzima element, 0-ne uzima
/*
                                                []i=0 zbir1=0,zbir2=0;
                                                /\
                                        []zbir1=3.5   [3,5]i=1; zbir2=3.5
                                        /\              /\
                                    []     [1.7]i=2 [3.5] [3.5,1.7]i=2 itd
                                            /\
                                            [1.7,1.2]



fiksiramo prefiks niza elem koji smo odradili, kada dodjemo do i=4 i do lista, tada smo pronasli izbor i potom oduzimamo dva lista i trazimo minimalnu razliku po listovima
inkrementalno cemo racunati zbirove za jednog i drugog pri cemu su inicijalizovani na 0
ide prvo zbir1=zbir2=0
zatim u prvom nivou zbir1=0 zbir2=3.5 sa leve a sa desne zzbir1=3.5 zbir2=0
u drugom sa desne pa sa leve str zbir1=3.5zbir2=1.7 itd itd i posle radimo apsolutnu razliku ta dva zbira
u svakom podstablu radimo apsolutnu razliku i trazimo minimalnu
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
/*
double podele(vector<double>& p, int i, double z1, double z2){
    if(i==p.size()){
        return abs(z1-z2);
    }
    double min1=podele(p,i+1,z1+p[i],z2); //minimalna razlika ako dodamo prvom bratu elem
    double min2=podele(p,i+1,z1,z2+p[i]);
    return min(min1,min2);
}
*/
//DRUGI NACIN

double podele(vector<double>& p, int i, double z1, double z2,double z){
    if(i==p.size()){
        return abs(z1-z2);
    }
    if(z1+z<=z2)
        return z2-(z1+z);
    else if(z2+z<=z1)
        return z1-(z2+z);
    double min1=podele(p,i+1,z1+p[i],z2,z-p[i]);
    double min2=podele(p,i+1,z1,z2+p[i],z-p[i]);
    return min(min1,min2);
}
int main(){
    int n;
    cin >> n;
    vector<double>p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    cout << fixed << setprecision(2) << podele(p,0,0,0) << '\n'; //ispisujemo realne brojeve na odredjen fiksirani br decimala
    return 0;;
}
