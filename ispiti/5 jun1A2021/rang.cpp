//Ранг елемента x је број елемената из тог низа који су строго мањи од x.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    //sortiranje niza i pamćenje njihovih pozicija
    vector<int64_t> sortiran = a;
    sort(begin(sortiran),end(sortiran));
    for(auto x:a){
        //lower bound vraća prvi manji od x
        auto it = lower_bound(begin(sortiran),end(sortiran),x);
        cout << it-begin(sortiran) << ' '; //indeks
    }
    cout << endl;
    return 0;
}
/*
 a= 4 -20 8 4 6
 sortiran = 4 -20 8 4 6
 ==> -20 4 4 6 8
  x: (4 -20 8 4 6)
  it = 1(-20<4)
  it = 0(nema manjeg od -20)
  it = 4(-20,4,4 i 6 < 8)
  it = 1(4<=4)
  it = 3(-20, 4 4 < 6)
 */
