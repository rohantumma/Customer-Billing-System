#include "order.h"
#include "includefiles.h"

#include "C:\Users\rohan\Google Drive\project7\MenuSideProduct.cpp"
#include "C:\Users\rohan\Google Drive\project7\RawProduct.cpp"
#include "C:\Users\rohan\Google Drive\project7\MenuPizzaProduct.cpp"





order::order()
{
    //ctor
}

order::~order()
{
    //dtor
}

order :: orderchoice()
{
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         Order System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Take Order \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Log Out \n";
            cout<<"\n\nEnter Your Option: ";
            cin >> OrderChoice;

            while(!cin.good())
            {
                cout<<"**Please Enter Number Values Only \n";
                cin.clear();
                cin.ignore(2000000,'\n');
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t         Owner Main System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t Take Order \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Log Out \n";
                cout<<"\n\nEnter Your Roll Option: ";
                cin >> OrderChoice;
            }
            return OrderChoice;
}

order :: orderswitch()
{
    OrderChoice=orderchoice();
    switch(OrderChoice)
        {
        case 1:
            takeorder();
            system("cls");
            orderswitch();
            break;
        case 2:
            deleteorder();
            system("cls");
            orderswitch();
            break;
        case 3:
            return 0;
        default:
                system("cls");
                cout<<" **Wrong Choice\n";
                orderswitch();
    }

}

order :: takeorderchoice()
{
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         Order Choice System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Pizza Order \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Log Out \n";
            cout<<"\n\nEnter Your Option: ";
            cin >> OrderChoice;

            while(!cin.good())
            {
                cout<<"**Please Enter Number Values Only \n";
                cin.clear();
                cin.ignore(2000000,'\n');
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t         Order Choice System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t Pizza Order \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Log Out \n";
                cout<<"\n\nEnter Your Option: ";
                cin >> OrderChoice;
            }
            return OrderChoice;
}

order ::takeorder()
{
    OrderChoice=takeorderchoice();
    MenuPizza MP;
    switch(OrderChoice)
        {
        case 1:
            system("cls");
            MP.ViewPizzaProduct();
            prize=MP.TakeProduct();
            cout<<prize;
            break;
        case 2:
            //deleteorder();
            system("cls");
            //orderswitch();
            break;
        case 3:
            return 0;
        default:
                system("cls");
                cout<<" **Wrong Choice\n";
                takeorder();
        }
}


order :: deleteorder()
{

}


