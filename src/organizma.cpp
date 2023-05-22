/** 
* @file organizma.cpp
* @description Organizma sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include "organizma.hpp"


using namespace std;

Organizma::Organizma()
{
    ilkSistem=0;
    sistemSayisi=0;
}

void Organizma:: SistemEkle(Sistem* eklenecekSistem)
{
    if(ilkSistem==0)
    {
        ilkSistem=eklenecekSistem;
    }
    else
    {
        Sistem* gec=ilkSistem;

        while(gec->sonrakiSistem!=0)
        {
            gec=gec->sonrakiSistem;
        }
        gec->sonrakiSistem=eklenecekSistem;
        eklenecekSistem->oncekiSistem=gec;
    }
}

Organizma::~Organizma()
{   
    Sistem* gec=ilkSistem;
    Sistem* silinecek;
    while(gec!=0)
    {
        silinecek=gec;
        gec=gec->sonrakiSistem;
        delete silinecek;
    }
}