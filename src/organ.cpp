#include "organ.hpp"
#include <iostream>

using namespace std;

Organ::Organ()
{
    ikiliaramaagaci=0;
}

void Organ::AgacEkle(IkiliAramaAgaci* ikiliaramaagaci)
{
    this->ikiliaramaagaci=ikiliaramaagaci;
}