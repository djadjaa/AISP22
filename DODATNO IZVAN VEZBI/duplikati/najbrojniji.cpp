#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<string> imena(n);
    for(int i=0; i<n; i++){
        cin >> imena[i];
    }
    sort(begin(imena),end(imena));
    /*
    for(int i=0; i<n; i++){
        cout << imena[i] << " ";
    }*/
    int64_t maxglasovi=1,glasovi=1;
    for(int i=1; i<n; i++){
        if(imena[i]==imena[i-1])
            glasovi++;
        else
            glasovi=1;
        maxglasovi=max(maxglasovi,glasovi);
    }
    cout << maxglasovi << endl;
    return 0;
}
