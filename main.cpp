#include <iostream>
#include "Vector.h"
#include "Vector.cpp"

using namespace std;

int main()
{
    Vector<int> v;
    int menu;

    do {
        cout << "Vector: ";
        for(int i=0;i<v.getSize();i++)
        {
            cout << v[i] << " ";
        }
        cout << endl << endl;

        cout << "Menu:\n\n";
        cout << "1. Push_back\n";
        cout << "2. Pop_back\n";
        cout << "3. Set\n";
        cout << "0. Exit\n\n > ";
        cin >> menu;

        if(menu == 1){
            int data;

            cout << "Data > ";
            cin >> data;

            v.push_back(data);
        }
        else if(menu == 2){
            v.pop_back();
        }
        else if(menu == 3){
            int data, index;

            cout << "Index > ";
            cin >> index;

            cout << "Data > ";
            cin >> data;

            v[index] = data;
        }

    }while(menu != 0);


    return 0;
}
