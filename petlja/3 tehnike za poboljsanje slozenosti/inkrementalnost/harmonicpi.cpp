#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    double harmonic=0;
    for(int i=0; i<n; i++){
        harmonic += (pow((double)-1,(double)i))/(double)(2*i+1);
    }
    cout << setprecision(5) << fixed << harmonic*4 << endl;
    harmonic=0;
    for(int i=0; i<n; i++){
        harmonic += (pow((double)-1,(double)i))/(double)(2*i+1);
        cout << setprecision(5) << fixed << harmonic*4 << endl;
    }
    return 0;
}
