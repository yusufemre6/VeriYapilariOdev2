/** 
* @file organ.hpp
* @description Organ sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef organ_hpp
#define organ_hpp

#include "hucre.hpp"
#include "doku.hpp"
#include "ikiliaramaagaci.hpp"
#include <iostream>

class Organ
{
    public:
        Organ();
        ~Organ();
        IkiliAramaAgaci* ikiliaramaagaci;
        void AgacEkle(IkiliAramaAgaci* ikiliaramaagaci);
};
#endif