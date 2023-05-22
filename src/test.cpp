/** 
* @file test.cpp
* @description Program başlatılınca çalışan main foksiyonun bulunduğu dosyadır.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 19.12.2022
* @author Yusuf Emre Yıldız , yusuf.yildiz8@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include "organizma.hpp"
#include "kontrol.hpp"

using namespace std;

int main()
{
    Organizma* organizma=new Organizma();//ana organizma
    
    Kontrol* kontrol=new Kontrol();

    kontrol->OrganizmaOlustur(organizma);
    
    kontrol->EkranaYazdirma(organizma);

    int input;
    input=getch();
    if(input==13)
    {
        system("cls");
        kontrol->Mutasyon(organizma);
        kontrol->EkranaYazdirma(organizma);
    }
}