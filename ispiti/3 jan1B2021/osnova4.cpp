#include <bits/stdc++.h>

using namespace std;

void generisi(vector<int>& a, int num, int n){
    if(n==0){
        a.push_back(num);
        return;
    }
    for(int i=0; i<4; i++){
        //ako su im jedinice različite parnosti
        if(i>0 && ((num%10)%2 != i%2)){
            int val = num*10+i;
            generisi(a,val,n-1);
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<int> a;
    generisi(a,0,n);
    for(int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
    return 0;
}
