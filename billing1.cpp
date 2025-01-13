#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t_______________________________________\n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t|          Supermarket Main Menu         \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t_______________________________________\n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 1. Administrator Mode                      \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 2. Buyer Mode                                   \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 3. Exit                                                \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t Please select!";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\t\t\t Pleae Login  \n";
        cout << "\t\t\t Enter Email: \n";
        cin >> email;
        cout << "\t\t\t Enter Password: \n";
        cin >> password;
        if (email == "robby@gmail.com" && password == "robby@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email or password!";
        }
        break;
    case 2:
        buyer();
    case 3:
        exit(0);
    default:
        cout << "Invalid choice!";
        break;
    }
    goto m;
}

void shopping::administrator()
{
m:
    int choice;
    cout << "\t\t\t\t_______________________________________\n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t|          Administrator Mode         \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t_______________________________________\n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 1. Add Product                                   \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 2. Edit Product                                  \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 3. Remove Product                           \n ";
    cout << "\t\t\t\t|                                                           \n ";
    // cout<<"\t\t\t\t| 4. List Product                                      \n ";
    // cout<<"\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 5. Main Menu                                      \n ";
    cout << "\t\t\t\t|                                                           \n ";
    // cout<<"\t\t\t\t| 6. Exit                                                  \n ";
    // cout<<"\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t Please select!";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
        ;
    default:
        cout << "Invalid choice!";
        break;
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t_______________________________________\n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t|          Buyer Mode         \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t_______________________________________\n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 1. Buy Product                                   \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t| 2. Go Back                                         \n ";
    cout << "\t\t\t\t|                                                           \n ";
    cout << "\t\t\t\t Please select!";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "Invalid choice!";
        break;
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t  Add Product\n";
    cout << "\t\t\t  Enter Product Code: ";
    cin >> pcode;
    cout << "\t\t\t  Enter Product Name: ";
    cin >> pname;
    cout << "\t\t\t  Enter Product Price: ";
    cin >> price;
    cout << "\t\t\t  Enter Product Discount: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
    }
    cout << "\n\n\t\t\t  Product Added Successfully!";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t  Edit Product\n";
    cout << "\t\t\t  Enter Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File not found!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\t\t\t  Enter Product new code: ";
                cin >> c;
                cout << "\t\t\t  Enter Product new name: ";
                cin >> n;
                cout << "\t\t\t  Enter Product new price: ";
                cin >> p;
                cout << "\t\t\t  Enter Product new discount: ";
                cin >> d;
                data1 << "" << c << " " << n << " " << p << " " << d << endl;
                cout << "\n\n\t\t\t  Product Edited Successfully!";
                token++;
            }
            else
            {
                data1 << "" << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t  Product not found!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t\t\t  Remove Product\n";
    cout << "\t\t\t  Enter Product Code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File not found!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\t\t  Product Removed Successfully!";
                token++;
            }
            else
            {
                data1 << "" << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t  Product not found!";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_______________________________________________________________________________________|\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "|_______________________________________________________________________________________|\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;
    float dis = 0;

    cout << "\n\n\t\t\t  Receipt\n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File not found!";
    }
    else
    {
        data.close();

        list();
        cout << "\n_____________________________________\n";
        cout << "\n                                                        \n";
        cout << "\n\n         Please place the order        \n ";
        cout << "\n                                                        \n";
        cout << "\n_____________________________________\n";
        do
        {
            m:
            cout << "\n\n\t\t\t  Enter Product Code: ";
            cin >> arrc[c];
            cout << "\t\t\t  Enter Product Quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "Product already added!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n\t\t\t  Do you want to buy another product? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        cout << "\n\n\t\t\t__________________________________Your Receipt________________________________\n";
        cout << "\nProduct No \t Product name \t product quantity \t price \t Amount \t Amount with Discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis << endl;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n_______________________________________________________";
    cout << "\n Total Amount : " << total;
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}

