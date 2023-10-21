#include <iostream>
using namespace std;

void foo(int x) {
    int y = x + 1;
    cout << "Dirección de x en el stack: " << &x << endl;
    cout << "Dirección de y en el stack: " << &y << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    int *p = new int[5];
    cout << "Dirección de a en el stack: " << &a << endl;
    cout << "Dirección de b en el stack: " << &b << endl;
    cout << "Dirección de p en el stack: " << &p << endl;
    cout << "Dirección apuntada por p en el heap: " << p << endl;
    cout << "Dirección de main en el code: " << (void*)main << endl;
    cout << "Dirección de foo en el code: " << (void*)foo << endl;
    foo(a);
    delete[] p;
    return 0;
}
