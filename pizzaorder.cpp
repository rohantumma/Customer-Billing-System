#include "includefiles.h"

#include "RawProduct.cpp"
#include "CashierDetails.cpp"
#include "MenuSideProduct.cpp"
#include "MenuPizzaProduct.cpp"



class pizzaorder : public Pizza , public discount
{
    private:
            string cashieruname;
            int flag;

    public:

            float prize=0;
            int OrderChoice;

            int orderswitch(string cashieruname)
            {
                OrderChoice=orderchoice(cashieruname);
                switch(OrderChoice)
                    {
                    case 1:
                        takeorder(cashieruname);
                        system("cls");
                        orderswitch(cashieruname);
                        break;
                    case 2:
                        //deleteorder();
                        system("cls");
                        orderswitch(cashieruname);
                        break;
                    case 3:
                        return 0;
                    default:
                            system("cls");
                            cout<<" **Wrong Choice\n";
                            orderswitch(cashieruname);
                }

            }

            int takeorder(string cashieruname)
            {
            OrderChoice=takeorderchoice();
            MenuPizza m;
            switch(OrderChoice)
                {
                case 1:
                    //m.
                    prize=m.takeorderpizza();
                    flag=1;
                    takeorder(cashieruname);
                    break;
                case 2:
                    prize=m.takeorderproduct();
                    flag=1;
                    takeorder(cashieruname);
                    break;
                case 3:
                    if(flag==1)
                    {
                        pizzaprice=m.takeprintbill(cashieruname);
                        flag=0;
                        orderconfirmswitch();
                    }
                    else
                         takeorder(cashieruname);
                    //orderswitch();
                    break;
                case 4:
                    m.getpizzaproductswitch();
                    system("cls");
                        //cin>>pizzaprice;
                        break;
                case 5:
                        return 0;
                default:
                        system("cls");
                        cout<<" **Wrong Choice\n";
                        takeorder(cashieruname);
                }
            }

            int orderconfirmswitch()
            {
                OrderChoice=orderconfirmchoice();
                MenuPizza m;
                switch(OrderChoice)
                    {
                    case 1:
                        orderpaymentswitch();
                        orderswitch(cashieruname);
                        break;
                    case 2:
                        m.deleteorder();
                        orderswitch(cashieruname);
                        break;
                    case 3:
                            return 0;
                    default:
                            system("cls");
                            cout<<" **Wrong Choice\n";
                            orderconfirmswitch();
                    }

            }

            int orderpaymentswitch()
            {
                OrderChoice=orderpaymentchoice();
                MenuPizza m;
                switch(OrderChoice)
                    {
                    case 1:
                        orderswitch(cashieruname);
                        break;
                    case 2:
                            m.deleteorder();
                            return 0;
                    default:
                            system("cls");
                            cout<<" **Wrong Choice\n";
                            orderconfirmswitch();
                    }
            }






            int orderpaymentchoice()
            {
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         PayMent Confirm System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Take Payment  \n\t\t\t2.\t Exit \n";
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
                cout<<"\n\t\t\t1.\t Order Confirm  \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Exit \n";
                cout<<"\n\nEnter Your Option: ";
                cin >> OrderChoice;
            }
            return OrderChoice;

            }

            int orderconfirmchoice()
            {
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         Order Confirm System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Order Confirm  \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Exit \n";
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
                cout<<"\n\t\t\t1.\t Order Confirm  \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Exit \n";
                cout<<"\n\nEnter Your Option: ";
                cin >> OrderChoice;
            }
            return OrderChoice;
            }

            int takeorderchoice()
            {
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         Order Choice System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Pizza Order \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Print Bill. \n";
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
                cout<<"\n\t\t\t1.\t Pizza Order \n\t\t\t2.\t Delete Order \n\t\t\t3.\t Print Bill. \n";
                cout<<"\n\nEnter Your Option: ";
                cin >> OrderChoice;
            }
            return OrderChoice;
}

            int orderchoice(string cashieruname)
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t         Order System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\t\t\tCashier User Name:"<<cashieruname;
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

};

