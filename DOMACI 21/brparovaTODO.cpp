#include <iostream>
#include <vector>

using namespace std;

int main(){

    int64_t n,d;
    cin >> n >> d;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    multiset<int64_t> s = a;
    int br=0;
    for(int i=0; i<n; i++){
        int64_t val = upper_bound(a[i]);


    }
    cout << br << endl;
    return 0;
}
//gruba sila
    /*
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(i<j && a[i]+3*a[j]<=d){
                br++;
            }
        }
    }
    +

    int val = (d-a[i])/3;
        for(int j=i+1; j<n; j++){
            if(a[j] <= val){
                br++;
            }
        }

    //slucaj kada je niz sortiran
    int i=0,j=n-1;
    while(i<j){
        if(a[i]+3*a[j]<=d){
            br += (j-i);
            j--;
        }
        else{
            i++;
        }
    }
    */
