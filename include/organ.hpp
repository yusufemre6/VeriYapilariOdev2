#ifndef organ_hpp
#define organ_hpp

#include "hucre.hpp"
#include "doku.hpp"
#include "ikiliaramaagaci.hpp"

class Organ
{
    public:
        Organ();
        IkiliAramaAgaci* ikiliaramaagaci;
        void AgacEkle(IkiliAramaAgaci* ikiliaramaagaci);
};
#endif