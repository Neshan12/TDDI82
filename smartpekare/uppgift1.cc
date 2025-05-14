#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <iomanip>
#include <stdexcept>

#include "counted_ptr.h"

using namespace std;

struct Point
{
    int x;
    int y;
};

int main ()
{
    //Koperingskonstruktor:
    /*  
    int* heltal{new int{5}};

    counted_ptr<int> c1{heltal};
    cout << *c1.get() << " " << c1.use_count() << endl;
    counted_ptr<int> c2{c1};
    cout << *c1.get() << " " << c1.use_count() << endl;
    cout << *c2.get() << " " << c2.use_count() << endl;
    */
    
    // Koperingsoperator

    // int* heltal1{new int{5}};
    // int* heltal2{new int{4}};
    // counted_ptr<int> c1{heltal1};
    // counted_ptr<int> c2{heltal2};
    // cout << *c1.get() << " " << c1.use_count() << endl;
    // c2 = c1;
    // cout << *c1.get() << " " << c1.use_count() << endl;
    // cout << *c2.get() << " " << c2.use_count() << endl;


    // Flyttkonstruktor
    
    // int* heltal1{new int{5}};
    // counted_ptr<int> c1{ heltal1 };

    // cout << *c1.get() << " " << c1.use_count() << endl;

    // counted_ptr<int> c2{ move(c1) };

    // //cout << *c1.get() << " " << c1.use_count() << endl;
    // cout << *c2.get() << " " << c2.use_count() << endl;
   

    // Flytttilledlingsoperator

    // int* heltal1{new int{5}};
    // counted_ptr<int> c1{ heltal1 };

    // cout << *c1.get() << " " << c1.use_count() << endl;

    // counted_ptr<int> c2{};

    // c2 = move(c1);

    // //cout << *c1.get() << " " << c1.use_count() << endl;
    // cout << *c2.get() << " " << c2.use_count() << endl;

    // Tilldela nullptr
    //TODO: FIXA

    /* counted_ptr<int> c1{ new int{5} };
    cout << *c1 << endl;

    counted_ptr<Point> p1{ new Point{1, 2} };
    cout << p1->x << endl;
    cout << p1->y << endl; */

    // Logik:

    counted_ptr<int> c1{ new int{5} };
    counted_ptr<int> c2{ c1 };

    if (c1 == c2)
    {
        cout << "JA1" << endl;
    }

    int* t1{new int{5}};
    counted_ptr<int> c0{t1};

    if (c0 == t1)
    {
        cout << "JA2" << endl;
    }

    return 0;
}