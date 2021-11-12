#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date d1(1999, 3, 8), d2(2003, 5, 16);
    cout << d1 << endl << d2 << endl;
    cout << "input date:\n";
    cin>>d1;
    cout << d1 << endl;
    return 0;
}
