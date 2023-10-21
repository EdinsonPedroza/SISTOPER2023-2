#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    cout << "Dirección de arr: " << arr << endl;
    cout << "Dirección de ptr: " << ptr << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Valor de arr[" << i << "]: " << ptr[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        ptr[i] = ptr[i] * 2;
    }
    for (int i = 0; i < 5; i++) {
        cout << "Nuevo valor de arr[" << i << "]: " << ptr[i] << endl;
    }
    return 0;
}
