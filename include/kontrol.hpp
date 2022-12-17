#ifndef kontrol_hpp
#define kontrol_hpp

#include "hucre.hpp"
#include "doku.hpp"
#include "organ.hpp"
#include "dinamikdizi.hpp"
#include "radix.hpp"
#include "ikiliaramaagaci.hpp"
#include "sistem.hpp"
#include "organizma.hpp"
#include "kontrol.hpp"

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
        int sayac;
        int sayac1;
        
};
#endif