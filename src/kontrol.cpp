#include "kontrol.hpp"
#include <cmath>

Kontrol::Kontrol()
{
    dengesizMi=false;
}

void Kontrol::DengeKontrol(IkiliAramaAgaci* ikiliaramaagaci,Doku* aktifDoku)
{
    if(aktifDoku)
    {
        DengeKontrol(ikiliaramaagaci,aktifDoku->sol);
        DengeKontrol(ikiliaramaagaci,aktifDoku->sag);
        if(abs(ikiliaramaagaci->Yukseklik(aktifDoku->sol)-ikiliaramaagaci->Yukseklik(aktifDoku->sag))>=2)
        {
            dengesizMi=true;
        }
    }
}