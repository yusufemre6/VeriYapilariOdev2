#ifndef sistem_hpp
#define sistem_hpp

#include "organ.hpp"

class Sistem 
{
    public:
        Sistem(Organ* organlar);
        ~Sistem();
        Organ* organlar;
        Sistem* oncekiSistem;
        Sistem* sonrakiSistem;
};
#endif