#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class items
{
private:
    string name, id, price, quantity, category;

public:
    items()
    {
        name = "";
        id = "";
        price = "";
        quantity = "";
        category = "";
    }
    void getdata()
    {
        cout << "\nEnter item name:\t";
        getline(cin >> ws, name);
        cout << "\nEnter item id:\t";
        getline(cin >> ws, id);
        cout << "\nEnter item price:\t";
        getline(cin >> ws, price);
        cout << "\nEnter item quantity:\t";
        getline(cin >> ws, quantity);
        cout << "\nEnter item category:\t";
        getline(cin >> ws, category);
    }
    void putdata()
    {
        cout << "name\t"
             << "id\t"
             << "price\t"
             << "quantity\t"
             << "category\t\n"
             << endl;
        ifstream fin("item_list.txt");

        while (fin)
        {
            getline(fin >> ws, name);
            getline(fin, id);
            getline(fin, price);
            getline(fin, quantity);
            getline(fin, category);

            if (name != "" || id != "")
                cout << name << "\t" << id << "\t" << price << "\t" << quantity << "\t" << category << endl;
        }

        fin.close();
    }
    void storedata();
    void updatedata(string t_id);
    void srchFile(string t_id);
    void delfile(string t_id);
};

void items::storedata()
{
    if (name == "" || id == "")
    {
        cout << "\nError (Data is not found) !!\n"
             << endl;
    }
    else
    {
        ofstream fout("item_list.txt", ios::app);
        fout << name << "\n"
             << id << "\n"
             << price << "\n"
             << quantity << "\n"
             << category << endl;
        fout.close();

        cout << "\n Data is stored successfully.\n"
             << endl;
    }
}
void items::updatedata(string t_id)
{
    ofstream outFile("temp.txt", ios::app);
    ifstream fin("item_list.txt");

    while (fin)
    {
        getline(fin >> ws, name);
        getline(fin, id);
        getline(fin, price);
        getline(fin, quantity);
        getline(fin, category);
        if (id == t_id)
        {
            getdata();
            outFile << name << "\n"
                    << id << "\n"
                    << price << "\n"
                    << quantity << "\n"
                    << category << endl;

            cout << "\nSuccessfully updated..." << endl;
        }
        else
        {
            outFile << name << "\n"
                    << id << "\n"
                    << price << "\n"
                    << quantity << "\n"
                    << category << endl;
        }
    }

    outFile.close();
    fin.close();
    remove("item_list.txt");
    rename("temp.txt", "item_list.txt");
}
void items::srchFile(string t_id)
{
    cout << "name\t"
         << "id\t"
         << "price\t"
         << "quantity\t"
         << "category\t\n"
         << endl;
    ifstream fin("item_list.txt");

    while (fin)
    {
        getline(fin >> ws, name);
        getline(fin, id);
        getline(fin, price);
        getline(fin, quantity);
        getline(fin, category);
        if (name == t_id || id == t_id || category == t_id)
            cout << name << "\t" << id << "\t" << price << "\t" << quantity << "\t" << category << endl;
    }
    fin.close();
}
void items::delfile(string t_id)
{
    ofstream outFile("temp.txt", ios::app);
    ifstream fin("item_list.txt");

    while (fin)
    {
        getline(fin >> ws, name);
        getline(fin, id);
        getline(fin, price);
        getline(fin, quantity);
        getline(fin, category);
        if (id != t_id)
        {
            outFile << name << "\n"
                    << id << "\n"
                    << price << "\n"
                    << quantity << "\n"
                    << category << endl;
        }
    }

    outFile.close();
    fin.close();
    remove("item_list.txt");
    rename("temp.txt", "item_list.txt");
    cout << "\nSuccessfully deleted..." << endl;
}

int adminLogIn()
{
    string fname, lname, user_id, password, phone_no, email_id, address, t1, t2;
    cout << "\n____________________________________________________________\n";
    cout << "\n-------------------------- Log In --------------------------\n"
         << endl;
    cout << "\nUserid:\t";
    getline(cin >> ws, t1);
    cout << "\nPassword:\t";
    getline(cin >> ws, t2);

    ifstream fin("Admins.txt");

    while (fin)
    {
        getline(fin >> ws, fname);
        getline(fin, lname);
        getline(fin, user_id);
        getline(fin, password);
        getline(fin, phone_no);
        getline(fin, email_id);
        getline(fin, address);
        if (user_id == t1 || password == t2)
        {
            cout << "\nWelcome Mr./Ms. " << lname << " ! Have a nice day..." << endl;
            return 1;
        }
    }
    fin.close();
    return 0;
}

int main()
{
    system("CLS");
    int i = 0;
LogIn:
    if (adminLogIn() != 1)
    {
        cout << "\nUserId and Password doesn't match..." << endl;
        if (i < 3)
        {
            i++;
            goto LogIn;
        }
        return 1;
    }
    items item[10], temp;
    int size, opt = 0;
    string search;
    system("CLS");
menu:
    cout << "\n____________________________________________________________\n";
    cout << "\n------------------------------------------------------------\n"
         << endl;
    cout << "MENU:" << endl;
    cout << "\n [1] - Add items data:\n";
    cout << "\n [2] - Update item's data:\n";
    cout << "\n [3] - All items list:\n";
    cout << "\n [4] - search item by 'id' or 'name':\n";
    cout << "\n [5] - Save:\n";
    cout << "\n [6] - Delete item's data:\n";
    cout << "\n [7] - Close:\n\n---\t";

    cin >> opt;
    system("CLS");

    switch (opt)
    {
    case 1:
        cout << "\nHow many item you want to add(Max. 10):\t";
        cin >> size;

        system("CLS");

        for (int i = 0; i < size; i++)
        {
            cout << "\nEnter data of item" << (i + 1) << ": ---------------\n"
                 << endl;
            item[i].getdata();
        }
        break;
    case 2:
        cout << "\nEnter id of item you want to update:\t";
        getline(cin >> ws, search);

        temp.updatedata(search);
        break;
    case 3:
        cout << "---------------------------------------" << endl;
        temp.putdata();
        break;
    case 4:
        cout << "\nEnter id, name or category to search items:\t";
        getline(cin >> ws, search);

        temp.srchFile(search);
        break;
    case 5:
        for (int i = 0; i < size; i++)
        {
            item[i].storedata();
        }

        break;
    case 6:
        cout << "\nEnter id of item you want to delete:\t";
        getline(cin >> ws, search);

        temp.delfile(search);
        break;
    case 7:
        cout << "\nThanks for your hard work." << endl;
        break;

    default:
        if (opt != 7)
            cout << "\nError! Enter again..." << endl;
        break;
    }

    if (opt == 7)
    {
        system("pause");
        system("CLS");
        return 0;
    }
    goto menu;
}