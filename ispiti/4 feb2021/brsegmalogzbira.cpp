#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int64_t z;
    cin >> z;
    int64_t sum=0,i=0,brseg=0;
    for(int j=0; j<n; j++){
        sum += a[j];
        while(sum >= z){
            sum -= a[i];
            i++;
        }
        brseg += j-i+1; //broj elem između ona dva koja formiraju zbir manji od z, uključujući i ovaj poslednji
    }
    cout << brseg << endl;
    return 0;
}
