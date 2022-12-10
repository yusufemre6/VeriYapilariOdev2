#ifndef dinamikdizi_hpp
#define dinamikdizi_hpp

class Dinamikdizi
{
    public:
        Dinamikdizi();
        ~Dinamikdizi();
        void SayiEkle(int eklenecekSayi);
        void Genislet(int boyut);
        int* m_adres;
        int m_boyut;
        int m_kullanilan;
};
#endif