#include <iostream>
#include <vector>

#define M 1234567

int64_t sum(int64_t a, int64_t b){
    return ((a%M)+(b%M))%M;
}

int64_t product(int64_t a, int64_t b){
    return ((a%M)*(b%M))%M;
}

int64_t diff(int64_t a, int64_t b){
    return (M+(a%M)-(b%M))%M; //izvlacenje ostatka od negativnog rezultata
}

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int tezinskiZbir=0,uksum=0;
    for(int i=0; i<n; i++){
        uksum=sum(uksum,a[i]); //uksum += a[i];
        tezinskiZbir = sum(tezinskiZbir,product(i,a[i])); //tezinskiZbir += (i*a[i])
    }
    int64_t max  = tezinskiZbir; //baza
    //na pocetku maksimalna rotacija je 0 i maksimalni zbir je 0*a0+1*a1+...+(n-1)an-1
    //ind. korak;
    for(int i=1; i<n; i++){
        tezinskiZbir = sum(diff(tezinskiZbir,uksum),product(n,a[i-1])); //zi=zi-1-z+n*a[i-1]
        //tezinskizbir za tekuce i se azurira pa se kao zi-1 koristi tezinskizbir koji se izracunao pre novog i
        if(tezinskiZbir>max)
            max=tezinskiZbir;
    }
    cout << max << endl;
    return 0;
}
