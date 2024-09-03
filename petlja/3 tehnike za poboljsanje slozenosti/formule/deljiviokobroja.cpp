#include <iostream>
using namespace std;

int main(){

    int64_t n,k;
    cin >> n >> k;
    int64_t najmanji,najveci;
    int64_t ost=n%k;
    if(ost==0){
        najmanji = najveci = n;
    }else{
        najmanji = n-ost;
        najveci = n+k-ost;
    }
    cout << najmanji << endl;
    cout << najveci << endl;
    return 0;
}
/*
odredićemo ostatak pri deljenju sa k. vidimo da najmanji možemo dobiti oduzimanjem broja n sa ostatkom kako bismo dobili najmanji broj deljiv sa k. što se tiče najvećeg, možemo sabrati n i k i kada ga budemo delili ponovo sa k, videćemo da je ostatak isti kao i kod n. stoga najveći dobijamo sabiranjem n i k i oduzimanjem ostatka i zasta dobijamo prvi najveći deljiv sa k
 */
