#include <iostream>
#include <fstream>
#include <limits>
#include <string.h>
#include <ctime>
// for newlines
#define newline(n)              \
    for (int i = 0; i < n; i++) \
    cout << "\n"
// for stars
#define stars(n)                \
    for (int i = 0; i < n; i++) \
    cout << "*="

using namespace std;
template <typename T>
class customer
{
    T name[30];
    T policy[60];
    T address[60];
    int age;
    long long mob;
    long long CID;

public:
    // this is the info which i wanted to store into file as well but i coudn't store the data that is initialized into the file that's y this is an alternative which i did to print the info
    void displayPolicyInfo()
    {
        cout << "\n\n1)LIC Jeevan Amar:\n\nthis is very helpful policy for you entire life this will help you to live a long and happy life to you. you should by this policy.\nSome features of this policy:\n1)plan type: Whole Life Insurance\n2)Entry age: 8 years- 65 years\n3)Max age: 65 years\n4)Policy term: 	10 years-40 years\n\n1)LIC Jeevan jio:\n\nthis is very helpful policy for you entire life this will help you to live a long and happy life to you. you should by this policy.\nSome features of this policy:\n1)plan type: Whole Life Insurance\n2)Entry age: 1 years- 60 years\n3)Max age: 60 years\n4)Policy term: 10 years-50 years\n\n1)LIC Shiksha policy:\n\nThis is very helpful policy for your child or yourself if you are educating you can buy this policy and we will provide you fund for the education.\nSome features of this policy:\n1)plan type: Life Insurance\n2)Entry age: 8years- 35 years\n3)Max age: 30 years\n4)Policy term: 10 years-20 years";
        newline(2);
    }
    void getdata()
    {
        // after every string input i have cleared the standard input buffer so that i would be able to read space seperated strings from the user without any skip
        fflush(stdin);
        cout << "\nEnter name: ";
        cin.getline(name, 30);
        fflush(stdin);
        cout << "\nEnter policy: ";
        cin.getline(policy, 60);
        fflush(stdin);
        cout << "\nEnter address: ";
        cin.getline(address, 60);
        fflush(stdin);
        cout << "\nEnter age: ";
        cin >> age;
        cout << "\nEnter mobile number: ";
        cin >> mob;
        cout << "\nEnter customer id(only integers): ";
        cin >> CID;
    }
    // my ID here is private but throughout my program i have used customer ID outside this class hence i need this function to access the cid
    long long int getID()
    {
        return CID;
    }
    // thhis function helps me to print the data inside a particular object of the customer class
    void display()
    {

        cout << "\nname: " << name;
        cout << "\npolicy: " << policy;
        cout << "\naddress: " << address;
        cout << "\nmobile number: " << mob;
        cout << "\ncustomer age: " << age;
        cout << "\ncustomer ID: " << CID << endl
             << endl;
    }
    // this function helps me to read the whole content in the file and display it into the console directly
    void fread(string file)
    {
        customer obj;
        ifstream fin(file, ios::in);

        fin.read((T *)&obj, sizeof(obj));
        if (!fin)
        {
            cout << "\n\nNO DATA IN DATABASE :-(\n\n";
            return;
        }
        while (fin.eof() == 0)
        {
            obj.display();
            fin.read((T *)&obj, sizeof(obj));
        }
    }

    // fwrite function helps me to write the new customer data into the file licdata.txt
    void fwrite()
    {
        customer obj;
        obj.getdata();
        ofstream fout("licdata.txt", ios::app);
        if (!fout)
        {
            cout << "\nFile can't be opened!\n";
        }
        else
        {
            fout.write((T *)&obj, sizeof(obj));
        }
        fout.close();

        // NOTOFICATION
        // current date and time depending upo current system time
        time_t now = time(0);
        // converting to strning
        char *loc = ctime(&now);
        ofstream out("Notifications.txt", ios::out | ios::app);
        out << "\nNew customer named " << obj.name << " bought " << obj.policy << " policy! "
            << "on " << loc << endl;
        out.close();
    }
    // i have overloaded the operaor so that i can use greater than symbol on objcts while sorting function
    bool operator>(customer obj)
    {
        if (CID > obj.getID())
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    // function template i have used here
    template <class M>
    void sortObjAr(M ar[], int size)
    {
        if (size == 0 or size == 1)
        {
            cout << "\nData is already sorted!\n";
            return;
        }
        else
        {
            // simple insertion sort
            for (int k = 1; k < size; k++)
            {
                M current = ar[k];
                int j = k - 1;
                while (current > ar[j] and j >= 0)
                {
                    ar[j + 1] = ar[j];
                    j--;
                }
                ar[j + 1] = current;
            }
            cout << "\nYour data has been sorted successfully..... :) \n\nNote: your data has been stored in increasing orders of customer ID\n";
        }

        // NOTOFICATION
        // current date and time depending upo current system time
        time_t now = time(0);
        // converting to strning
        char *loc = ctime(&now);
        ofstream out("Notifications.txt", ios::out | ios::app);
        out << "\nYou sorted the data of the customers "
            << "on " << loc << "\n";
        out.close();
    }
    // to up[date the data into the ffile]
    void updateDetails()
    {

        long long id;
        cout << "\nEnter your customer ID : ";
        cin >> id;
        bool flag = 0;
        customer obj;
        ifstream fin("licdata.txt", ios::in);
        ofstream temp("temp.txt", ios::out | ios::app);
        fin.read((T *)&obj, sizeof(obj));
        while (!fin.eof())
        {
            if (obj.CID == id)
            {
                flag = 1;
                int t = 1;
                while (t)
                {
                    int s;
                    cout << "\nEnter what things you want to update: ";
                    cout << "\n1) Name\n2) Policy\n3) Address\n4) Number\n5) Age\nEnter: ";
                    cin >> s;
                    switch (s)
                    {
                    case 1:
                        fflush(stdin);
                        cout << "\nEnter new name: ";
                        gets(obj.name);
                        fflush(stdin);
                        break;
                    case 2:
                        fflush(stdin);
                        cout << "\nEnter new policy: ";
                        gets(obj.policy);
                        break;
                    case 3:
                        fflush(stdin);
                        cout << "\nEnter new address: ";
                        gets(obj.address);
                        break;
                    case 4:
                        fflush(stdin);
                        cout << "\nEnter new number: ";
                        cin >> obj.mob;
                        break;
                    case 5:
                        fflush(stdin);
                        cout << "\nEnter new age: ";
                        cin >> obj.age;
                        break;
                    default:
                        cout << "\nWrong choice!\n";
                    }
                    cout << "\nWant to continue updation (1/0) :";
                    cin >> t;
                }
                temp.write((T *)&obj, sizeof(obj));
            }
            else
            {
                temp.write((T *)&obj, sizeof(obj));
            }
            fin.read((T *)&obj, sizeof(obj));
        }
        if (flag == 0)
        {
            cout << "\n\nNO DATA FOUND WITH THIS ID :-(!\n";
        }
        cout << "\n\nDATA WITH ID: " << id << " UPDATED SUCCESSFULLY......   :-)\n\n";
        fin.close();
        temp.close();
        remove("licdata.txt");
        rename("temp.txt", "licdata.txt");

        // NOTOFICATION
        // current date and time depending upon current system time
        time_t now = time(0);
        // converting to strning
        char *loc = ctime(&now);
        ofstream out("Notifications.txt", ios::out | ios::app);
        out << "\nSomebody updated the data with id: " << id
            << " on " << loc << "\n";
        out.close();
    }
    // directly searching into the file
    void searchCustomer()
    {
        long long id;
        customer obj;
        cout << "\nEnter the id of the customer to be searched: ";
        cin >> id;
        bool flag = 0;
        ifstream fin("licdata.txt", ios::in);
        fin.read((T *)&obj, sizeof(obj));
        // tochk if data eexits at all or not
        if (!fin)
        {
            cout << "\n\nNO DATA IN DATABASE :-(\n\n";
            return;
        }
        while (!fin.eof())
        {
            if (obj.CID == id)
            {
                flag = 1;
                obj.display();
            }
            fin.read((T *)&obj, sizeof(obj));
        }

        if (flag == 0)
        {
            cout << "\nDATA WITH ID: " << id << " NOT FOUND :-)\n\n";
            return;
        }

        // NOTOFICATION
        // current date and time depending upo current system time
        time_t now = time(0);
        // converting to strning
        char *loc = ctime(&now);
        ofstream out("Notifications.txt", ios::out | ios::app);
        out << "\nSomebody Searched for the id: " << id << " on " << loc << "\n";
        out.close();
    }
};
// inherited the customer class into the Admin class
template <typename T>
class Admin : public customer<T>
{
    // i was not having any option insetad of stroring this data at the timeof decxlaration itslef bcz char arras can't be intialised directly except at the time of the initialization
    char pW[30] = "A@123";
    char uN[30] = "A";

public:
    // constructor
    Admin()
    {
        ofstream fout("AdminData.txt", ios::out);
        fout.write((char *)&uN, sizeof(uN));
        fout.write((char *)&pW, sizeof(pW));
        fout.close();
    }
    // used file handling to chk the password and username of the admin if it is correct or not
    bool chk()
    {
        char user[30], pass[30];
        ifstream fin("AdminData.txt", ios::in);
        cout << "\nENTER USERNAME : ";
        cin >> user;
        cout << "\nENTER PASSWORD : ";
        cin >> pass;
        fin.read((char *)&uN, sizeof(uN));
        fin.read((char *)&pW, sizeof(pW));
        if ((!strcmp(uN, user)) and (!strcmp(pass, pW)))
        {
            cout << "\n\n";
            stars(10);
            cout << "PASSWORD MATCHED";
            stars(10);
            cout << "\n\n";
            return 1;
        }
        else
        {
            cout << "\nWrong password or username!\n";
            return 0;
        }
    }
    // to update the password and usernmae of the agent/admin
    // i tried to make it forever change a it would be stored in the file itself
    void updatePasswordAndUsername()
    {
        ofstream fout("AdminData.txt", ios::out);
        cout << "\nEnter new username: ";
        cin >> uN;
        cout << "\nEnter new password: ";
        cin >> pW;
        fout.write((char *)&uN, sizeof(uN));
        fout.write((char *)&pW, sizeof(pW));
        fout.close();

        // NOTOFICATION
        // current date and time depending upo current system time
        time_t now = time(0);
        // converting to strning
        char *loc = ctime(&now);
        ofstream out("Notifications.txt", ios::out | ios::app);
        out << "\nYou Updated the username and password "
            << "on " << loc << "\n";
        out.close();
    }
    // it is the function which helps to delete any particular record in the file
    void deleteRecord()
    {
        long long int id;
        customer<char> obj;
        cout << "\nEnter customer id: ";
        cin >> id;
        bool flag = 0;
        ifstream fin("licdata.txt", ios::in);
        ofstream t("t.txt", ios::out | ios::app);
        fin.read((char *)&obj, sizeof(obj));
        // to chk if the data exists in the file or not
        if (!fin)
        {
            cout << "\n\nNO DATA IN DATABASE :-(\n\n";
            return;
        }
        if (fin.eof())
        {
            cout << "\nFile has No data!\n";
            return;
        }
        while (!fin.eof())
        {
            if (obj.getID() == id)
            {
                flag = 1;
            }
            else
            {
                t.write((char *)&obj, sizeof(obj));
            }
            fin.read((char *)&obj, sizeof(obj));
        }
        if (flag == 0)
        {
            cout << "\nDATA WITH ID: " << id << " NOT FOUND :-)\n";
            return;
        }
        fin.close();
        t.close();
        remove("licdata.txt");
        rename("t.txt", "licdata.txt");
        cout << "\n\nDATA WITH ID: " << id << " DELETED SUCCESSFULLY......   :-)\n\n";
        // NOTOFICATION
        // current date and time depending upo current system time
        time_t now = time(0);
        // converting to strning
        char *loc = ctime(&now);
        ofstream out("Notifications.txt", ios::out | ios::app);
        out << "\nSomebody deleted the data with id: " << id
            << " on " << loc << "\n";
        out.close();
    }
    // this is the function which i have created to sort the data in the file in ascending order of the ID's
    void sortCustomerDataInFile()
    {
        customer<char> ar[100];
        ifstream fin("licdata.txt", ios::in);
        ofstream temp("temporary.txt", ios::out);
        fin.read((char *)&ar[0], sizeof(ar[0]));
        int i = 1;
        while (fin.eof() == 0)
        {
            fin.read((char *)&ar[i], sizeof(ar[i]));
            i++;
        }
        int len = i - 1;
        // calling the sortArobj function in customer class to sort the data and that function is created using the function template

        ar[0].sortObjAr<customer<char>>(ar, len);

        for (int j = 0; j < len; j++)
        {
            temp.write((char *)&ar[j], sizeof(ar[j]));
        }
        fin.close();
        temp.close();
        remove("licdata.txt");
        rename("temporary.txt", "licdata.txt");
    }
    // suddenly came into mind that we can notify the customer if there is new customer who has registered for the LIC policy
    void notifications()
    {
        // if not understanding what is this just go at top and see the preprocessor directives :-)
        newline(2);
        stars(10);
        cout << "WELCOME TO NOTIFICATION SECTION AGENT";
        stars(10);
        newline(2);
        string apple;
        ifstream fin("Notifications.txt", ios::in);
        getline(fin, apple);
        cout << apple << endl;
        while (!fin.eof())
        {
            getline(fin, apple);
            cout << apple << endl;
        }
    }
};
int main()
{
    time_t n = time(0);
    char *t = ctime(&n);
    int a = 1;
    while (a)
    {
        system("CLS");
        cout << "\n"
             << t;
        customer<char> C;
        Admin<char> A;
        int opt1;
        int opt2;
        int a1 = 1;
        // time and date :reference from tutorials point
        time_t now = time(0);     // thios returns the system time in miliseconds since 1 january 1970
        tm *lt = localtime(&now); // i have pass the address of now object into localtime function which converts the miliseconds time into the structure having all this different like date , hour , min etc and will return pointer ot this structore and you can access them with the object pointer of tm type

        newline(2);
        stars(10);
        cout << "WELCOME TO LIC DATABASE MANAGEMENT SYSTEM";
        stars(10);
        newline(2);
        cout << "\nEnter who you are:\n\n1) :-) Agent\n2) :-) Customer\n\nEnter: ";
        cin >> opt1;
        switch (opt1)
        {
        case 1:
            // Admin/Agent part
            cout << "\nHii Agent!";
            if ((lt->tm_hour >= 0 and lt->tm_min >= 0) and (lt->tm_hour <= 11 and lt->tm_min <= 60))
            {
                // 1am to 11:60am
                cout << "\nGOOD MORNING AGENT :-)\n\nPLEASE KINDLY LOGIN\n\n";
            }
            else if ((lt->tm_hour >= 12 and lt->tm_min >= 0) and (lt->tm_hour <= 17 and lt->tm_min <= 59))
            {
                // 12pm to 6pm
                cout << "\nGOOD AFERNOON AGENT :-)\n\nPLEASE KINDLY LOGIN\n\n";
            }
            else
            {
                // 6pm to 12am
                cout << "\nGOOD EVENING AGENT :-)\n\nPLEASE KINDLY LOGIN\n\n";
            }
        start:
            if (A.chk())
            {
                while (a1)
                {
                up:
                    cout << "\nSelect what you want to do?\n\n1) See all customer details\n2) Update username and password\n3) Sort the whole record\n4) Search for a customer with customer Id\n5) Update the info of any customer\n6) Delete any customer record\n7) Add customer\n8) See the Notifications\n9) Exit\n\nEnter: ";
                    cin >> opt2;
                    switch (opt2)
                    {
                    case 1:
                        A.fread("licdata.txt");
                        break;
                    case 2:
                        A.updatePasswordAndUsername();
                        break;
                    case 3:
                        A.sortCustomerDataInFile();
                        break;
                    case 4:
                        A.searchCustomer();
                        break;
                    case 5:
                        A.updateDetails();
                        break;
                    case 6:
                        A.deleteRecord();
                        break;
                    case 7:
                        A.fwrite();
                        break;
                    case 8:
                        A.notifications();
                        break;
                    case 9:
                        goto exit;
                        break;
                    default:
                        cout << "\n\nWrong choice!\n please enter right choice :-)\n";
                        goto up;
                        break;
                    }
                    /**************************USING EXCEPTION HANDLING FOR INPUT VALIDATION******************************************/
                    // to fix this crash i can use exception handling here which i'm going to use now

                    try
                    {
                        cout << "\nNOTE: be alert! don't enter character or string below only inetegers!\n";
                        cout << "\nWant to continue as a customer(1/0): ";
                        cin >> a1;
                        if (cin.fail()) // to check if user have entered character or string instead of integer
                        {
                            cin.clear();                                         // to reset the cin into normal mode
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to clear the buffer through which i/p out put takes place since there would be te string or a character in the buffer which user enetred mistakenly in place of 1/0.
                            throw a;
                        }
                    }
                    catch (...)
                    {
                        cout << "\n\nI ALREADY TOLD YOU TO ENTER 1/0 BUT SADLY U ENETERED A STRING OR A CHARACTER -_-!\n\n";
                    }
                    /**************************USING EXCEPTION HANDLING FOR INPUT VALIDATION******************************************/
                }
            }
            else
            {
                cout << "\nOops! AGENT you have entered wrong password or username\nplease try again with correct password and username\n";
                goto start;
            }
            break;
        case 2:
            // customer part
            cout << "\nHii Customer!";
            if ((lt->tm_hour >= 0 and lt->tm_min >= 0) and (lt->tm_hour <= 11 and lt->tm_min <= 60))
            {
                cout << "\nGOOD MORNING CUSTOMER :-)\n\n";
            }
            else if ((lt->tm_hour >= 12 and lt->tm_min >= 0) and (lt->tm_hour <= 17 and lt->tm_min <= 59))
            {
                cout << "\nGOOD AFERNOON CUSTOMER :-)\n\n";
            }
            else
            {
                cout << "\nGOOD EVENING CUSTOMER :-)\n\n";
            }
            while (a1)
            {
            top:
                cout << "\nSelect what you want to do?\n\n1)Buy policy\n2)Update the details\n3)Want to see the policies offered\n4)Want to see the exisiting details\n5)Exit\n\nEnter choice: ";
                cin >> opt2;
                switch (opt2)
                {
                case 1:
                    C.fwrite();
                    break;
                case 2:
                    C.updateDetails();
                    break;
                case 3:
                    C.displayPolicyInfo();
                    break;
                case 4:
                    C.searchCustomer();
                    break;
                case 5:
                    goto exit;
                    break;
                default:
                    cout << "\nWrong choice!\n please enter right choice :-)\n";
                    goto top;
                }

                /**************************USING EXCEPTION HANDLING FOR INPUT VALIDATION******************************************/
                // to fix this crash i can use exception handling here which i'm going to use now

                try
                {
                    cout << "\nNOTE: be alert! don't enter character or string below only inetegers!\n";
                    cout << "\nWant to continue as a customer(1/0): ";
                    cin >> a1;
                    if (cin.fail()) // to check if user have entered character or string instead of integer
                    {
                        cin.clear();                                         // to reset the cin into normal mode
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to clear the buffer through which i/p out put takes place since there would be te string or a character in the buffer which user enetred mistakenly in place of 1/0.
                        throw a;
                    }
                }
                catch (...)
                {
                    cout << "\n\nI ALREADY TOLD YOU TO ENTER 1/0 BUT SADLY U ENETERED A STRING OR A CHARACTER -_-!\n\n";
                }
                /**************************USING EXCEPTION HANDLING FOR INPUT VALIDATION******************************************/
            }

            break;
        default:
            cout << "\n\nWrong choice!\n please enter right choice :-)\n";
            break;
        }
        /**************************USING EXCEPTION HANDLING FOR INPUT VALIDATION******************************************/
        // to fix this crash i can use exception handling here which i'm going to use now

        try
        {
            cout << "\nNOTE: be alert! don't enter character or string below only inetegers!\n";
            cout << "\nWant to continue using this system(1/0): ";
            cin >> a1;
            if (cin.fail()) // to check if user have entered character or string instead of integer
            {
                cin.clear();                                         // to reset the cin into normal mode
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to clear the buffer through which i/p out put takes place since there would be te string or a character in the buffer which user enetred mistakenly in place of 1/0.
                throw a;
            }
        }
        catch (...)
        {
            cout << "\n\nI ALREADY TOLD YOU TO ENTER 1/0 BUT SADLY U ENETERED A STRING OR A CHARACTER -_-!\n\n";
        }
        /**************************USING EXCEPTION HANDLING FOR INPUT VALIDATION******************************************/
    exit:;//for exit option in both customer and agent
    }

    return 0;
}
