#ifndef hucre_hpp
#define hucre_hpp

class Hucre
{
	public:
		Hucre(int dnaUzunlugu);
		~Hucre();		
		Hucre* oncekiHucre;
		Hucre* sonrakiHucre;
		int dnaUzunlugu;
};

#endif