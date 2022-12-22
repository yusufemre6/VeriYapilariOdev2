#ifndef organ_hpp
#define organ_hpp

#include "hucre.hpp"
#include "doku.hpp"
#include "ikiliaramaagaci.hpp"
#include <iostream>

class Organ
{
    public:
        Organ();
        ~Organ();
        IkiliAramaAgaci* ikiliaramaagaci;
        void AgacEkle(IkiliAramaAgaci* ikiliaramaagaci);
};
#endif