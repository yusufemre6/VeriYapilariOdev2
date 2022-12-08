#include "doku.hpp"
#include "hucre.hpp"

Doku::Doku()
{
    sol=0;
    sag=0;
    ortadakiHucre=0;
    ilkHucre=0;
}

// void Doku::hucreEkle(int hucreVeri)
// {
//     Hucre* yeniHucre= new SatirDugum(hucreVeri);
//     if(ilkHucre==0)
//     {
//         ilkHucre=yeniHucre;
//     }
//     else
//     {
//         Hucre* gecHucre= ilkHucre;
//         while(gecHucre->sonrakiHucre!=0)
//         {
//             gecHucre=gecHucre->sonrakiHucre;
//         }

//         gecHucre->sonrakiHucre=yeniHucre;
//         yeniHucre->oncekiHucre=gecHucre;
//     }
// }