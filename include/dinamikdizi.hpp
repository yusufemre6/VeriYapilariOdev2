#ifndef dinamikdizi_hpp
#define dinamikdizi_hpp
#include "radix.hpp"

class Dinamikdizi
{
    public:
        Dinamikdizi();
        ~Dinamikdizi();
        void SayiEkle(int eklenecekSayi);
        void Genislet(int boyut);
        void RadixYap();
        int* m_adres;
        int m_boyut;
        int m_kullanilan;
        Radix* radix;
};
#endif