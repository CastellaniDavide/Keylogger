#include <iostream>
#include <string>
#include <map>

#define MAXN 1000000
using namespace std;

map <unsigned  int,int> tot;
int digits[MAXN];

int main() {

    int N, K,i;
    unsigned  int nc,m;
    m=1;
    for (int i=1;i<K;i++)
		m*=10;      //m=10 alla k-1 m modulo per eliminare prima ifra
	nc=0;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> digits[i];



	for (i=0;i<K-1;i++){
		int cif=digits[i];
		nc=nc*10+cif;
    // insert your code here
	}

    for (; i < N; i++){
		int cif;
		cif=digits[i];
		nc=nc%m; // elimina cifra a sx
		nc=nc*10+cif;
		tot[nc]++;  // metti nella mappa
	}
	int ma=0;
    unsigned long  pin;

    for(auto const& it1 : tot) {
		if (it1.second > ma){
			ma=it1.second;
			pin=it1.first;
		}
    }
//    int pin = 1234;

    for (int i=0 ;i< K; i++) {
        cout << pin / m << " ";
        pin=pin % m;
        m=m/10;
    }
   cout << endl;
    return 0;
}
