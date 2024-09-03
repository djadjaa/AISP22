#include <iostream>
#include <climits>
using namespace std;

int main(){

    int64_t n;
    cin >> n;
    int64_t x,maxtemp=0,max=0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==1){
            maxtemp++;
        }else if(x==-1){
            if(maxtemp>max){
                max = maxtemp;
            }
            maxtemp=0; //odsecanje jer preskačemo poraze
        }
    }
    if(maxtemp>max){
        max = maxtemp;
    }
    cout << max << endl;
    return 0;
}
