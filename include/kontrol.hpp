#ifndef kontrol_hpp
#define kontrol_hpp

#include "ikiliaramaagaci.hpp"
#include "doku.hpp"

class Kontrol
{
    public:
        Kontrol();
        bool dengesizMi;
        void DengeKontrol(IkiliAramaAgaci* ikiliaramaagaci,Doku* aktifDoku);
};
#endif