/** 
* @file dinamikdizi.hpp
* @description Dinamik dizi sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef dinamikdizi_hpp
#define dinamikdizi_hpp
#include "radix.hpp"

class Dinamikdizi
{
    public:
        Dinamikdizi();
        ~Dinamikdizi();
        void SayiEkle(int eklenecekSayi);
        void Genislet(int boyut);
        int* m_adres;
        int m_boyut;
        int m_kullanilan;
};
#endif