/** 
* @file ikiliaramaagaci.hpp
* @description IkiliAramaAgaci sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/
#ifndef ikiliaramaagaci_hpp
#define ikiliaramaagaci_hpp

#include "hucre.hpp"
#include "doku.hpp"
#include <cmath>
#include <iostream>


class IkiliAramaAgaci
{   
   public:   
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();
    void Ekle(Doku* yeniDoku, Doku* aktifDoku);
    int Yukseklik(Doku* aktifDoku);
    void PostOrder(Doku* aktifDoku);
    Doku* kok;
    bool VarMi(int aranan,Doku* aktifDoku);
    bool DokuSil(Doku* &doku);
    int sayac;

   private:
    bool BosMu();
    void Temizle();
      
};
#endif