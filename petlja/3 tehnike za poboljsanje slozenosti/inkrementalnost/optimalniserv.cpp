#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    int64_t uk=0;
    vector<int64_t> km(n);
    for(int i=0; i<n; i++){
        cin >> km[i];
        uk += km[i];
    }
    int64_t minRazl=INT_MAX,preServ=0,postServ=uk,razl,dan;
    for(int i=0; i<n; i++){
        preServ += km[i];
        postServ-= km[i];
        razl=abs(preServ-postServ);
        if(razl<minRazl){
            minRazl=razl;
            dan=i;
        }
    }
    cout << dan << endl;
    return 0;
}
