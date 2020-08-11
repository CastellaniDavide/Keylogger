#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAXN 1000000

map <unsigned  int,int> tot;



map <unsigned  int,int>::iterator it;
int main() {

    int N, K;
    std::cin >> N >> K;
    unsigned  int nc,m;
    m=1;
    for (int i=1;i<K;i++)
		m*=10;      //m=10 alla k-1 m modulo per eliminare prima ifra
	nc=0;
	unsigned  int last[K];
	int ind=0;
	int i;
	for (i=0;i<K-1;i++){
		int cif;
		cin >> cif;
		nc=nc*10+cif;

	}
    for (; i < N; i++){
		int cif;
		cin >> cif;
		nc=nc%m; // elimina cifra a sx
		nc=nc*10+cif;

		tot[nc]++;  // metti nella mappa

//		ind=(ind+1)%(K-1);

	}
	int ma=0;
    unsigned long int pin;
    /*
    for (it=tot.begin();it!=tot.end();it++){
		//cout << it->first << " " << it->second << endl;
		if (it->second > ma){
			ma=it->second;
			pin=it->first;
		}
	}
*/

    for(auto const& it1 : tot) {
		if (it1.second > ma){
			ma=it1.second;
			pin=it1.first;
		}
    }

    for (int i=0 ;i< K; i++) {
        cout << pin / m << " ";
        pin=pin % m;
        m=m/10;
    }
   cout << endl;
/*
    // This prints the pin space separated.
    // ***Note: make sure that C++11 is enabled***
    std::string pin_string = std::to_string(pin);
    for (char& c : pin_string)
        std::cout << c << " ";
    std::cout << std::endl;
*/
    return 0;
}
