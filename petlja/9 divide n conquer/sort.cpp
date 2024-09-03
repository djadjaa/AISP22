#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergesort(vector<int64_t>& a, int64_t l, int64_t d, vector<int64_t>& tmp){
    if(l>=d)
        return;
    else{
        int s=l+(d-l)/2;
        mergesort(a,l,s,tmp); //leva polovina
        mergesort(a,s+1,d,tmp); //desna polovina
        int64_t i=l, j=s+1, k=0; //k je indeks koji prolazi kroz tmp niz
        while(i<=s && j<=d){
            if(a[i] < a[j])
                tmp[k++] = a[i++];
            else
                tmp[k++] = a[j++];
        }
        //prepisivanje leve pa desne polovine niza
        while(i<=s)
            tmp[k++]=a[i++];
        while(j<=d)
            tmp[k++]=a[j++];
        //prepisivanje iz tmp u orig
        for(k=0, i=l; i<=d; k++, i++)
            a[i] = tmp[k];
    }
}

int main(){

    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int64_t> tmp(n);
    mergesort(a,0,n-1,tmp);
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
