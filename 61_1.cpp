#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Ciag{
	ifstream plik;
	vector <int> liczby;
	int dlugosc;
	int max=0;
	int poprawnych=0;
	int roznica;
	int liczba;
	
	public:
		Ciag();
		~Ciag();
		void wczytaj();
		void wypisz();
		bool arytm();
};

Ciag::Ciag() {
	plik.open("ciagi.txt");
}

void Ciag::wczytaj() {
	if(plik.good()) {
		while(!plik.eof()) {
			plik>>dlugosc;
			for(int i=0; i<dlugosc; i++) {
				plik>>liczba;
				liczby.push_back(liczba);
			}
			if(this->arytm()) {
				poprawnych++;
				if(roznica>max) {
					max=roznica;
				}	
			}
			liczby.clear();
		}
	}
}

void Ciag::wypisz() {
	cout<<"Najwieksza roznica: "<<max<<"\n";
	cout<<"Ilosc poprawnych ciagow: "<<poprawnych;
}

bool Ciag::arytm() {
	roznica = liczby[1]-liczby[0];
	for(int i=0; i<dlugosc-1; i++) {
		if(liczby[i]+roznica!=liczby[i+1])
			return false;
	}
	return true;
}

Ciag::~Ciag() {
	plik.close();
}

int main(int argc, char** argv) {
	Ciag c;
	c.wczytaj();
	c.wypisz();
	return 0;
}
