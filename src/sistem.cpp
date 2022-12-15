#include "sistem.hpp"

using namespace std;

Sistem::Sistem(Organ* organlar)
{
    this->organlar=organlar;
    oncekiSistem=0;
    sonrakiSistem=0;
}

Sistem::~Sistem()
{
    delete[] organlar;
}