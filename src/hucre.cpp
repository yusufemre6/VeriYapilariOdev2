/** 
* @file hucre.cpp
* @description Hucre sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include "hucre.hpp"

Hucre::Hucre(int dnaUzunlugu)
{
    oncekiHucre=0;
    sonrakiHucre=0;
    this->dnaUzunlugu=dnaUzunlugu;
}

Hucre::~Hucre()
{
    
}