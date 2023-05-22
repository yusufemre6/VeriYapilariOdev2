/** 
* @file kontrol.hpp
* @description Kontrol sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#ifndef kontrol_hpp
#define kontrol_hpp

#include <iostream>
#include <iomanip>
#include<conio.h>
#include <cmath>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include "hucre.hpp"
#include "doku.hpp"
#include "organ.hpp"
#include "dinamikdizi.hpp"
#include "radix.hpp"
#include "ikiliaramaagaci.hpp"
#include "sistem.hpp"
#include "organizma.hpp"

class Kontrol
{
    public:
        Kontrol();
        bool dengesizMi;
        bool mutasyon;
        IkiliAramaAgaci* yeniAgac;
        Dinamikdizi* dinamikDiziler;
        int* siraliDiziler[20];
        Radix* radix;
        Doku* yeniDokuDizisi;
        void DengeKontrol(IkiliAramaAgaci* ikiliaramaagaci,Doku* aktifDoku);
        void EkranaYazdirma(Organizma* organizma);
        void Mutasyon(Organizma* organizma);
        void YeniAgacYap();
        void YeniDokuYap();
        void RadixYap();
        void AgaciDiziyeAl(IkiliAramaAgaci* agac);
        void HucreleriMutasyonaSokma();
        void PostOrderAl(Doku* aktifDoku);
        void OrganizmaOlustur(Organizma* organizma);
        int sayac;
        
};
#endif