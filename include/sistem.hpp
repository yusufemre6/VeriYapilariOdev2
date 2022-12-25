/** 
* @file sistem.hpp
* @description Sistem sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef sistem_hpp
#define sistem_hpp

#include "organ.hpp"

class Sistem 
{
    public:
        Sistem(Organ* organlar);
        ~Sistem();
        Organ* organlar;
        Sistem* oncekiSistem;
        Sistem* sonrakiSistem;
};
#endif