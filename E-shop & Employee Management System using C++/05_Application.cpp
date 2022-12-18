#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

int Menu()
{
    int opt;
    cout << "\n____________________________________________________________\n";
    cout << "\n---------------------------- MENU --------------------------\n"
         << endl;
    cout << "\n [1] - User-Block:\n";
    cout << "\n [2] - Admin-Block:\n";
    cout << "\n [3] - Register:\n";
    cout << "\n [4] - Close:\n\n---\t";

    cin >> opt;
    system("CLS");
    return opt;
}

int MenuAdmin()
{
    int opt;
    cout << "\n____________________________________________________________\n";
    cout << "\n---------------------------- MENU --------------------------\n"
         << endl;
    cout << "\n [1] - Item handling:\n";
    cout << "\n [2] - Admin handling:\n";
    cout << "\n [3] - Close:\n\n---\t";

    cin >> opt;
    system("CLS");
    return opt;
}

int main()
{
    char reg[] = "E:\\C++\\project\\01_register.exe";
    char item[] = "E:\\C++\\project\\02_item_list.exe";
    char admin[] = "E:\\C++\\project\\03_admin_block.exe";
    char shopping[] = "E:\\C++\\project\\04_shopping.exe";
    int opt1, opt2;

Menu1:
    system("CLS");
    opt1 = Menu();
    switch (opt1)
    {
    case 1:
        ShellExecute(NULL, "open", shopping, NULL, NULL, SW_SHOWNORMAL);
        break;

    case 2:
    Menu2:
        system("CLS");
        opt2 = MenuAdmin();
        switch (opt2)
        {
        case 1:
            ShellExecute(NULL, "open", item, NULL, NULL, SW_SHOWNORMAL);
            break;

        case 2:
            ShellExecute(NULL, "open", admin, NULL, NULL, SW_SHOWNORMAL);
            break;

        default:
            if (opt2 != 3)
                cout << "Error !! Enter Again...\n"
                     << endl;
            break;

            if (opt2 != 3)
                goto Menu2;
        }
        break;

    case 3:
        ShellExecute(NULL, "open", reg, NULL, NULL, SW_SHOWNORMAL);
        break;

    default:
        if (opt1 != 4)
            cout << "Error !! Enter Again...\n"
                 << endl;
        break;
        if (opt1 != 4)
            goto Menu1;
        system("pause");
        return 0;
    }
}