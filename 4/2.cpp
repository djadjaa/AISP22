//kvadratna slozenost -> n puta radimo op slozenosti n; zato cemo samo linearnim prolaskom odrediti br pojavljivanja osoba

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> imena(n);
    for(int i=0; i<n; i++){ //n
        cin >> imena[i];
    }
    sort(begin(imena),end(imena)); //nlogn; po defaultu se poredi leksikografski

    int maxDuzina=1; //barem jedan glas za osobu
    int duzina=1; //duzina segmenata uzastopnih elem tj br pojavljivanja
    for(int i=1; i<n; i++){
        if(imena[i]==imena[i-1]){
            duzina++;
        }else{
            duzina=1;
        }
        maxDuzina = max(maxDuzina,duzina);
    }
    cout << maxDuzina << '\n';
    return 0;
}
