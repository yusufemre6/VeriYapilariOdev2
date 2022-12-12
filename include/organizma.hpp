#ifndef organizma_hpp
#define organizma_hpp

#include "sistem.hpp"

class Organizma
{ 
    public:
    Organizma();
    Sistem* ilkSistem;
    void SistemEkle(Sistem* eklenecekSistem);     
};
#endif