#include <iostream>
#include <fstream>
using namespace std;

class reg
{
private:
    string user_id;
    string password;
    string fname, lname;
    string phone_no;
    string email_id;
    string address;

public:
    reg()
    {
        user_id = password = fname = lname = "";
    }

    void getdata()
    {
        cout << "\nEnter user id:\t";
        getline(cin, user_id);
        cout << "\nEnter Password:\t";
        getline(cin, password);
        cout << "\nEnter your First Name:\t";
        getline(cin, fname);
        cout << "\nEnter your Last Name:\t";
        getline(cin, lname);
        cout << "\nEnter phone no.:\t";
        getline(cin, phone_no);
        cout << "\nEnter Email-id:\t";
        getline(cin, email_id);
        cout << "\nEnter address:\t";
        getline(cin, address);
    }

    void userReg();
    void adminReg();
    int checkUser(string temp);
    int checkAdmin(string temp);

    ~reg()
    {
        cout << "Destructor executed..." << endl;
    }
};

void reg::userReg()
{
    reg t;
    if (fname == "" || user_id == "" || password == "")
        cout << "\nError (Data is not found) !!\n"
             << endl;
    else
    {
        if (t.checkUser(user_id) == 0)
        {
            ofstream fout("Users.txt", ios::app);
            fout << fname << "\n"
                 << lname << "\n"
                 << user_id << "\n"
                 << password << "\n"
                 << phone_no << "\n"
                 << email_id << "\n"
                 << address << endl;
            fout.close();

            cout << "\n You have successfully registered.\n"
                 << endl;
        }
    }
}
void reg::adminReg()
{
    reg t;
    if (fname == "" || user_id == "" || password == "")
    {
        cout << "\nError (Data is not found) !!\n"
             << endl;
    }
    else
    {
        if (t.checkAdmin(user_id) == 0)
        {
            ofstream fout("tempAdmin.txt", ios::app);   
            fout << fname << "\n"
                 << lname << "\n"
                 << user_id << "\n"
                 << password << "\n"
                 << phone_no << "\n"
                 << email_id << "\n"
                 << address << endl;
            fout.close();

            cout << "\nRegistration form is submitted. Wait for administrators action.\n"
                 << endl;
        }
    }
}

int reg::checkAdmin(string temp)
{
    string fname, lname, user_id, password, phone_no, email_id, address;
    ifstream fin("tempAdmin.txt");
    while (fin)
    {
        getline(fin, fname);
        getline(fin, lname);
        getline(fin, user_id);
        getline(fin, password);
        getline(fin, phone_no);
        getline(fin, email_id);
        getline(fin, address);
        if (user_id == temp)
        {
            cout << "\n Error ! This user_id already exist..." << endl;
            return 1;
        }
    }
    fin.close();

    ifstream file("Admins.txt");
    while (file)
    {
        getline(file, fname);
        getline(file, lname);
        getline(file, user_id);
        getline(file, password);
        getline(file, phone_no);
        getline(file, email_id);
        getline(file, address);
        if (user_id == temp)
        {
            cout << "\n Error ! This user_id already exist..." << endl;
            return 1;
        }
    }
    file.close();
    return 0;
}

int reg::checkUser(string temp)
{
    string fname, lname, user_id, password, phone_no, email_id, address;
    ifstream fin("Users.txt");
    while (fin)
    {
        getline(fin, fname);
        getline(fin, lname);
        getline(fin, user_id);
        getline(fin, password);
        getline(fin, phone_no);
        getline(fin, email_id);
        getline(fin, address);
        if (user_id == temp)
        {
            cout << "\n Error ! This user_id already exist..." << endl;
            return 1;
        }
    }
    fin.close();
    return 0;
}

int main()
{
    system("CLS");
    reg check, temp;
    int opt;

menu:
    cout << "\n____________________________________________________________\n";
    cout << "\n------------------------------------------------------------\n"
         << endl;
    cout << "MENU:" << endl;
    cout << "\n [1] - User registration:\n";
    cout << "\n [2] - Administrator registration:\n";
    cout << "\n [3] - Close:\n\n---\t";

    cin >> opt;
    system("CLS");

    switch (opt)
    {
    case 1:
        cin.ignore();
        temp.getdata();
        temp.userReg();
        break;

    case 2:
        cin.ignore();
        temp.getdata();
        temp.adminReg();
        break;

    default:
        if (opt != 3)
            cout << "\nError! Enter again..." << endl;
        break;
    }

    if (opt == 3)
    {
        system("pause");
        system("CLS");
        return 0;
    }
    goto menu;
}