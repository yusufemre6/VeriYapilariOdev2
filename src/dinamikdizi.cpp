#include "dinamikdizi.hpp"

Dinamikdizi::Dinamikdizi()
{
    m_boyut=15;
    m_adres=new int[m_boyut];
    m_kullanilan=0;
}

void Dinamikdizi:: SayiEkle(int eklenecekSayi)
{
    if(m_kullanilan>=m_boyut)
        Genislet(m_boyut);
    m_adres[m_kullanilan]=eklenecekSayi;
    m_kullanilan++;        
}

void Dinamikdizi::Genislet(int boyut)
{
    int* yeniAdres=new int[m_boyut+boyut];

    for(int i=0;i<m_kullanilan;i++)
        yeniAdres[i]=m_adres[i];

    delete[] m_adres;

    m_adres=yeniAdres;

    m_boyut+=boyut;    
} 

void Dinamikdizi::RadixYap()
{
    radix=new Radix(m_adres,m_kullanilan);
    int* sirali=radix->sirala();
    delete radix;
    delete m_adres;
    m_adres=sirali;
}

Dinamikdizi::~Dinamikdizi()
{
    delete[] m_adres;
}