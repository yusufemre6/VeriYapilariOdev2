#include "doku.hpp"
#include "hucre.hpp"

Doku::Doku()
{
    sol=0;
    sag=0;
	hucreSayisi=0;
    ilkHucre=0;
    ortadakiHucre=0;
}

//dokuya hücre ekleme fonksiyonu
 void Doku::HucreEkle(int dnaUzunlugu)
 {
     Hucre* yeniHucre= new Hucre(dnaUzunlugu);
     if(ilkHucre==0)
     {
         ilkHucre=yeniHucre;
     }
     else
     {
         Hucre* gecHucre= ilkHucre;
         while(gecHucre->sonrakiHucre!=0)
         {
             gecHucre=gecHucre->sonrakiHucre;
         }

         gecHucre->sonrakiHucre=yeniHucre;
         yeniHucre->oncekiHucre=gecHucre;
     }
	 hucreSayisi++;
 }