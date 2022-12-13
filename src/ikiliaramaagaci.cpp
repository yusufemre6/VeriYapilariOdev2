#include "ikiliaramaagaci.hpp"
#include <cmath>
#include <iostream>

using namespace std;


IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok=0;
}

// bool IkiliAramaAgaci::VarMi(int aranan, AgacDugum* aktif)
// {
//     if(aktif->hucre->dnaUzunlugu<aranan)
//     { 
//         if(aktif->sag)
//             return VarMi(aranan,aktif->sag);

//         return false;    
//     }
//     else if(aktif->hucre->dnaUzunlugu>aranan)
//     {
//         if(aktif->sol)
//             return VarMi(aranan,aktif->sol);

//         return false;    
//     }
//     else 
//         return true;
// }

void IkiliAramaAgaci::Ekle(Doku* yeniDoku, Doku* aktifDoku)
{
    if(aktifDoku==0)
    {
        kok=yeniDoku;
    }
    else if((aktifDoku->ortaHucre->dnaUzunlugu)>=(yeniDoku->ortaHucre->dnaUzunlugu))
    {
        if(aktifDoku->sol)
            Ekle(yeniDoku,aktifDoku->sol);
        else
            aktifDoku->sol=yeniDoku;
    }
    else if((aktifDoku->ortaHucre->dnaUzunlugu)<(yeniDoku->ortaHucre->dnaUzunlugu))
    {
        if(aktifDoku->sag)
            Ekle(yeniDoku,aktifDoku->sag);
        else
            aktifDoku->sag=yeniDoku;
    }
}

int IkiliAramaAgaci::Yukseklik(Doku* aktifDoku)
{
    if(aktifDoku)
    {
        return 1+max(Yukseklik(aktifDoku->sol),Yukseklik(aktifDoku->sag));
    }
    return -1;
}

void IkiliAramaAgaci::PostOrder(Doku* aktifDoku)
{
    if(aktifDoku)
    {
        PostOrder(aktifDoku->sol);
        PostOrder(aktifDoku->sag);
        cout<<aktifDoku->ortaHucre->dnaUzunlugu<<"  ";
    }
}