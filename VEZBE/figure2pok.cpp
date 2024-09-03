#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int64_t brFigurica;
    cin >> brFigurica;
    vector<int64_t> jacine(brFigurica);
    for(int i=0; i<brFigurica; i++){
        cin >> jacine[i];
    }
    sort(begin(jacine),end(jacine));
    int64_t granica;
    cin >> granica;
    int64_t j=0, rez=0, razl=0; //j ce nam biti k u slucaju binarne pretrage
    for(int64_t i=0; i<brFigurica; i++){
        while(((i-j+1)*(jacine[i]-jacine[j]))>granica){
            j++; //uvecavamo j kako bismo dosli do desne polovine
        }
        int64_t tempRazlika=(i-j+1)*(jacine[i]-jacine[j]);
        if(i-j+1>rez || (i-j+1==rez && tempRazlika<razl)){ //u slucaju da je isti br igraca kao u prethodnoj iteraciji provericemo da li je razlika zvanicna
            rez=i-j+1; //max br igraca
            razl=tempRazlika; //najmanja razlika tako da ne predje granicu
        }
    }
    cout << rez << " " << razl << '\n';
    return 0;
}
