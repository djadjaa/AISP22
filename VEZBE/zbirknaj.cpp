#include <iostream>
#include <queue>
using namespace std;
int main(){

    int64_t n,k,x;
    cin >> n >> k;
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> najK;
    //prvo ispisujemo prvih k zadataka
    for(int i=0; i<k; i++){
        cin >> x;
        najK.push(x);
    } //svakako ce po odredjenom poretku da se sortiraju elementi, jer je u pitanju red sa prioritetom(dakle onaj koji je veci ici ce skroz dole ili gore i sl
    for(int i=k; i<n; i++){ //ispisujemo ostatak i poredimo ga sa ostalim elementima
        cin >> x;
        if(x>najK.top()){
            najK.pop();
            najK.push(x);
        }
    }
    int64_t z=0;
    while(!najK.empty()){
        cout << najK.top() << " ";
        z += najK.top();
        najK.pop();
    }
    cout << z << '\n';
    return 0;
}
