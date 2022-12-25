/** 
* @file kontrol.cpp
* @description Kontrol sınıfına ait fonksiyonlar ve değişkenler vardır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/


#include "kontrol.hpp"

Kontrol::Kontrol()
{
    dengesizMi=false;
    mutasyon=false;
    sayac=0;
}


void Kontrol::OrganizmaOlustur(Organizma* organizma)
{
    ifstream dosyaOku;
	dosyaOku.open("Veri.txt");
    string satir;

    int dokuSayaci=20;
    int organSayaci=100;
    
    Doku* organOlacakDokular;//20 tane kosulu oldugu icin 
    Organ* sistemOlacakOrganlar;//100 tane kosulu oldugu icin
    IkiliAramaAgaci* aramaAgaci;
    Dinamikdizi* dinamikDizi;

    while(!dosyaOku.eof())
    {
        if(dokuSayaci==20)//baslangicta 20 tane doku aciyorum ve her 20 satır dokulara eklenince yeni 20 tane doku acilacak.
        {
            dokuSayaci=0;
            organOlacakDokular=new Doku[20];
        }

        getline(dosyaOku,satir);
		int tmp;
		stringstream ss(satir);   
        
        dinamikDizi=new Dinamikdizi();

        while(ss>>tmp)//satirdaki sayilari dinamik diziye aliyorum.
        {
            dinamikDizi->SayiEkle(tmp);
        }

        Radix* radix=new Radix(dinamikDizi->m_adres,dinamikDizi->m_kullanilan);//dinamik diziyi artan sekilde siraliyorum

        int* siraliSayilar=radix->sirala();//sirali sayilar dizisi tutan pointer

        delete radix;

        for(int i=0;i<dinamikDizi->m_kullanilan;i++)// sirali diziyi dokuya eklemek icin
        {
            organOlacakDokular[dokuSayaci].HucreEkle(siraliSayilar[i],dinamikDizi->m_kullanilan);
        }

        delete dinamikDizi;
        delete[] siraliSayilar;

        dokuSayaci++;

        if(dokuSayaci==20)//20 tane doku olunca organ yapmak icin 
        {
         
            if(organSayaci==100)
            {   
                organSayaci=0;
                sistemOlacakOrganlar=new Organ[100];
            }

            aramaAgaci=new IkiliAramaAgaci();

            for(int i=0;i<20;i++)//dokular orta hucresinden agaca ekleniyor
            {
                aramaAgaci->Ekle(&organOlacakDokular[i],aramaAgaci->kok);
            }

            sistemOlacakOrganlar[organSayaci].AgacEkle(aramaAgaci);//agac organa ekleniyor
            
            organSayaci++;

            if(organSayaci==100)//100 tane olan organi sistem yapip organizmaya baglıyorum
            {
                Sistem* sistem=new Sistem(sistemOlacakOrganlar);
                organizma->SistemEkle(sistem);
                organizma->sistemSayisi+=1;
            }
        }
    }

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
    if(mutasyon==true)
        cout<<setw(44)<<"ORGANIZMA (MUTASYONA UGRADI)"<<endl;
    else
        cout<<setw(25)<<"ORGANIZMA"<<endl;
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
    mutasyon=true;
    Sistem* gec=organizma->ilkSistem;

    while(gec!=0)
    {
        for(int i=0;i<100;i++)
        {
            if(gec->organlar[i].ikiliaramaagaci!=0)
            {
                if(gec->organlar[i].ikiliaramaagaci->kok->ortaHucre->dnaUzunlugu%50==0)
                {   
                   AgaciDiziyeAl(gec->organlar[i].ikiliaramaagaci);
                   HucreleriMutasyonaSokma();
                   RadixYap();
                   YeniDokuYap();
                   YeniAgacYap();
                   delete[] dinamikDiziler;
                   sayac=0;
                   gec->organlar[i].ikiliaramaagaci=yeniAgac;
                }
            }
            else
                break;
        }
        gec=gec->sonrakiSistem;
    }
}

void Kontrol::YeniAgacYap()
{
    yeniAgac=new IkiliAramaAgaci();
    for(int i=0;i<20;i++)
    {
        yeniAgac->Ekle(&yeniDokuDizisi[i],yeniAgac->kok);
    }
}

void Kontrol::YeniDokuYap()
{
    yeniDokuDizisi=new Doku[20];

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<dinamikDiziler[i].m_kullanilan;j++)
        {
            yeniDokuDizisi[i].HucreEkle(siraliDiziler[i][j],dinamikDiziler[i].m_kullanilan);
        }
    }
}

void Kontrol::RadixYap()
{
      for(int i=0;i<20;i++)
       {
           radix=new Radix(dinamikDiziler[i].m_adres,dinamikDiziler[i].m_kullanilan);
           siraliDiziler[i]=radix->sirala();
           delete radix; 
       }
}

void Kontrol::HucreleriMutasyonaSokma()
{
       for(int i=0;i<20;i++)
       {
                for(int j=0;j<dinamikDiziler[i].m_kullanilan;j++)
                {
                    if(dinamikDiziler[i].m_adres[j]%2==0)
                    {
                        dinamikDiziler[i].m_adres[j]/=2;
                    }
                }        
       }
       
}

void Kontrol::PostOrderAl(Doku* aktifDoku)
{
    if(aktifDoku)
    {
        PostOrderAl(aktifDoku->sol);
        PostOrderAl(aktifDoku->sag);
        Hucre* gec=aktifDoku->ilkHucre;
        while(gec!=0)
        {
            dinamikDiziler[sayac].SayiEkle(gec->dnaUzunlugu);
            gec=gec->sonrakiHucre;
        }
        sayac++;
    }
}

void Kontrol::AgaciDiziyeAl(IkiliAramaAgaci* agac)
{
    dinamikDiziler=new Dinamikdizi[20];
    PostOrderAl(agac->kok);
}