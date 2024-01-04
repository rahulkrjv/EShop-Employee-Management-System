#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

string temp_id;

class temp
{
public:
    int logInMenu()
    {
        int opt;
        cout << "\n____________________________________________________________\n";
        cout << "\n------------------------------------------------------------\n"
             << endl;
        cout << "MENU:" << endl;
        cout << "\n [1] - Log In:\n";
        cout << "\n [2] - Close:\n\n---\t";

        cin >> opt;
        system("CLS");
        return opt;
    }
    bool logInUser()
    {
        string fname, lname, user_id, password, phone_no, email_id, address, t_password;

        cout << "\n____________________________________________________________\n";
        cout << "\n-------------------------- Log In --------------------------\n"
             << endl;
        cout << "\nUser ID:\t";
        getline(cin >> ws, temp_id);
        cout << "\nPassword:\t";
        getline(cin >> ws, t_password);

        ifstream fin("Users.txt");
        while (fin)
        {
            getline(fin >> ws, fname);
            getline(fin, lname);
            getline(fin, user_id);
            getline(fin, password);
            getline(fin, phone_no);
            getline(fin, email_id);
            getline(fin, address);
            if (user_id == temp_id && password == t_password)
            {
                cout << "\nWelcome Mr./Ms. " << lname << " ! I wish you get what you want..." << endl;
                return true;
            }
        }
        fin.close();

        ifstream file("Admins.txt");
        while (file)
        {
            getline(file >> ws, fname);
            getline(file, lname);
            getline(file, user_id);
            getline(file, password);
            getline(file, phone_no);
            getline(file, email_id);
            getline(file, address);
            if (user_id == temp_id && password == t_password)
            {
                cout << "\nWelcome Mr./Ms. " << lname << " ! I wish you get what you want..." << endl;
                return true;
            }
        }
        file.close();
        return false;
    }

    void Menu()
    {
        int opt;
        cout << "\n____________________________________________________________\n";
        cout << "\n---------------------------- MENU --------------------------\n"
             << endl;
        cout << "\n [1] - Buy:\n";
        cout << "\n [2] - Orders:\n";
        cout << "\n [3] - Account Details:\n";
        cout << "\n [4] - Close:\n\n---\t";

        cin >> opt;
        system("CLS");

        switch (opt)
        {
        case 1:
            buyMenu();
            break;

        case 2:
            orders();
            break;

        case 3:
            userDetail();
            break;

        default:
            if (opt != 4)
                cout << "\nError ! Enter again..." << endl;
            break;
        }
        if (opt != 4)
            Menu();
    }

    void buyMenu()
    {
        int opt;
        cout << "\n____________________________________________________________\n";
        cout << "\n------------------------------------------------------------\n"
             << endl;
        cout << "MENU:" << endl;
        cout << "\n [1] - See all items:\n";
        cout << "\n [2] - Buy Item:\n";
        cout << "\n [3] - Sort by category:\n";
        cout << "\n [4] - Sort by price:\n";
        cout << "\n [5] - Close:\n\n---\t";

        cin >> opt;
        system("CLS");

        switch (opt)
        {
        case 1:
            allItems();
            break;

        case 2:
            buy();
            break;

        case 3:
            catItems(category());
            break;

        case 4:
            priceItems();
            break;

        default:
            if (opt != 5)
            {
                cout << "\nError..." << endl;
                buyMenu();
            }
            break;
        }
        if (opt != 5)
            buyMenu();
    }

    string category()
    {
        int opt;
        cout << "\n____________________________________________________________\n";
        cout << "\n------------------------------------------------------------\n"
             << endl;
        cout << "\n [1] - Fruits:\n";
        cout << "\n [2] - Dry Fruits:\n";
        cout << "\n [3] - Grocery items:\n";
        cout << "\n [4] - Close:\n\n---\t";

        cin >> opt;

        switch (opt)
        {
        case 1:
            return "Fruits";
            break;

        case 2:
            return "Dry Fruits";
            break;

        case 3:
            return "Grocery items";
            break;

        default:
            cout << "Error..." << endl;
            return category();
            break;
        }
    }

    void allItems()
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
            string name, id, price, quantity, category;

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

    void catItems(string temp)
    {
        string name, id, price, quantity, category;
        ifstream fin("item_list.txt");
        while (fin)
        {
            getline(fin >> ws, name);
            getline(fin, id);
            getline(fin, price);
            getline(fin, quantity);
            getline(fin, category);
            if (temp == category)
                cout << name << "\t" << id << "\t" << price << "\t" << quantity << "\t" << category << endl;
        }

        fin.close();
    }

    void priceItems()
    {
        double min, max;

        cout << "\nEnter min amount:\t";
        cin >> min;
        cout << "\nEnter max amount:\t";
        cin >> max;

        string name, id, price, quantity, category;
        ifstream fin("item_list.txt");
        while (fin)
        {
            getline(fin >> ws, name);
            getline(fin, id);
            getline(fin, price);
            getline(fin, quantity);
            getline(fin, category);
            if ((min <= stod(price)) && (stod(price) <= max))
                cout << name << "\t" << id << "\t" << price << "\t" << quantity << "\t" << category << endl;
        }
        fin.close();
    }

    void buy()
    {
        string t_id;
        int t_quantity, temp_quantity, temp;

        cout << "\nEnter id of item you wants to buy:\t";
        getline(cin >> ws, t_id);
        cout << "\nEnter Quantity of item you wants to buy:\t";
        cin >> t_quantity;

        string name, id, price, quantity, category;
        ofstream tempFile("temp.txt", ios::app);
        ofstream outFile("Orders.txt", ios::app);
        ifstream fin("item_list.txt");
        while (fin)
        {
            getline(fin >> ws, name);
            getline(fin, id);
            getline(fin, price);
            getline(fin, quantity);
            getline(fin, category);
            temp_quantity = stoi(quantity);
            if ((t_id == id) && (temp_quantity > t_quantity))
            {
                cout << name << "\t" << id << "\t" << price << "\t" << quantity << "\t" << category << endl;
                temp = temp_quantity - t_quantity;
                quantity = to_string(temp);

                tempFile << name << "\n"
                         << id << "\n"
                         << price << "\n"
                         << quantity << "\n"
                         << category << endl;

                outFile << name << "\n"
                        << id << "\n"
                        << price << "\n"
                        << to_string(t_quantity) << "\n"
                        << category << "\n"
                        << temp_id << endl;

                cout << "Thanks for buying. We'll deliver your item ASAP." << endl;
            }
            else
            {
                tempFile << name << "\n"
                         << id << "\n"
                         << price << "\n"
                         << quantity << "\n"
                         << category << endl;
            }
        }

        tempFile.close();
        outFile.close();
        fin.close();
        remove("item_list.txt");
        rename("temp.txt", "item_list.txt");
    }

    void userDetail()
    {
        string fname, lname, user_id, password, phone_no, email_id, address;
        ifstream fin("Users.txt");
        while (fin)
        {
            getline(fin >> ws, fname);
            getline(fin, lname);
            getline(fin, user_id);
            getline(fin, password);
            getline(fin, phone_no);
            getline(fin, email_id);
            getline(fin, address);
            if (user_id == temp_id)
            {
                cout << "\nName:\t" << fname + " " + lname << "\nContact no.:\t" << phone_no << "\nEmail:\t" << email_id << "\nAddress:\t" << address << endl;
                break;
            }
        }
        fin.close();
    }

    void orders()
    {
        cout << "name\t"
             << "id\t"
             << "price\t"
             << "quantity\t"
             << "category\t\n"
             << endl;
        string name, id, price, quantity, category, user_id;
        ifstream fin("Orders.txt");
        while (fin)
        {
            getline(fin >> ws, name);
            getline(fin, id);
            getline(fin, price);
            getline(fin, quantity);
            getline(fin, category);
            getline(fin, user_id);
            if (user_id == temp_id)
            {
                cout << "\nName:\t" << name << "\nItem Id:\t" << id << "\nPrice:\t" << price << "\nQuantity:\t" << quantity << endl;
                break;
            }
        }
        fin.close();
    }
};

int main()
{
    temp ob;
    int opt, i = 0;
logIn:
    system("CLS");

    opt = ob.logInMenu();
    switch (opt)
    {
    case 1:
        if (ob.logInUser())
            ob.Menu();
        else
        {
            i++;
            if (i > 3)
                return 1;
        }

        break;
    default:
        if (opt != 2)
            cout << "\nError ! Enter again..." << endl;
        break;
    }
    if (opt == 2)
    {
        cout << "\nThanks for visiting us. We hope you got what you wanted.\n"
             << endl;
        system("pause");
        system("CLS");
        return 0;
    }

    system("pause");
    goto logIn;
}