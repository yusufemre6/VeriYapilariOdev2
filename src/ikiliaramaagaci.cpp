#include "ikiliaramaagaci.hpp"
#include "agacdugum.hpp"
#include <cmath>
#include <iostream>

using namespace std;


IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok=0;
}

bool IkiliAramaAgaci::VarMi(int aranan, AgacDugum* aktif)
{
    if(aktif->hucre->dnaUzunlugu<aranan)
    { 
        if(aktif->sag)
            return VarMi(aranan,aktif->sag);

        return false;    
    }
    else if(aktif->hucre->dnaUzunlugu>aranan)
    {
        if(aktif->sol)
            return VarMi(aranan,aktif->sol);

        return false;    
    }
    else 
        return true;
}

void IkiliAramaAgaci::Ekle(Hucre* hucre, AgacDugum* aktifDugum)
{
    if(aktifDugum==0)
    {
        aktifDugum=new AgacDugum(hucre);
        kok=aktifDugum;
    }
    else if((aktifDugum->hucre->dnaUzunlugu)>=(hucre->dnaUzunlugu))
    {
        if(aktifDugum->sol)
            Ekle(hucre,aktifDugum->sol);
        else
            aktifDugum->sol=new AgacDugum(hucre);
    }
    else if((aktifDugum->hucre->dnaUzunlugu)<(hucre->dnaUzunlugu))
    {
        if(aktifDugum->sag)
            Ekle(hucre,aktifDugum->sag);
        else
            aktifDugum->sag=new AgacDugum(hucre);
    }
}

int IkiliAramaAgaci::Yukseklik(AgacDugum* aktifDugum)
{
    if(aktifDugum)
    {
        return 1+max(Yukseklik(aktifDugum->sol),Yukseklik(aktifDugum->sag));
    }
    return -1;
}

void IkiliAramaAgaci::PostOrder(AgacDugum* aktifDugum)
{
    if(aktifDugum)
    {
        PostOrder(aktifDugum->sol);
        PostOrder(aktifDugum->sag);
        cout<<aktifDugum->hucre->dnaUzunlugu<<"  ";
    }
}