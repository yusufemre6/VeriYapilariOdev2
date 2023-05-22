/** 
* @file organ.cpp
* @description Organ sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include "organ.hpp"


using namespace std;

Organ::Organ()
{
    ikiliaramaagaci=0;
}

void Organ::AgacEkle(IkiliAramaAgaci* ikiliaramaagaci)
{
    this->ikiliaramaagaci=ikiliaramaagaci;
}

Organ::~Organ()
{
    delete ikiliaramaagaci;
}