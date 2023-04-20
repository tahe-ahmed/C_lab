#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

int dayInYear(int day, int month, int year);

int main()
{

    int year = 1900;
    int i;

    assert(("Faild: ...", dayInYear(-1, -1, -2000) != 1));
    assert(("Faild: ...", dayInYear(-1, -1, 2000) != 1));
    assert(("Faild: ...", dayInYear(1, -1, 2000) == 1));
    assert(("Faild: ...", dayInYear(-1, 1, 2000) != 1));
    assert(("Faild: ...", dayInYear(1, 1, -2000) == 1));

    for (i = year; i <= 2022; i += 1)
    {

        // assert(("Faild: ...", dayInYear(32, 12, 1900) < 366));

        // assert(("Messe: failed", (dayInYear(0, 0, i)) > 0));
        if (dayInYear(0, 0, i) < 0)
        {
            cout << " out of range " << endl;
            return 30;
        }

        if (i % 4 != 0)
        {
            if (dayInYear(32, 12, i) > 366)
            {
                cout << " out of range " << endl;
                return 31;
            }

            // common
            assert(("Messe: failed", (dayInYear(1, 1, i)) == 1));
            // if ((dayInYear(1, 1, i)) != 1)
            //     return 1;

            assert(("Messe: failed", (dayInYear(1, 3, i)) == 60));
            // if ((dayInYear(1, 3, i)) != 60)
            //     return 1;

            assert(("Messe: failed", (dayInYear(31, 12, i)) == 365));
            // if ((dayInYear(31, 12, i)) != 365)
            // return 1;
        }
        else if (i % 100 != 0)
        {
            // assert(("Faild: ...", dayInYear(32, 12, 1900) < 366));
            if (dayInYear(32, 12, i) > 367)
            {
                cout << " out of range " << endl;
                return 32;
            }

            // leap
            assert(("Messe: failed", dayInYear(1, 1, i) == 1));

            assert(("Messe: failed", (dayInYear(1, 3, i) == 61)));

            assert(("Messe: failed", (dayInYear(31, 12, i) == 366)));

            // if ((dayInYear(1, 1, i)) != 1)
            //     return 1;
            // if (dayInYear(1, 3, i) != 61)
            //     return 1;
            // if (dayInYear(31, 12, i) != 366)
            //     return 1;
        }
        else if (i % 400 != 0)
        {
            if (dayInYear(32, 12, i) > 366)
            {
                cout << " out of range " << endl;
                return 33;
            }

            // common
            assert(("Messe: failed", (dayInYear(1, 1, i)) == 1));
            // if ((dayInYear(1, 1, i)) != 1)
            //     return 1;

            assert(("Messe: failed", (dayInYear(1, 3, i)) == 60));
            // if ((dayInYear(1, 3, i)) != 60)
            //     return 1;

            assert(("Messe: failed", (dayInYear(31, 12, i)) == 365));
            // if ((dayInYear(31, 12, i)) != 365)
            // return 1;
        }
        else
        {
            if (dayInYear(32, 12, i) > 367)
            {
                cout << " out of range " << endl;
                return 34;
            }
            // assert(("Faild: ...", dayInYear(32, 12, 1900) < 366));

            assert(("Messe: failed", dayInYear(1, 1, i) == 1));

            assert(("Messe: failed", (dayInYear(1, 3, i) == 61)));

            assert(("Messe: failed", (dayInYear(31, 12, i) == 366)));

            // leap
            // if ((dayInYear(1, 1, i)) != 1)
            //     return 1;
            // if (dayInYear(1, 3, i) != 61)
            //     return 1;
            // if (dayInYear(31, 12, i) != 366)
            //     return 1;
        }
    }

    // for (i = year; i <= 2022; i += 1)
    // {
    //     assert(("Messe: failed", (dayInYear(32, 13, i) != 0)));
    //     // if ((dayInYear(32, 13, i)) == 0)
    //     //     return 1;
    // }
    std::cout << " Passed all testes !" << std::endl;

    return 0;
}

///  straties
/// personel atteractive
/// stbility
