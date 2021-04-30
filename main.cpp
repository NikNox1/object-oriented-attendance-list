#include<iostream>
#include"interfejs.hh"
#include <string>

int main()
{
    int rozmiar = 1;

    osoba *_osoba;

    _osoba = new osoba[rozmiar];

    interfejs(rozmiar, _osoba);

    return 0;
}
