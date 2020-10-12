//#include "CashierDetails.cpp"
#include "Admin.cpp"

//#include "CustomerDetails.cpp"

#include "DeliveryBoy.cpp"

//#include "RawProduct.cpp"
//#include "MenuSideProduct.cpp"

//#include "MenuPizzaProduct.cpp"

#include "pizzaorder.cpp"

#include "startup.h"
#include "Furniture.h"
#include "includefiles.h"


using namespace std;
int count,contact_no;
//float price;


class Dominoz
{
private:

    int StartUpchoice=0;
    string roll;
    char *p="00";

        int dominozgetownerchoice()
        {
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         Owner Main System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Add Owner \n\t\t\t2.\t Manager System\n\t\t\t3.\t Cashier System \n\t\t\t4.\t Delivery Boy System \n\t\t\t5.\t Menu Side Product System \n \t\t\t6.\t Raw Product System \n \t\t\t7.\t Furniture System \n \t\t\t8.\t Log Out \n";
            cout<<"\n\nEnter Your Option: ";
            cin >> StartUpchoice;

            while(!cin.good())
            {
                cout<<"**Please Enter Number Values Only \n";
                cin.clear();
                cin.ignore(2000000,'\n');
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t         Owner Main System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t Add Owner \n\t\t\t2.\t Manager System\n\t\t\t3.\t Cashier System \n\t\t\t4.\t Delivery Boy System \n\t\t\t5.\t Menu Side Product System \n \t\t\t6.\t Raw Product System \n \t\t\t7.\t Furniture System \n \t\t\t8.\t Log Out \n";
                cout<<"\n\nEnter Your Roll Option: ";
                cin >> StartUpchoice;
            }
            return StartUpchoice;
        }

        int dominozownerswitch()
        {
            StartUpchoice=dominozgetownerchoice();
            ManagerDetails m;
            DeliveryBoy1 d;
            CashierMember c;
            MenuSideProduct msp;
            RawMainProduct rmp;
            FurnitureFun ff;
            switch(StartUpchoice)
                {
                case 1:
                        system("cls");
                        m.registerme();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 2:
                        system("cls");
                        m.Managerswitch();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 3:
                        system("cls");
                        c.cashierswitch();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 4:
                        system("cls");
                        d.deliveryboyswitch();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 5:
                        system("cls");
                        msp.menuproductswitch();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 6:
                        system("cls");
                        rmp.rawproductswitch();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 7:
                        system("cls");
                        ff.furnitureswitch();
                        system("cls");
                        dominozownerswitch();
                    break;
                case 8:
                        return 0;
                    break;
                default:
                        system("cls");
                        cout<<" **Wrong Choice";
                        dominozownerswitch();
            }

        }

        int dominozgetmanagerchoice()
        {
            cout<<"\n\n\t\t\t------------------------------";
            cout<<"\n\t\t\t         Manager Main System   ";
            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
            cout<<"\n\t\t\t1.\t Cashier System \n\t\t\t2.\t Delivery Boy System \n\t\t\t3.\t Menu Side Product System \n \t\t\t4.\t Raw Product System \n \t\t\t5.\t Furniture System \n \t\t\t6.\t Log Out \n";
            cout<<"\n\nEnter Your Roll Option: ";
            cin >> StartUpchoice;

            while(!cin.good())
            {
                cout<<"**Please Enter Number Values Only \n";
                cin.clear();
                cin.ignore(2000000,'\n');
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t         Manager Main System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t Cashier System \n\t\t\t2.\t Delivery Boy System \n\t\t\t3.\t Menu Side Product System \n \t\t\t4.\t Raw Product System \n \t\t\t5.\t Furniture System \n \t\t\t6.\t Log Out \n";
                cout<<"\n\nEnter Your Roll Option: ";
                cin >> StartUpchoice;
            }
            return StartUpchoice;
        }

        int dominozmanagerswitch()
        {
            StartUpchoice=dominozgetmanagerchoice();
            DeliveryBoy1 d;
            CashierMember c;
            MenuSideProduct msp;
            RawMainProduct rmp;
            FurnitureFun ff;
            pizzaorder po;
                                    string u;
                        u="Panda";

            switch(StartUpchoice)
                {
                case 1:
                        system("cls");
                        //po.orderswitch(u);
                        c.cashierswitch();
                        system("cls");
                        dominozmanagerswitch();
                    break;
                case 2:
                        system("cls");
                        d.deliveryboyswitch();
                        system("cls");
                        dominozmanagerswitch();
                    break;
                case 3:
                        system("cls");
                        msp.menuproductswitch();
                        system("cls");
                        dominozmanagerswitch();
                    break;
                case 4:
                        system("cls");
                        rmp.rawproductswitch();
                        system("cls");
                        dominozmanagerswitch();
                    break;
                case 5:
                        system("cls");
                        ff.furnitureswitch();
                        system("cls");
                        dominozmanagerswitch();
                    break;
                case 6:
                        return 0;
                    break;
                default:
                        system("cls");
                        cout<<" **Wrong Choice";
                        dominozownerswitch();
            }

        }

        int rollgetchoice()
        {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t          LogIn System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t Owner Of Dominoz \n\t\t\t2.\t Manager Of Dominoz \n\t\t\t3.\t Cashier Of Dominoz \n\t\t\t4.\t Exit \n";
                cout<<"\n\nEnter Your Roll Option: ";
                cin >> StartUpchoice;

                while(!cin.good())
                {
                    cout<<"**Please Enter Number Values Only \n";
                    cin.clear();
                    cin.ignore(2000000,'\n');
                    cout<<"\n\n\t\t\t------------------------------";
                    cout<<"\n\t\t\t          LogIn System   ";
                    cout<<"\n\t\t\t------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t Owner Of Dominoz \n\t\t\t2.\t Manager Of Dominoz \n\t\t\t3.\t Cashier Of Dominoz \n\t\t\t4.\t Exit \n";
                    cout<<"\n\nEnter Your Roll Option: ";
                    cin >> StartUpchoice;
                }
                return StartUpchoice;
        }


        int ClogIn()
        {
            pizzaorder po;
            CashierMember c;
            string u=c.CashierLogin();
            if(u=="00")
            {
                cout<<"\n3";
            }
            else
            {
                system("cls");
                cout<<"\n2";
                po.orderswitch(u);
            }
            return 0;
        }
        int cashierloginswitch()
        {
            CashierMember cm;
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t          Cashier Log-In System   ";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t Log In \n\t\t\t2.\t Forgot Password \n\t\t\t3.\t Exit \n";
                cout<<"\n\nEnter Your Option: ";
                cin >> StartUpchoice;

                while(!cin.good())
                {
                    cout<<"**Please Enter Number Values Only \n";
                    cin.clear();
                    cin.ignore(2000000,'\n');
                    cout<<"\n\n\t\t\t------------------------------";
                    cout<<"\n\t\t\t          Cashier Log-In System   ";
                    cout<<"\n\t\t\t------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t Log In \n\t\t\t2.\t Forgot Password \n\t\t\t3.\t Exit \n";
                    cout<<"\n\nEnter Your Option: ";
                    cin >> StartUpchoice;
                }
                switch(StartUpchoice)
                {
                case 1:
                        ClogIn();
                        break;
                case 2:
                        cm.ForgotPass();
                        break;
                case 3:
                        return 0;
                default:
                        system("cls");
                        cout<<" **Wrong Choice";
                        cashierloginswitch();

                }
            return 0;

        }
        int AlogIn()
        {

        }

        int MlogIn()
        {

        }


        public:
        int SatrtUp()
            {
                system("cls");
                StartUpchoice=0;
                StartUpchoice=rollgetchoice();
                ManagerDetails m;
                switch(StartUpchoice)
                    {
                    case 1:
                        roll="Owner";
                        system("cls");
                        if(m.login(roll)==1)
                        {
                            cout<<"OK";
                            system("cls");
                            dominozownerswitch();
                            system("cls");
                            SatrtUp();
                        }
                        system("cls");
                        SatrtUp();
                        break;
                    case 2:
                        roll="Manager";
                        system("cls");
                        if(m.login(roll)==1)
                        {
                            dominozmanagerswitch();
                            system("cls");
                            SatrtUp();
                        }
                        system("cls");
                        SatrtUp();
                        break;
                    case 3:
                        roll="Cashier";
                        system("cls");
                        cashierloginswitch();
                        SatrtUp();
                        break;
                    case 4:
                        return 0;

                    default:
                            system("cls");
                            cout<<" **Wrong Choice";
                            SatrtUp();
                }
            }
};


int main()
{

    //system("cls");
    // administratorPowerPolicy admin;

    //admin.mainmenu();
    //admin.ff();

    // DeliveryBoy1 d;
    // d.deliveryboyswitch();

    // CashierMember p;
    // p.cashierswitch();

   //  ManagerDetails m;
   //  m.Managerswitch();

   // FurnitureFun f;
   // f.furnitureswitch();

   // CustomerDetailsData cdd;
   // cdd.mainmenu();

    //RawMainProduct RMP;
    //RMP.rawproductswitch();

  // MenuSideProduct msp;
  // msp.menuproductswitch();

   //MenuPizza mp;

   //mp.AddPizzaProduct();

   //mp.getpizzaproductswitch();



    Dominoz d;
    d.SatrtUp();



        //startup s;
        //s.LoadLogo();

        //system("cls");
       // MenuPizza m;
       // m.getpizzaproductswitch();



       // pizzaorder po;
      //  po.orderswitch();

       // discount d;
       // d.discountswitch();


        //s.backuploader();

       // pizzamenue p;
       // p.ViewPizza();
       // p.AddPizza();
       // p.ViewPizza();

    return 0;
    }




