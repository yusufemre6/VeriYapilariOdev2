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
    int Yukseklik(Doku* aktifDoku);
    void PostOrder(Doku* aktifDoku);
    Doku* kok;
    bool VarMi(int aranan,Doku* aktifDoku);
    bool DokuSil(Doku* &doku);
    int sayac;

   private:
    bool BosMu();
    void Temizle();
      
        
};
#endif