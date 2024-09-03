#include <iostream>
#include <vector>

using namespace std;
const double EPS = 0.00001;

/*
int brPodnizova(vector<double>& a, vector<double>& aSub, int n, double sum, int tempPos){
    if(n==0){
        double sumTemp=0.0;
        for(int i=0; i<tempPos; i++)
            sumTemp += aSub[i];
        if(sumTemp==sum)
            return 1;
        else
            return 0;//moze se desiti da podnizovi ne ispunjavaju zbir
    }else{
        int num=0;
        num += brPodnizova(a,aSub,n-1,sum,tempPos);
        aSub[tempPos] = a[n-1];
        num += brPodnizova(a,aSub,n-1,sum,tempPos+1);
    }
    return num;
}
*/

int brPodnizova(vector<double>&a, int tempPos, double sum){
    if(abs(sum)<EPS)
        return 1; //naisli smo na jedan podskup ciji je zbir jednak sum; to cemo proveriti dekrementiranjem sum-a u svakom rek poz i proveriti ga sa 0
    if(tempPos == a.size())
        return 0;
   // cout << sum-a[tempPos] << ' ' << a[tempPos] << ' ' << tempPos<< endl;
    return brPodnizova(a,tempPos+1,sum-a[tempPos])+brPodnizova(a,tempPos+1,sum);
    //povratna vr nam pokazuje da uklanjamo tekuci element iz niza time sto uvecavamo tekucu poziciju, prvi slucaj je kada se tekuci clan nalazi u podnizu, a drugi kada se ne nalazi
}

int main(){

    int n;
    cin >> n;
    vector<double> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    //vector<double> aSub(n);
    double sum;
    cin >> sum;

    cout << brPodnizova(a,0,sum) << endl;

    //cout << brPodnizova(a,aSub,n,sum,0) << endl;

    return 0;
}
