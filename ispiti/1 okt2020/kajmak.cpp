/*
 * idemo kroz niz i sabiramo elemente sve dok ne postigne nosivost;
 * čim je prestigne/premaši, moramo oduzeti od tekuće sume elemente koji remete nosivost
 * sabiramo sve elemente od levog do desnog (pomeramo desni pokazivač) sve dok se ne premaši nosivost;
 * čim je prestigne, oduzimamo leve elemente (i pomeramo levi pokazivač)
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n,kg;
    cin >> n >> kg;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    /*GRUBA SILA
     for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += v[j];
            if (sum < kg)
                max_s = max(max_s, sum);
            else
                break;
        }
    }
     */
    int64_t tempSum=a[0],maxKg=tempSum;
    int64_t i=0;
    for(int j=1; j<n; j++){
        while(tempSum >= kg){
            tempSum -= a[i];
            i++;
        }
        maxKg = max(maxKg,tempSum);
        tempSum += a[j];
    }
    cout << maxKg << endl;
    return 0;
}
