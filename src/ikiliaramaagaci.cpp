/** 
* @file ikiliaramaagaci.cpp
* @description IkiliAramaAgaci sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include "ikiliaramaagaci.hpp"
#include <cmath>
#include <iostream>

using namespace std;


IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok=0;
    sayac=0;
}

IkiliAramaAgaci::~IkiliAramaAgaci()
{
    Temizle();
}

void IkiliAramaAgaci::Temizle()
{
    while(!BosMu())
    {
        DokuSil(kok);
    }
}

bool IkiliAramaAgaci::DokuSil(Doku* &doku)
{
    Doku* silinecekDoku=doku;

    if(doku->sag==0) doku=doku->sol;
    else if(doku->sol==0)doku=doku->sag;
    else
    {
        silinecekDoku = doku->sol;
		Doku *ebeveyn = doku;
		while(silinecekDoku->sag != 0){
			ebeveyn = silinecekDoku;
			silinecekDoku = silinecekDoku->sag;
		}
		doku->ortaHucre->dnaUzunlugu = silinecekDoku->ortaHucre->dnaUzunlugu;
		if(ebeveyn == doku) doku->sol = silinecekDoku->sol;
		else ebeveyn->sag = silinecekDoku->sol;
    }
    delete silinecekDoku;
	return true;
}

bool IkiliAramaAgaci::VarMi(int aranan, Doku* aktifDoku)
{
    if(aktifDoku->ortaHucre->dnaUzunlugu<aranan)
    { 
        if(aktifDoku->sag)
            return VarMi(aranan,aktifDoku->sag);

        return false;    
    }
    else if(aktifDoku->ortaHucre->dnaUzunlugu>aranan)
    {
        if(aktifDoku->sol)
            return VarMi(aranan,aktifDoku->sol);

        return false;    
    }
    else 
        return true;
}

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
        Hucre* gec=aktifDoku->ilkHucre;
        while(gec!=0)
        {
            cout<<gec->dnaUzunlugu<<" ";
            gec=gec->sonrakiHucre;
        }
        cout<<endl;
    }
}

bool IkiliAramaAgaci::BosMu()
{
    return kok==0;
}