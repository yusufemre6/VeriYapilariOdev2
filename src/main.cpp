#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include "hucre.hpp"
#include "doku.hpp"
#include "dinamikdizi.hpp"
#include "radix.hpp"

using namespace std;

int main()
{
    ifstream dosyaOku;
	dosyaOku.open("Veri.txt");

    string satir;
    int dokuSayaci=20;

    Doku* organOlacakDokular;

    while(!dosyaOku.eof())
    {
        if(dokuSayaci==20)
        {
            dokuSayaci=0;
            organOlacakDokular=new Doku[20];
        }

        getline(dosyaOku,satir);
		int tmp;
		stringstream ss(satir);   
        
        Dinamikdizi* dinamikDizi=new Dinamikdizi();

        while(ss>>tmp)
        {
            dinamikDizi->SayiEkle(tmp);
        }

        Radix* radix=new Radix(dinamikDizi->m_adres,dinamikDizi->m_kullanilan);

        int* siraliSayilar=radix->sirala();

        delete radix;

        for(int i=0;i<dinamikDizi->m_kullanilan;i++)
        {
            organOlacakDokular[0].HucreEkle(siraliSayilar[i]);
        }

        delete dinamikDizi;

        // Hucre* gec=organOlacakDokular[dokuSayaci].ilkHucre;

        // while(gec!=0)
        // {
        //     cout<<setw(5)<<gec->dnaUzunlugu;
        //     gec=gec->sonrakiHucre;
        // }
        // cout<<endl;
        // cin>>tmp;

        dokuSayaci++;

        if(dokuSayaci==20)
        {
            
        }

    }
}