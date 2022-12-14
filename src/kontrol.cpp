#include "kontrol.hpp"
#include <cmath>
#include <iostream>

Kontrol::Kontrol()
{
    dengesizMi=false;
    sayac=0;
    
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

void Kontrol::EkranaYazdirma(Organizma* organizma)
{
    Sistem* gec=organizma->ilkSistem;

    while(gec!=0)
    {
        for(int i=0;i<100;i++)
        {
            if(gec->organlar[i].ikiliaramaagaci!=0)
            {
                DengeKontrol(gec->organlar[i].ikiliaramaagaci,gec->organlar[i].ikiliaramaagaci->kok);
                if(dengesizMi==true)
                {
                   cout<<"#";
                }
                else    
                   cout<<" ";

                dengesizMi=false;    
            }
            else 
                break;
        }
        cout<<endl;

        gec=gec->sonrakiSistem;
    }
}

void Kontrol::Mutasyon(Organizma* organizma)
{
    Sistem* gec=organizma->ilkSistem;

    while(gec!=0)
    {
        for(int i=0;i<100;i++)
        {
            if(gec->organlar[i].ikiliaramaagaci!=0)
            {
                if(gec->organlar[i].ikiliaramaagaci->kok->ortaHucre->dnaUzunlugu%50==0)
                {   
                     HucreleriMutasyonaSokma(gec->organlar[i].ikiliaramaagaci->kok);

                     Dinamikdizi* dinamikDiziler=new Dinamikdizi[20];
                     PostOrderAl(dinamikDiziler,gec->organlar[i].ikiliaramaagaci->kok);

                     sayac=0;

                     yeniDokuDizisi=new Doku[20];
                     yeniAgac=new IkiliAramaAgaci();

                     for(int i=0;i<20;i++)
                     {   
                        int* dizi=dinamikDiziler[i].m_adres;
                        for(int j=0;j<dinamikDiziler[i].m_kullanilan;j++)
                        {
                            yeniDokuDizisi[i].HucreEkle(dizi[j],dinamikDiziler[i].m_kullanilan);
                        }
                        yeniAgac->Ekle(&yeniDokuDizisi[i],yeniAgac->kok);
                     }
                     //delete gec->organlar[i].ikiliaramaagaci;
                     gec->organlar[i].ikiliaramaagaci=yeniAgac;
                     delete[] dinamikDiziler;
                }
            }
            else
                break;
        }
        gec=gec->sonrakiSistem;
    }
}

void Kontrol::HucreleriMutasyonaSokma(Doku* aktifDoku)
{
    if(aktifDoku)
    {
        HucreleriMutasyonaSokma(aktifDoku->sol);
        HucreleriMutasyonaSokma(aktifDoku->sag);
        Hucre* gec=aktifDoku->ilkHucre;
        while(gec!=0)
        {
            if(gec->dnaUzunlugu%2==0)
            {
                gec->dnaUzunlugu=gec->dnaUzunlugu/2;
            }
            gec=gec->sonrakiHucre;
        }

    }
}

void Kontrol::PostOrderAl(Dinamikdizi* dD,Doku* aktifDoku)
{
    if(aktifDoku)
    {
        PostOrderAl(dD,aktifDoku->sol);
        PostOrderAl(dD,aktifDoku->sag);
        Hucre* gec=aktifDoku->ilkHucre;
        while(gec!=0)
        {
            dD[sayac].SayiEkle(gec->dnaUzunlugu);
            gec=gec->sonrakiHucre;
        }
        sayac++;
    }
}