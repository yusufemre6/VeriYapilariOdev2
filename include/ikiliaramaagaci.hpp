#ifndef ikiliaramaagaci_hpp
#define ikiliaramaagaci_hpp

#include "hucre.hpp"
#include "doku.hpp"
#include "agacdugum.hpp"

class IkiliAramaAgaci
{   
   public:   
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();
    void Ekle(Hucre* hucre, AgacDugum* aktifDugum);
    void Sil();
    int Yukseklik(AgacDugum* aktifDugum);
    void PostOrder(AgacDugum* aktifDugum); 
    AgacDugum* kok;
    bool VarMi(int aranan,AgacDugum* aktif); 
        
};
#endif