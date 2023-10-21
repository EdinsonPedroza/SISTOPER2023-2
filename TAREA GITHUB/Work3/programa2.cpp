#include <iostream>
using namespace std;

int main()
{
    int var = 5;
    int *p = &var;
    int &r = var;
    cout << "Valor de var: " << var << endl;
    cout << "Dirección de var: " << &var << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Dirección de p: " << &p << endl;
    cout << "Valor apuntado por p: " << *p << endl;
    cout << "Valor de r: " << r << endl;
    cout << "Dirección de r: " << &r << endl;
    *p = 10;
    r = 15;
    cout << "Nuevo valor de var: " << var << endl;
    cout << "Dirección de var: " << &var << endl;
    cout << "Nuevo valor de p: " << p << endl;
    cout << "Dirección de p: " << &p << endl;
    cout << "Nuevo valor apuntado por p: " << *p<< endl;
    cout <<"Nuevo valor de r: "<< r<<endl;
    cout <<"Dirección der: "<<&r<<endl;
    return 0;
}
