/** 
* @file organizma.hpp
* @description Organizma sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef organizma_hpp
#define organizma_hpp

#include "sistem.hpp"
#include "organ.hpp"
#include "doku.hpp"
#include "hucre.hpp"

class Organizma
{ 
    public:
    Organizma();
    ~Organizma();
    int sistemSayisi;
    Sistem* ilkSistem;
    void SistemEkle(Sistem* eklenecekSistem);     
};
#endif