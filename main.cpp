/*
*	main.cpp

	Aplikacja wyznaczająca środek trójkąta, z wykorzystaniem wzoru funkcji linowej

*	CopyLeft 16-06-2016
*	Autor: Piotr Wawryka piotrwzst@gmail.com,
*/

#include "PointZone.h"
#include "Func.h"
#include <vector>

// ------------------------------------------------------

int main()
{

   // system("chcp 65001 > nul");                                               // polskie znaki

    vector<Point> tab(3);

    tab[0] = {  8,  4 };
    tab[1] = {  2, -5 };
    tab[2] = {  -6, 5  };

///     nie bangla
//    tab[0] = {  0,  0 };
//    tab[1] = {  10, 0 };
//    tab[2] = { 0,  10 };


    for( Point t : tab )                                                        // pokaż punkty
    {
        Show( t );
    }
    cout << endl;

    Linear_Func a = {  tab[0], tab[1] };                                        // wyznaczam wzory funkcji
    Linear_Func b = {  tab[1], tab[2] };
    ///Linear_Func c = {  tab[2], tab[0] };

    a.ShowFuncModel();
    b.ShowFuncModel();
//  c.ShowFuncModel();

    a.ShowNormalFuncModel();
    b.ShowNormalFuncModel();
//  c.ShowNormalFuncModel();

    Point S; //S.X = 0.84;   S.Y = 2.272;                                       // Punkt środka

    S.X = (-b.Bnormal - a.Bnormal) / ( -b.Anormal - a.Anormal);
    // S.Y = ((a.Anormal - b.Anormal) * S.X) - (a.Bnormal - b.Bnormal)/2;       /// so close
    S.Y = -((a.Anormal + b.Anormal)  + (a.Bnormal + b.Bnormal) )* S.X;

    cout << "\nX = " << S.X << endl;
    cout << "Y = " << S.Y << endl << endl;

/*
        /// podaję do punktu testowego tylko wartość X, Y = 0
    Point test( 2, 0 );

        /// na podstawie wartości X obliczam Y, math everywhere :)
    test.Y = a.CalcFor( test.X );
    Show(test);
    test.Y = b.CalcFor( test.X );
    Show(test);
    test.Y = a.CalcForNormal( test.X );
    Show(test);
    test.Y = b.CalcForNormal( test.X );
    Show(test);
*/

   //cout << "Odległości: ";

   for( Point point : tab )
        cout << Length(S, point) << endl;

    black("\nLegenda:");
    green("\n(=) wzory funkcji linowych, przedluzenie bokow");
    red("\n(=) wzory funkcji prostopadlych (normal) do bokow przecinajac je w srodku");

    return 0;
}

// ------------------------------------------------------

