#include "organizma.hpp"
#include "sistem.hpp"
#include "organ.hpp"
#include "doku.hpp"
#include "hucre.hpp"

using namespace std;

Organizma::Organizma()
{
    ilkSistem=0;
    sistemSayisi=0;
}

void Organizma:: SistemEkle(Sistem* eklenecekSistem)
{
    if(ilkSistem==0)
    {
        ilkSistem=eklenecekSistem;
    }
    else
    {
        Sistem* gec=ilkSistem;

        while(gec->sonrakiSistem!=0)
        {
            gec=gec->sonrakiSistem;
        }
        gec->sonrakiSistem=eklenecekSistem;
        eklenecekSistem->oncekiSistem=gec;
    }
}

Organizma::~Organizma()
{   
    Sistem* gec=ilkSistem;
    Sistem* silinecek;
    while(gec!=0)
    {
        silinecek=gec;
        gec=gec->sonrakiSistem;
        delete silinecek;
    }
}