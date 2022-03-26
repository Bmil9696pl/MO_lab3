#include <iostream>
#include <cmath>

double funkcja_1(double x){
    double sinus = 1.0;

    sinus = sin(x / 4.0);

    return sinus * sinus - x;
}

double poch_1(double x){
    return (1.0/4.0) * (sin(x/2.0)) - 1.0;
}

double fi_1(double x){
    double sinus = 1.0;

    sinus = sin(x / 4.0);

    return sinus * sinus;
}

double poch_fi_1(double x){
    return 0.25*sin(x/2.0);
}

double funkcja_2(double x){
    return tan(2.0*x) - x - 1.0;
};

double poch_2(double x){
    return -1.0 + 2.0 / (cos(2.0 * x) * cos(2.0*x));
}

double fi_2(double x){
    return tan(2.0 * x) - 1.0;
}

double poch_fi_2(double x){
    double cosinus = 1.0;

    cosinus = cos(2.0 * x);

    return 2.0 / (cosinus * cosinus);
}

/**
 * @brief funkcja przybliza pierwiastek funkcji pierwszej przy uzyciu metody Picarda
 * @param x - x startowe, od ktorego zaczynamy iterowac
 * @param maxIt - maksymalna liczba iteracji
 * @param tolX - tolerowana wartosc estymatora
 * @param tolF - tolerowana wartosc residuum
 * @return -1 - funkcja zakonczyla sie niepowodzeniem
 * @return 0 - funkcja zakonczyla sie powodzeniem
 */
int picard_1(double x, int maxIt, double tolX, double tolF){
    // sprawdzenie kryterium zbieznosci
    if(fabs(poch_fi_1(x)) >= 1.0){
        std::cout << "Funkcja rozbiezna" << std::endl;
        return -1;
    }

    double estymator = 0.0, residuum = 0.0, przyblizenie = x;
    int i = 1;
    bool kont = true;


    std::cout << "Iteracja\t Wartosc przyblizona\t\t residuum\t\t\t estymator bledu\n";

    while(kont){
        std::cout << i << "\t";
        // obliczenie przyblizenia
        przyblizenie = fi_1(przyblizenie);
        std::cout << przyblizenie << "\t\t";

        estymator = fabs(przyblizenie - x);

        x = przyblizenie;
        residuum = funkcja_1(x);

        std::cout << residuum << "\t\t" << estymator << std::endl;

        if(abs(residuum) <= tolF && estymator <= tolX || i>=maxIt)
            kont = false;

        i++;
    }
    return 0;
}

/**
 * @brief funkcja przybliza pierwiastek funkcji drugiej przy uzyciu metody Picarda
 * @param x - x startowe, od ktorego zaczynamy iterowac
 * @param maxIt - maksymalna liczba iteracji
 * @param tolX - tolerowana wartosc estymatora
 * @param tolF - tolerowana wartosc residuum
 * @return -1 - funkcja zakonczyla sie niepowodzeniem
 * @return 0 - funkcja zakonczyla sie powodzeniem
 */
int picard_2(double x, int maxIt, double tolX, double tolF){
    // sprawdzenie kryterium zbieznosci
    if(fabs(poch_fi_2(x)) >= 1.0){
        std::cout << "Funkcja rozbiezna" << std::endl;
        return -1;
    }

    double estymator = 0.0, residuum = 0.0, przyblizenie = x;
    int i = 1;
    bool kont = true;


    std::cout << "Iteracja\t Wartosc przyblizona\t\t residuum\t\t\t estymator bledu\n";

    while(kont){
        std::cout << i << "\t";
        // obliczenie przyblizenia
        przyblizenie = fi_2(przyblizenie);
        std::cout << przyblizenie << "\t\t";

        estymator = fabs(przyblizenie - x);

        x = przyblizenie;
        residuum = funkcja_2(x);

        std::cout << residuum << "\t\t" << estymator << std::endl;

        if(abs(residuum) <= tolF && estymator <= tolX || i>=maxIt)
            kont = false;

        i++;
    }
    return 0;
}

/**
 * @brief funkcja przybliza pierwiastek funkcji pierwszej przy uzyciu metody bisekcji
 * @param a poczatek przedzialu
 * @param b koniec przedzialu
 * @param maxIt maksymalna liczba iteracji
 * @param tolX tolerowana wartosc esymatora
 * @param tolF tolerowana wartosc residuum
 * @return -1 - w przypadku niepowodzenia
 * @return 0 - w przypadku powodzenia
 */
int bisekcja_1(double a, double b, int maxIt, double tolX, double tolF){
    // sprawdzenie czy f(a) i f(b) są roznych znakow
    if (funkcja_1(a)* funkcja_1(b) > 0){
        std::cout << "Funkcja nie zmienia znaku w podanym przedziale" << std::endl;
        return -1;
    }

    double estymator = 0.0, residuum = 0.0, x = 0.0;
    int i = 1;
    bool kont = true;

    std::cout << "Iteracja\t\t a\t\t b\t\t x\t\t residuum\t\t estymator bledu" << std::endl;

    while(kont){
        // obliczenie srodka przedzialu
        x = (a+b)/2.0;
        estymator = fabs((b-a)/2.0);
        residuum = funkcja_1(x);

        std::cout << i << "\t\t" << a << "\t\t" << b << "\t\t" << x << "\t\t" << residuum << "\t\t" << estymator << std::endl;

        // wybor nowego pkt skrajnego
        if(funkcja_1(a)<0 && funkcja_1(x)>0 || funkcja_1(a)>0 && funkcja_1(x)<0)
            b = x;
        else
            a = x;

        if(fabs(residuum) <= tolF && estymator <= tolX || i >= maxIt)
            kont = false;

        i++;
    }

    return 0;
}

/**
 * @brief funkcja przybliza pierwiastek funkcji drugiej przy uzyciu metody bisekcji
 * @param a poczatek przedzialu
 * @param b koniec przedzialu
 * @param maxIt maksymalna liczba iteracji
 * @param tolX tolerowana wartosc esymatora
 * @param tolF tolerowana wartosc residuum
 * @return -1 - w przypadku niepowodzenia
 * @return 0 - w przypadku powodzenia
 */
int bisekcja_2(double a, double b, int maxIt, double tolX, double tolF){
    // sprawdzenie czy f(a) i f(b) są roznych znakow
    if (funkcja_2(a)* funkcja_2(b) > 0){
        std::cout << "Funkcja nie zmienia znaku w podanym przedziale" << std::endl;
        return -1;
    }

    double estymator = 0.0, residuum = 0.0, x = 0.0;
    int i = 1;
    bool kont = true;

    std::cout << "Iteracja\t\t a\t\t b\t\t x\t\t residuum\t\t estymator bledu" << std::endl;

    while(kont){
        // obliczenie srodka przedzialu
        x = (a+b)/2.0;
        estymator = fabs((b-a)/2.0);
        residuum = funkcja_2(x);

        std::cout << i << "\t\t" << a << "\t\t" << b << "\t\t" << x << "\t\t" << residuum << "\t\t" << estymator << std::endl;

        // wybor nowego pkt skrajnego
        if(funkcja_2(a)<0 && funkcja_2(x)>0 || funkcja_2(a)>0 && funkcja_2(x)<0)
            b = x;
        else
            a = x;

        if(fabs(residuum) <= tolF && estymator <= tolX || i >= maxIt)
            kont = false;

        i++;
    }

    return 0;
}

/**
 * @brief przybliza pierwiastek pierwszej funkcji metoda Newtona
 * @param x - x0 od ktorego zaczynam iterowac
 * @param maxIt - maksymalna liczba iteracji
 * @param tolX - tolerowana wartosc estymatora
 * @param tolF - tolerowana wartosc residuum
 * @return -1 - w przypadku niepowodzenia
 * @return 0 - w przypadku powodzenia
 */
int newton_1(double x, int maxIt, double tolX, double tolF){
    double x0 = x, x1 = 0.0, estymator = 0.0, residuum = 0.0;
    int i = 0;
    bool kont = true;

    std::cout << "Iteracja\t\t x1\t\t\t residuum\t\t estymator" << std::endl;

    while(kont){
        // obliczanie x1
        x1 = x0 - (funkcja_1(x0)/ poch_1(x0));
        estymator = fabs(x0-x1);
        x0 = x1;
        residuum = funkcja_1(x0);

        std::cout << i << "\t\t" << x1 << "\t\t\t" << residuum << "\t\t" << estymator << std::endl;

        if(fabs(residuum) <= tolF && estymator <= tolX || i >= maxIt)
            kont = false;

        i++;
    }

    return 0;
}

/**
 * @brief przybliza pierwiastek drugiej funkcji metoda Newtona
 * @param x - x0 od ktorego zaczynam iterowac
 * @param maxIt - maksymalna liczba iteracji
 * @param tolX - tolerowana wartosc estymatora
 * @param tolF - tolerowana wartosc residuum
 * @return -1 - w przypadku niepowodzenia
 * @return 0 - w przypadku powodzenia
 */
int newton_2(double x, int maxIt, double tolX, double tolF){
    double x0 = x, x1 = 0.0, estymator = 0.0, residuum = 0.0;
    int i = 0;
    bool kont = true;

    std::cout << "Iteracja\t\t x1\t\t\t residuum\t\t estymator" << std::endl;

    while(kont){
        // obliczanie x1
        x1 = x0 - (funkcja_2(x0)/ poch_2(x0));
        estymator = fabs(x0-x1);
        x0 = x1;
        residuum = funkcja_2(x0);

        std::cout << i << "\t\t" << x1 << "\t\t\t" << residuum << "\t\t" << estymator << std::endl;

        if(fabs(residuum) <= tolF && estymator <= tolX || i >= maxIt)
            kont = false;

        i++;
    }

    return 0;
}

/**
 * @brief przybliza pierwiastek funkcji pierwszej metoda siecznych
 * @param x0 - punkt startowy
 * @param x1 - x0 + delta
 * @param maxIt - maksymalna liczba iteracji
 * @param tolX - tolerowana wartosc estymatora
 * @param tolF - tolerowana wartosc residuum
 * @return -1 - w przypadu niepowodzenia
 * @return 0 - w przypadu powodzenia
 */
int sieczne_1(double x0, double x1, int maxIt, double tolX, double tolF){
    double x2 = 0.0, estymator = 0.0, residuum = 0.0;
    int i = 0;
    bool kont = true;

    std::cout << "Iteracja\t\t x1\t\t\t residuum\t\t estymator" << std::endl;

    while (kont){
        x2 = x1 - funkcja_1(x1) / ((funkcja_1(x1) - funkcja_1(x0)) / (x1 - x0));
        estymator = fabs(x2-x1);
        residuum = funkcja_1(x2);

        std::cout << i << "\t\t" << x1 << "\t\t\t" << residuum << "\t\t" << estymator << std::endl;

        x0 = x1;
        x1 = x2;

        if(fabs(residuum) <= tolF && estymator <= tolX || i >= maxIt)
            kont = false;

        i++;
    }

    return 0;
}

/**
 * @brief przybliza pierwiastek funkcji drugiej metoda siecznych
 * @param x0 - punkt startowy
 * @param x1 - x0 + delta
 * @param maxIt - maksymalna liczba iteracji
 * @param tolX - tolerowana wartosc estymatora
 * @param tolF - tolerowana wartosc residuum
 * @return -1 - w przypadu niepowodzenia
 * @return 0 - w przypadu powodzenia
 */
int sieczne_2(double x0, double x1, int maxIt, double tolX, double tolF){
    double x2 = 0.0, estymator = 0.0, residuum = 0.0;
    int i = 0;
    bool kont = true;

    std::cout << "Iteracja\t\t x1\t\t\t residuum\t\t estymator" << std::endl;

    while (kont){
        x2 = x1 - funkcja_2(x1) / ((funkcja_2(x1) - funkcja_2(x0)) / (x1 - x0));
        estymator = fabs(x2-x1);
        residuum = funkcja_2(x2);

        std::cout << i << "\t\t" << x1 << "\t\t\t" << residuum << "\t\t" << estymator << std::endl;

        x0 = x1;
        x1 = x2;

        if(fabs(residuum) <= tolF && estymator <= tolX || i >= maxIt)
            kont = false;

        i++;
    }

    return 0;
}

int main() {
    int iteracje = 100;
    double blad = 1e-15;

    std::cout << "Pierwsza funkcja" << std::endl;

    std::cout << "Picard" << std::endl;
    picard_1(0.3, iteracje, blad, blad);

    std::cout << "\nBisekcja" << std::endl;
    bisekcja_1(-0.3, 0.6, iteracje, blad, blad);

    std::cout << "\nNewton" << std::endl;
    newton_1(0.5,iteracje,blad,blad);

    std::cout << "\nSieczne" << std::endl;
    sieczne_1(-0.6, 1, iteracje, blad, blad);

    std::cout << "\n\n\nDruga funkcja" << std::endl;

    std::cout << "Picard" << std::endl;
    picard_2(0.3, iteracje, blad, blad);

    std::cout << "\nBisekcja" << std::endl;
    bisekcja_2(-0.3, 0.6, iteracje, blad, blad);

    std::cout << "\nNewton" << std::endl;
    newton_2(0.5,iteracje,blad,blad);

    std::cout << "\nSieczne" << std::endl;
    sieczne_2(-0.6, 1, iteracje, blad, blad);
}
