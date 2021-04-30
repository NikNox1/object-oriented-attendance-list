#include "interfejs.hh"

void dodaj_studenta(osoba *_osoba)
{
    int obecnosc;
    while(1)
    {
        cout << "Podaj numer indeksu" << endl;
        cin >> _osoba->index;
        cout << "Czy student jest obecny? Wpisz 1 jezeli jest obecny" << endl;
        cout << "lub 0 jezeli jest nieobecny" << endl;
        cin >> _osoba->obecnosc;
        cout << "Podaj imie :" << endl;
        cin >> _osoba->imie;
        cout << "Podaj nazwisko :" << endl;
        cin >> _osoba->nazwisko;

        if ((_osoba->obecnosc == 1) || (_osoba->obecnosc == 0))
        {
            _osoba->obecnosc;
            return;
        }
        else
        {
            cout << "Miales podac 1 lub 0!" << endl;
        }
    }
}

void wyswietl_liste(osoba *_osoba,int n)
{
    for (int i = 0; i < n; i++ )
    {
        cout <<_osoba[i].imie<<" "<<_osoba[i].nazwisko<<" "<<_osoba[i].index<<" "<<_osoba[i].obecnosc<< endl;
    }
}



void sortowanie(osoba *_osoba, intopcja_sortowanie, int rozmiar)
{
    if(opcja_sortowanie == 0)
    {

        for(int i = 0; i < rozmiar; i++)
        {
            for(int j = 0; j < rozmiar - 1; j++)
            {
                if(_osoba[j].imie > _osoba[j+1].imie)
                {
                    swap(_osoba[j], _osoba[j+1]);

                }
            }
        }
    }
    else if(opcja_sortowanie == 1)
    {

        for(int i = 0; i < rozmiar; i++)
        {
            for(int j = 0; j < rozmiar - 1; j++)
            {
                if(_osoba[j].nazwisko > _osoba[j+1].nazwisko)
                {
                    swap(_osoba[j], _osoba[j+1]);

                }
            }
        }
    }
    else if(opcja_sortowanie == 2)
    {
        for(int i = 0; i < rozmiar; i++)
        {
            for(int j = 0; j < rozmiar - 1; j++)
            {
                if(_osoba[j].index > _osoba[j+1].index)
                {
                    swap(_osoba[j], _osoba[j+1]);

                }
            }
        }
    }
    else
    {
        cout<<"Miales podac liczbe z zakresu od 0 do 2!!!"<<endl;
    }
}


void interfejs( int &rozmiar, osoba * _osoba)
{
    int  opcja_menu;
    int i = 0, opcja_sortowanie;
    while(1)
    {
        cout << "MENU" << endl;
        cout << "----------------- " << endl;
        cout << "1. DODAJ STUDENTA" << endl;
        cout << "2. WYSWIETL LISTE OBECNOSCI" << endl;
        cout << "3. USUN LISTE" << endl;
        cout << "4. SORTOWANIE"<< endl;
        cout << "5. KONIEC PROGRAMU"<< endl;
        cin >> opcja_menu;
        cout << endl;

        switch (opcja_menu)
        {
        case 1 :
            cout << "DODAWANIE NOWEGO STUDENTA" << endl;
            cout << "----------------- " << endl;
            if ( i < rozmiar )
            {
                dodaj_studenta(&_osoba[i]);
                i++;
            }
            else
            {
                _osoba = zwieksz(_osoba, rozmiar);

                 dodaj_studenta(&_osoba[rozmiar-1]);
                i++;
            }
            break;

        case 2 :
            cout << "WYSWIETLANIE LISTY OBECNOSCI" << endl;
            cout << "----------------- " << endl;
            wyswietl_liste(_osoba, i);
            break;

        case 3 :
            cout << "USUWANIE LISTY" << endl;
            cout << "----------------- " << endl;
            delete [] _osoba;
            rozmiar = 0;
            i =0;
            break;

        case 4 :
            cout << "0 - IMIE, 1 - NAZWISKO, 2 - NUMER INDEKSU" << endl;
            cin >> opcja_sortowanie;
            sortowanie(_osoba, opcja_sortowanie, rozmiar);

            break;
        case 5:
            return;
            break;

        default:
            cout << "Nie znam takiej komendy!!!" << endl;
            break;
        }
    }
}

