#include "organizma.hpp"
#include "sistem.hpp"
#include "organ.hpp"
#include "doku.hpp"
#include "hucre.hpp"

using namespace std;

Organizma::Organizma()
{
    ilkSistem=0;
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
        gec->sonrakiHucre=eklenecekSistem;
        eklenecekSistem->oncekiSistem=gec;
    }
}