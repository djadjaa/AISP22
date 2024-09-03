#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<int> dp(n,1); //složenost je kvadratna pa ćemo primeniti dinamičko programiranje u kom čuvamo rezultat na kraju niza
    int maxLenght = 1; //najmanja dužina proređenog niza je barem jedan element, bolje reći ovo je inicijalizacija zato što podniz morra imati barem 2 elem
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(abs(a[j]-a[i])>=d){
                dp[i] = max(dp[i],dp[j]+1);
                maxLenght = max(maxLenght,dp[i]);
            }
        }
    }
    cout << maxLenght << endl;

    return 0;
}
