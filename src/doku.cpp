/** 
* @file doku.cpp
* @description Doku sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include "doku.hpp"

Doku::Doku()
{
    sol=0;
    sag=0;
	hucreSayisi=0;
    ilkHucre=0;
    ortaHucre=0;
}

Doku::~Doku()
{
    Hucre* gec=ilkHucre;
    while(gec!=0)
    {
        Hucre* silinecek=gec;
        gec=gec->sonrakiHucre;
        delete silinecek;
    }
}

//dokuya hücre ekleme fonksiyonu
 void Doku::HucreEkle(int dnaUzunlugu , int satirdakiHucreSayisi)
 {
     Hucre* yeniHucre= new Hucre(dnaUzunlugu);
     if(ilkHucre==0)
     {
         ilkHucre=yeniHucre;
     }
     else
     {
         Hucre* gecHucre= ilkHucre;
         while(gecHucre->sonrakiHucre!=0)
         {
             gecHucre=gecHucre->sonrakiHucre;
         }

         gecHucre->sonrakiHucre=yeniHucre;
         yeniHucre->oncekiHucre=gecHucre;
     }
	 hucreSayisi++;

      if(hucreSayisi==(satirdakiHucreSayisi/2+1))
         ortaHucre=yeniHucre;
 }
