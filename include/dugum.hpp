/** 
* @file dugum.hpp
* @description Dugum sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
    public:
        Dugum(int veri);
        int veri;
        Dugum* sonraki;
};

#endif