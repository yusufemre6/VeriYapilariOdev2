#ifndef agacdugum_hpp
#define agacdugum_hpp

#include "hucre.hpp"

using namespace std;

class AgacDugum
{   
    public:
        AgacDugum(Hucre* hucre);
        Hucre* hucre;
        AgacDugum* sol;
        AgacDugum* sag;
};

#endif