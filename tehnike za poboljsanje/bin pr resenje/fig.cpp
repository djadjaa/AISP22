#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int64_t minrazlikazakigraca(int k,int64_t n,vector<int64_t>&a,int64_t t){
    int64_t minRazlika=INT_MAX;
    for(int i=0; i+k-1<n; i++){
        minRazlika=min(minRazlika,k*(a[i+k-1]-a[i]));
        /*
        if(k*(a[i+k-1]-a[i])<=t){
            return true;
        }
        */
    }
    return minRazlika;
}
//radimo do k jer ako naidjemo na ktog igraca koji ne ispunjava uslov nece ni oni koji su >k, k nam je granica
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> fig(n);
    for(int i=0; i<n; i++){
        cin >> fig[i];
    }
    int64_t gr;
    cin >> gr;
    sort(begin(fig),end(fig));
    int64_t l=1, d=n, rez,raz;
    while(l<=d){
        int64_t s=l+(d-l)/2;
        int64_t minRazlika=minrazlikazakigraca(s,n,fig,gr);
        if(minRazlika<=gr){
            rez=s;
            raz=minRazlika;
            //vece resenje je bolje stoga:
            l=s+1;
        }else{
            d=s-1;
        }
    }
    cout << rez << ' ' << raz <<'\n';
    return 0;
}
