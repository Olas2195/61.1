#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Ciag{
	ifstream plik;
	ofstream plik2;
	vector <int> liczby;
	int dlugosc;
	int r1, r2, r3;
	int roznica;
	int liczba;
	bool zle;
	
	public:
		Ciag();
		~Ciag();
		void wczytaj();
		int szukajR();
		void sprawdz();
		void sprawdzDla1i2();
};

Ciag::Ciag() {
	plik.open("bledne.txt");
	plik2.open("wynik3.txt");
}

void Ciag::wczytaj() {
	if(plik.good()) {
		while(!plik.eof()) {
			plik>>dlugosc;
			for(int i=0; i<dlugosc; i++) {
				plik>>liczba;
				liczby.push_back(liczba);
			}
			roznica=this->szukajR();
			if(!zle){
				this->sprawdz();
			}else{
				this->sprawdzDla1i2();
			}
			liczby.clear();
		}
	}
}

int Ciag::szukajR() {
	zle=false;
	r1=liczby[1]-liczby[0];
	r2=liczby[2]-liczby[1];
	r3=liczby[dlugosc-1]-liczby[dlugosc-2];
	if(r1==r2){
		return r1;
	}else{
		if(r1==r3){
			return r1;
		}else{
			zle=true;
			return r3;
		}
	}
}

void Ciag::sprawdz() {
	int x=liczby[0];
	for(int i=1; i<dlugosc; i++) {
		x=x+roznica;
		if(liczby[i]!=x){
			plik2<<liczby[i]<<"\n";
			cout<<liczby[i]<<"\n";
			break;
		}
	}
}

void Ciag::sprawdzDla1i2() {
	if(liczby[2]-roznica!=liczby[1]){
		plik2<<liczby[1]<<"\n";
		cout<<liczby[1]<<"\n";
	}else{
		plik2<<liczby[0]<<"\n";
		cout<<liczby[0]<<"\n";
	}
}

Ciag::~Ciag() {
	plik.close();
	plik2.close();
}

int main(int argc, char** argv) {
	Ciag c;
	c.wczytaj();
	return 0;
}
