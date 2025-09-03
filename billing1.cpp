//
// Created by Mobarak Inuwa on 03/09/2025.
//
#include <iostream>
#include<fstream>

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
            void reciept();

}

void shopping::menu()
{
    m;
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t_______________________________________________\n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t            Supermarket Main Menu               \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t_______________________________________________\n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t   1.) Administrator |\n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t   2.) Buyer         |\n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t   3.) Exit         |\n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t_______________________________________________\n";
    cout<<"\t\t\t\tPlease select!";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t\t Please Login: ";
            cout<<"\t\t\t\t Please Email: ";
            cin>>email;
            cout<<"\t\t\t\t Please Password: ";

            if(email=="admin" && password=="admin")
            {
                administrator();
            }
            else
            {
                cout<<"\t\t\t\t Wrong Password!";
            }
            break;

    }
        case 2:
    {
            buyer();
    }

        case 3:
    {
            exit(0);
    }

    default:
        {
            cout<<"\t\t\t\t Wrong Choice!";
        }

}
goto m;

void shopping::administrator()
{
    m;
    int choice;
    cout<<"\t\t\t\t 1. Administrator |\n";
    cout<<"\t\t\t\t |__________ 1.) Add the product_________|\n";
    cout<<"\t\t\t\t                                         |\n";
    cout<<"\t\t\t\t |__________ 2.) Modify the product______|\n";
    cout<<"\t\t\t\t                                         |\n";
    cout<<"\t\t\t\t |__________ 3.) Delete the product______|\n";
    cout<<"\t\t\t\t                                         |\n";
    cout<<"\t\t\t\t |__________ 4.) Back to main menu_______|\n";

    cout<<"\t\t\t\t Please enter your choice \n";
    cin>>choice;

    switch(choice)
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

        default:
            cout<<"\t\t\t\t Wrong Choice!";

    }
    goto m;

}

void shopping::buyer()
{
    int choice;
    cout<<"\t\t\t\t |_________ 1. Buyer _________|\n";
    cout<<"\t\t\t\t |                            |\n";
    cout<<"\t\t\t\t |_______ Buy product ________|\n";
    cout<<"\t\t\t\t |                            |\n";
    cout<<"\t\t\t\t |_________ Go back __________|\n";
    cout<<"\t\t\t\t |__Please enter your choice__|\n";

    cin>>choice;

    switch(choice)
    {
        case 1:
            reciept();

        case 2:
            menu();

        default:
            cout<<"\t\t\t\t Wrong Choice!";

    }

    goto m;

}

void shopping::add()
{
    m;
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\t\t\t\t | Add New Product |\n";
    cout<<"\t\t\t\t | Product code of the item |\n";
    cin>>pcode;
    cout<<"\t\t\t\t | Name of the product |\n";
    cin>>pname;
    cout<<"\t\t\t\t | Dicount the product |\n";
    cin>>dis;

    data.open("product.txt", ios::in);

    if(data.fail() || !data)
    {
        data.open("product.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;

            }
            data>>c>>n>>p>>d;
        }
        data.close();


    }

    if(token==1);
        goto m;
    else{
        data.open("product.txt", ios::app|ios::out);
        data<<" "pcode<<" "<<pname<<" "<<price<<" "<<d<<"\n";
        data.close();

    }
    cout<<"\t\t\t\t Record inserted!";
}
