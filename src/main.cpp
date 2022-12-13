#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include "hucre.hpp"
#include "doku.hpp"
#include "organ.hpp"
#include "dinamikdizi.hpp"
#include "radix.hpp"
#include "ikiliaramaagaci.hpp"
#include "sistem.hpp"
#include "organizma.hpp"
#include "kontrol.hpp"

using namespace std;

int main()
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

    Organizma* organizma=new Organizma();//ana organizma
    
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

    Kontrol* kontrol=new Kontrol();

    Sistem* gec=organizma->ilkSistem;

    while(gec!=0)
    {
        for(int i=0;i<100;i++)
        {
            if(gec->organlar[i].ikiliaramaagaci!=0)
            {
                kontrol->DengeKontrol(gec->organlar[i].ikiliaramaagaci,gec->organlar[i].ikiliaramaagaci->kok);
                if(kontrol->dengesizMi==true)
                {
                   cout<<"#";
                }
                else    
                   cout<<" ";

                kontrol->dengesizMi=false;    
            }
            else 
                break;
        }
        cout<<endl;

        gec=gec->sonrakiSistem;
    }
}