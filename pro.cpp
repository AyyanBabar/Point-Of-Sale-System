#include "Pos.h"
#include <iostream>
using namespace std;
int main()
{
    int input;
    Pos pos;
    pos.loaddata();
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        system("cls");
        cout << "Loading";
        for (int j = 0; j < 10; j++)
        {
            if (j < i)
                cout << "#";
            else
                cout << "_";
        }
        _sleep(150);
    }
A:
    system("cls");
    cout << "1 - Manage Items \n2 - Manage Customers \n3 - Make New Sale \n4 - Make Payment \n5 - Exit\n";
    cin >> input;
    cin.ignore();
    if (input == 1)
    {
        system("cls");
        cout << "\n1- Add new Item  \n2- Update Item details  \n3- Find Items  \n4- Remove Existing Item  \n5- Back to Main Menu\n ";
        cin >> input;
        cin.ignore();
        switch (input)
        {
        case 1:
            pos.additem();
            pos.upload();
            system("pause");
            goto A;
        case 2:
            pos.updateitem();
            pos.upload();
            system("pause");
            goto A;
        case 3:
            pos.finditem();
            pos.upload();
            system("pause");
            goto A;
        case 4:
            pos.Removeitem();
            pos.upload();
            system("pause");
            goto A;
        case 420: //cheat/debuging
            pos.showitems();
            system("pause");
        default:
            goto A;
        }
    }
    else if (input == 2)
    {
        system("cls");
        cout << "\n1 - Add new Customer \n2 - Update Customer details \n3 - Find Customer \n4 - Remove Existing Customer \n5 - Back to Main Menu\n";
        cin >> input;
        cin.ignore();
        switch (input)
        {
        case 1:
            pos.addcus();
            pos.upload();
            system("pause");
            goto A;
        case 2:
            pos.updatecus();
            pos.upload();
            system("pause");
            goto A;
        case 3:
            pos.findcus();
            pos.upload();
            system("pause");
            goto A;
        case 4:
            pos.removecus();
            pos.upload();
            system("pause");
            goto A;
        default:
            goto A;
        }
    }
    else if (input == 3)
    {
        pos.sale();
        pos.upload();
        system("pause");
        goto A;
    }
    else if (input == 4)
    {
        pos.payment();
        pos.upload();
        system("pause");
        goto A;
    }
    else if (input == 5)
    {
        pos.upload();
        return 0;
    }
    else
        goto A;
}