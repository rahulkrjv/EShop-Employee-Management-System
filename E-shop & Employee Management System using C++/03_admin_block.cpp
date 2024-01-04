#include <iostream>
#include <fstream>
using namespace std;

class admin
{
private:
    string user_id;
    string password;
    string fname, lname;
    string phone_no;
    string email_id;
    string address;

public:
    int adminLogIn();
    void regAdmin();
    void remTempAdmin();
    void remAdmin();

    ~admin()
    {
        cout << "Destructor executed..." << endl;
    }
};

int admin::adminLogIn()
{
    string t1, t2;
    cout << "\n____________________________________________________________\n";
    cout << "\n-------------------------- Log In --------------------------\n"
         << endl;
    cout << "\nUserID:\t";
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
void admin::regAdmin()
{
    string id;
    cout << "\nEnter user_id of person, whom you want to add:\t" << endl;
    getline(cin >> ws, id);

    ofstream outFile("Admins.txt", ios::app);
    ofstream tempFile("temp.txt", ios::app);
    ifstream fin("tempAdmin.txt");

    while (fin)
    {
        getline(fin >> ws, fname);
        getline(fin, lname);
        getline(fin, user_id);
        getline(fin, password);
        getline(fin, phone_no);
        getline(fin, email_id);
        getline(fin, address);
        if (id == user_id)
        {
            outFile << fname << "\n"
                    << lname << "\n"
                    << user_id << "\n"
                    << password << "\n"
                    << phone_no << "\n"
                    << email_id << "\n"
                    << address << endl;
            cout << "\nSuccessfully Added :\t" << user_id << " ." << endl;
        }
        else
        {
            tempFile << fname << "\n"
                     << lname << "\n"
                     << user_id << "\n"
                     << password << "\n"
                     << phone_no << "\n"
                     << email_id << "\n"
                     << address << endl;
        }
    }

    outFile.close();
    tempFile.close();
    fin.close();
    remove("tempAdmin.txt");
    rename("temp.txt", "tempAdmin.txt");
}

void admin::remTempAdmin()
{
    string id;
    cout << "\nEnter user_id of person, whom you want to remove:\t" << endl;
    getline(cin >> ws, id);

    ofstream tempFile("temp.txt", ios::app);
    ifstream fin("tempAdmin.txt");

    while (fin)
    {
        getline(fin >> ws, fname);
        getline(fin, lname);
        getline(fin, user_id);
        getline(fin, password);
        getline(fin, phone_no);
        getline(fin, email_id);
        getline(fin, address);
        if (id == user_id)
        {
            cout << "\nSuccessfully Removed :\t" << user_id << endl;
            continue;
        }

        tempFile << fname << "\n"
                 << lname << "\n"
                 << user_id << "\n"
                 << password << "\n"
                 << phone_no << "\n"
                 << email_id << "\n"
                 << address << endl;
    }

    tempFile.close();
    fin.close();
    remove("tempAdmin.txt");
    rename("temp.txt", "tempAdmin.txt");
}

void admin::remAdmin()
{
    string id;
    cout << "\nEnter user_id of person, whom you want to remove:\t" << endl;
    getline(cin >> ws, id);
    ofstream tempFile("temp.txt", ios::app);
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
        if (id == user_id)
        {
            cout << "\nSuccessfully Removed :\t" << user_id << endl;
            continue;
        }

        tempFile << fname << "\n"
                 << lname << "\n"
                 << user_id << "\n"
                 << password << "\n"
                 << phone_no << "\n"
                 << email_id << "\n"
                 << address << endl;
    }

    tempFile.close();
    fin.close();
    remove("tempAdmin.txt");
    rename("temp.txt", "Admins.txt");
}

int menu()
{
    int opt;
    cout << "\n____________________________________________________________\n";
    cout << "\n------------------------------------------------------------\n"
         << endl;
    cout << "MENU:" << endl;
    cout << "\n [1] - Register Administrator:\n";
    cout << "\n [2] - Remove Adminstrator Application:\n";
    cout << "\n [3] - Remove Administrator:\n";
    cout << "\n [4] - Close:\n\n---\t";

    cin >> opt;
    system("CLS");
    return opt;
}

int main()
{
    system("CLS");
    admin temp;
    int opt, i = 0;
LogIn:
    if (temp.adminLogIn() != 1)
    {
        cout << "\nUserId and Password doesn't match..." << endl;
        if (i < 3)
        {
            i++;
            goto LogIn;
        }
        return 1;
    }
menu:
    opt = menu();

    switch (opt)
    {
    case 1:
        temp.regAdmin();
        break;

    case 2:
        temp.remTempAdmin();
        break;

    case 3:
        temp.remAdmin();
        break;

    default:
        if (opt != 4)
            cout << "Error enter again...\t" << endl;

        break;
    }

    if (opt == 4)
    {
        cout << "\nThanks for your hard work." << endl;
        system("pause");
        system("CLS");
        return 0;
    }
    goto menu;
}