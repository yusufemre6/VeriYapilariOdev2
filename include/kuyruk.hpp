/** 
* @file kuyruk.hpp
* @description Kuyruk sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "Dugum.hpp"
#include <iomanip>
#include<stdexcept>

using namespace std;

class Kuyruk
{
    public:
        Kuyruk();
        ~Kuyruk();
        void ekle(int veri);
        void cikar();
        bool bosmu();
        int getir();
        int elemanSayisiGetir();
        friend ostream& operator<<(ostream& os,Kuyruk& kuyruk);
    private:
        Dugum* 	ilk;
        Dugum*	son;
        int elemanSayisi;
    };

#endif