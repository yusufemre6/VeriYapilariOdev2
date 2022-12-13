#ifndef ikiliaramaagaci_hpp
#define ikiliaramaagaci_hpp

#include "hucre.hpp"
#include "doku.hpp"


class IkiliAramaAgaci
{   
   public:   
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();
    void Ekle(Doku* yeniDoku, Doku* aktifDoku);
    //void Sil();
    int Yukseklik(Doku* aktifDoku);
    void PostOrder(Doku* aktifDoku); 
    Doku* kok;
    //bool VarMi(int aranan,AgacDugum* aktif); 
        
};
#endif