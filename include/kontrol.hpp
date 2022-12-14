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
        IkiliAramaAgaci* yeniAgac;
        Dinamikdizi* dinamikDizi;
        Radix* radix;
        Doku* yeniDokuDizisi;
        void DengeKontrol(IkiliAramaAgaci* ikiliaramaagaci,Doku* aktifDoku);
        void EkranaYazdirma(Organizma* organizma);
        void Mutasyon(Organizma* organizma);
        void HucreleriMutasyonaSokma(Doku* aktifDoku);
        void PostOrderAl(Dinamikdizi* dD,Doku* aktifDoku);
        int sayac;
        
};
#endif