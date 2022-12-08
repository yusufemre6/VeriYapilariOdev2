#include "kontrol.hpp"
#include "hucre.hpp"
#include "doku.hpp"
#include "organ.hpp"
#include<fstream>
#include<sstream>

void Kontrol::dosyaOkuma()
{
    ifstream dosyaOku;
	dosyaOku.open("Veri.txt");

    string satir;
    int dokuSayaci=0;

    Doku* dokuDizisi=new Doku[20];

    while(!dosyaOku.eof())
    {
        getline(dosyaOku,satir);
		int tmp;
		stringstream ss(satir);

        //Doku* doku=new Doku();
        while(ss>>tmp)
		{
            doku[dokuSayaci].HucreEkle(tmp);
	 	}

        dokuSayaci++;

        if(dokuSayaci==20)
        {
            dokuSayaci=0;
            organOlustur();
        }
    }
}

void Kontrol::organOlustur()
{

}
