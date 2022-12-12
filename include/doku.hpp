#ifndef doku_hpp
#define doku_hpp

#include "hucre.hpp"

using namespace std;

class Doku
{
	public:
		Doku();
		void HucreEkle(int dnaUzunlugu,int satirdakiHucreSayisi);		
		Doku* sol;
		Doku* sag;
        int hucreSayisi;
		Hucre* ortaHucre;
        Hucre* ilkHucre;
};

#endif