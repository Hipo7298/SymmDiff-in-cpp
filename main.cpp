#include <iostream>
#include <fstream>
#include "list.hpp"
#include "task.h"

using namespace std;

/***
    Template class List defined in list.hpp.
    The main() below read integers from 2 files (space, tab or \n between),
    and write its symmetric difference to standard output.
**/


//#define MAKEFILE
#ifndef MAKEFILE

int main()
{
    string ori = "test1_list1.txt";
    string mod = "test1_list2.txt";
    List<int> a;
    Fill(&a,ori);
    cout << "First content:\n";
    a.Display();

    List<int> b;
    Fill(&b,mod);
    cout << "Second content:\n";
    b.Display();
    symdiff(&a,&b);
    cout << "Symmetric difference solution:\n";
    a.Display();

    cout << "Symmetric difference length:\n";
    cout << a.length();

    return 0;
}

#else

    const int maximum_number_of_integers = 500;
    const int minimum_number_of_integers = 20;

    const int maximum_value_of_integer = 30;       /// (maximum value of integers) minus (minimum value of integers) be smaller than
    const int minimum_value_of_integer = -30;      /// (maximum number of integers) minus (minimum number of integers) to increase
                                                   /// the symmetric difference effectivity
    const string first_file_name = "test_list1.txt";
    const string second_file_name = "test_list2.txt";

int main() {
    int n = rand() % (maximum_number_of_integers-minimum_number_of_integers) + minimum_number_of_integers;
    fstream f1,f2;
    f1.open(first_file_name);
    f2.open(second_file_name);

    for(int i = 0;i<n;i++){
        int k = rand() % (maximum_value_of_integer)-(minimum_value_of_integer) + minimum_value_of_integer;
        f1 << k << "\n";
    }

    n = rand() % (maximum_number_of_integers-minimum_number_of_integers) + minimum_number_of_integers;
    for(int i = 0;i<n;i++){
        int k = rand() % (maximum_value_of_integer)-(minimum_value_of_integer) + minimum_value_of_integer;
        f2 << k << "\n";
    }
f1.close();
f2.close();

return 0;
}


#endif //MAKEFILE
