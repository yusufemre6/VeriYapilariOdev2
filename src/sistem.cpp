/** 
* @file sistem.cpp
* @description Sistem sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include "sistem.hpp"

using namespace std;

Sistem::Sistem(Organ* organlar)
{
    this->organlar=organlar;
    oncekiSistem=0;
    sonrakiSistem=0;
}

Sistem::~Sistem()
{
    delete[] organlar;
}