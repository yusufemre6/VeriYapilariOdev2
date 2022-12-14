#ifndef doku_hpp
#define doku_hpp

#include "hucre.hpp"

using namespace std;

class Doku
{
	public:
		Doku();
		~Doku();
		void HucreEkle(int dnaUzunlugu,int satirdakiHucreSayisi);
		void DokuIciniTemizle();		
		Doku* sol;
		Doku* sag;
        int hucreSayisi;
		Hucre* ortaHucre;
        Hucre* ilkHucre;
};

#endif