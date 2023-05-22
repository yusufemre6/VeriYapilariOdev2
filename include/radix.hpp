/** 
* @file radix.hpp
* @description Radix sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef Radix_hpp
#define Radix_hpp
#include "Kuyruk.hpp"

class Radix
{
    public:
        Radix(int* sayilar,int adet);
        ~Radix();
        int* sirala();

    private:
        int     maxBasamakSayisiGetir();
        int     basamakSayisiGetir(int sayi);
        void    kuyruklariYazdir();
        void    kuyrukUzunluklariGetir(int* uzunluklar);
        Kuyruk** kuyruklar;
        int*    sayilar;
        int     sayiAdedi;
};

#endif