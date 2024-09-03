#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int64_t n;
    cin >> n;
    vector<double> sirine(n);
    for(int i=0; i<n; i++)
        cin >> sirine[i];

    vector<double> poluprecnici(n);
    poluprecnici[0] = sirine[0];
    for(int i=1; i<n; i++)
        poluprecnici[i]=poluprecnici[i-1]+sirine[i];

    int64_t m;
    double x,y;
    cin >> m;
    while(m--){
        cin >> x >> y;
        double dist=sqrt(x*x+y*y);
        auto it = lower_bound(begin(poluprecnici),end(poluprecnici),dist);
        if(it==end(poluprecnici))
            cout << "izvan\n";
        else
            cout << it-begin(poluprecnici) << '\n';
    }


    return 0;
}

/*
 3
2.0
3.0
7.0
poluprecnici[] = {2,5,12}
5
1.0 1.0
d=sqrt(2) < 2 -> 0
2.0 3.0
d=sqrt(13) < 5 -> 1
8.0 7.0
d=sqrt(113) < 12 -> 2
13.2 14.5
d=sqrt(169+196) -> izvan
0.0 12.0
d= sqrt(144) = 12 <= 12 -> 2
 */
