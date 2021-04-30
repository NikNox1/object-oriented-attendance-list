#include "lista_obecnosci.hh"


osoba * zwieksz(osoba * tab, int &rozmiar)
{
	osoba * tmp;

	tmp = tworzenie_i_kopiowanie(tmp, tab, rozmiar, 0);
	tab = tworzenie_i_kopiowanie(tab, tmp, ++rozmiar, 1);

    return tab;
}

osoba * tworzenie_i_kopiowanie(osoba * tmp, osoba * tab, int rozmiar, int n) //nie zmieniamy N, wiec int
{
	tmp = new osoba[rozmiar];


	for (int i = 0; i < rozmiar-n; i++)
	{
			tmp[i]  = tab[i];
	}

    delete(tab);
    return tmp;
}



