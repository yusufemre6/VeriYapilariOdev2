/** 
* @file doku.hpp
* @description Doku sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

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
		Doku* sol;
		Doku* sag;
        int hucreSayisi;
		Hucre* ortaHucre;
        Hucre* ilkHucre;
};

#endif