#ifndef organizma_hpp
#define organizma_hpp

#include "sistem.hpp"
#include "organ.hpp"
#include "doku.hpp"
#include "hucre.hpp"

class Organizma
{ 
    public:
    Organizma();
    ~Organizma();
    int sistemSayisi;
    Sistem* ilkSistem;
    void SistemEkle(Sistem* eklenecekSistem);     
};
#endif