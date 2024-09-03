#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool provera(vector<int64_t>&armature,int64_t brPostArm, int64_t delovi, int64_t komadi){
    int64_t maxDuzinaStuba=0;
    for(int i=0; i<brPostArm; i++){
        maxDuzinaStuba += (armature[i]/delovi); //trazimo na koliko delova mozemo maksimalno da delimo postojece armature
    }
    return maxDuzinaStuba >= komadi;
}

int main(){

    int64_t brPostArm;
    cin >> brPostArm;
    vector<int64_t> armature(brPostArm);
    for(int i=0; i<brPostArm; i++){
        cin >> armature[i];
    }
    int64_t komadi;
    cin >> komadi;
    int64_t l=0, d=*max_element(begin(armature),end(armature)), rez;
    while(l<=d){
        int64_t s=(l+d)/2;
        if(provera(armature,brPostArm,s,komadi)){
            l=s+1;
            rez=s;
        }
        else{
            d=s-1;
        }
    }
    cout << rez << '\n';
    return 0;
}
