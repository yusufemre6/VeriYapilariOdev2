/** 
* @file hucre.hpp
* @description Hucre sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef hucre_hpp
#define hucre_hpp

class Hucre
{
	public:
		Hucre(int dnaUzunlugu);
		~Hucre();		
		Hucre* oncekiHucre;
		Hucre* sonrakiHucre;
		int dnaUzunlugu;
};

#endif