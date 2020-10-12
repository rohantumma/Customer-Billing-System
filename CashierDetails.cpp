#include "includefiles.h"
#include "backupandrestore.h"
#include "cashierlogin.cpp"

class cashierdetails
{
    private:
            char p[25];

            char a,b,c,d,e,f,g,h,i,j,k;
            char op=0;
            int dd,mm,yyyy;

            string Male="Male";
            string Female="Female";
            string Others="Others";
            string uname;
            string male="male";
            string female="female";
            string others="others";

    public:
            int Cashierid=0;
            char name[10],middlename[10],sername[10],address[30],PAN_NO[11],gender[5];
            LONGLONG Bank_Acc_no;
            LONGLONG salary;
            LONGLONG contact_no;
            LONGLONG Aadhaar_no;
            unsigned int age;


            string line;

            char alpha(char name)
            {
              if(isalpha(name))
              {
                return name;
              }
              else{
                    cout<<"**Enter char only";
                    return 0;
                  }
            }

            int digit(LONGLONG contact_no)
            {
              if(isdigit(contact_no))
              {
                return 1;
              }
              else
                {
                    cout<<"**Enter Number only";
                    return 0;
                }
            }
    public:

            char *getuname()
            {
                return p;
            }
            char *getcashiername()
            {
                return name;
            }

            char *getcashiersername()
            {
                return sername;
            }

            LONGLONG getphonenumber()
            {
                return contact_no;
            }

            void addcashier()
            {
                ifstream CashierPass;
                CashierPass.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\Cashierid.txt");
                getline(CashierPass, line);
                stringstream Cashierin(line);
                Cashierin>>Cashierid;

                Cashierid++;
                CashierPass.close();

                    cout<<"\n\t\t\t\t Enter Cashier Details";
                a:
                    cout<<"\n Enter Name(name-middlename-sername):";
                    cin>>name;
                    if(alpha(*name)!=0)
                        {
                            if(strlen(name)>=2)
                                goto b;
                            else
                            {
                                cout<<"**Please Enter Valid Name\n";
                                goto a;
                            }
                        }
                    else
                        goto a;
                b:
                    cin>>middlename;
                    if(alpha(*middlename)!=0)
                        {
                            if(strlen(middlename)>=1)
                                goto c;
                            else
                            {
                                cout<<"**Please Enter Valid MiddleName\n";
                                goto b;
                            }
                        }
                    else
                        goto b;
                c:
                    cin>>sername;
                    if(alpha(*sername)!=0)
                        {
                            if(strlen(sername)>=2)
                                goto d;
                            else
                            {
                                cout<<"**Please Enter Valid SerName\n";
                                goto c;
                            }
                        }
                    else
                        goto c;
                d:
                    cout<<"\n Enter Address:";
                    cin>>address;
                        if(strlen(address)>=10 && strlen(address)<=50)
                           goto e;
                        else
                        {
                           cout<<"\n**Enter Address valid (Minimum 10 characters And Maximum) only\n";
                           goto d;
                        }
                e:
                    cout<<"\n Enter Contact number:";
                    cin>>contact_no;
                        while(!cin.good())
                        {
                           cout<<"\n**Please enter number values only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Contact number:";
                           cin>>contact_no;
                        }

                        if(contact_no>=1000000000 && contact_no<=9999999999)
                            {
                                goto f;
                            }
                        else
                        {
                            cout<<"** Enter Contact number Valid (10 Digits) Only:\n";
                            goto e;
                        }

                f:
                    cout<<"\n Enter Age:";
                    cin>>age;
                        while(!cin.good())
                        {
                           cout<<"**Please enter number values only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Age (18-50) Only:";
                           cin>>age;
                        }
                        if(age>=18 && age<=50)
                            goto g;
                        else
                        {
                            cout<<"** Enter Age (18-50) Only:\n";
                            goto f;
                        }
                g:
                    cout<<"\n Enter Gender:";
                    cin>>gender;
                    if(alpha(*gender)!=0)
                    {
                        string comparegender(gender);
                            if((comparegender==Male || comparegender==Female || comparegender==Others || comparegender==male || comparegender==female || comparegender==others)!=0)
                                goto h;
                            else
                            {   cout<<"**Please Enter From following (Male/Female/Others) Only\n";
                                goto g;
                            }
                    }
                    else
                    {
                            cout<<"**Enter male/female only\n";
                            goto g;
                    }
                h:
                    cout<<"\n Enter PAN Card Number:";
                    cin>>PAN_NO;
                    if(strlen(PAN_NO)==10)
                       goto i;
                    else
                    {
                        cout<<"\n **Enter Pan Card Number valid (10 char) only";
                        goto h;
                    }

                i:
                    cout<<"\n Enter Aadhaar Card number:";
                    cin>>Aadhaar_no;
                    while(!cin.good())
                    {
                       cout<<"**Please enter number values only \n";
                       cin.clear();
                       cin.ignore(2000000,'\n');
                       cout<<"\n Enter Aadhaar Card number:";
                       cin>>Aadhaar_no;
                    }
                    if(Aadhaar_no>=100000000000 && Aadhaar_no<=999999999999)
                        goto j;
                    else
                    {
                        cout<<"**Please Enter Valid Aadhaar Card Number Only \n";
                        goto i;
                    }
                j:
                    cout<<"\n Enter Bank Account number:";
                    cin>>Bank_Acc_no;
                     while(!cin.good())
                           {
                               cout<<"**Please enter number values only \n";
                               cin.clear();
                               cin.ignore(2000000,'\n');
                               cout<<"\n Enter Bank Account number:";
                               cin>>Bank_Acc_no;
                           }
                    if(Bank_Acc_no>=1000000000000000 && Bank_Acc_no<=9999999999999999)
                        goto k;
                    else
                    {
                        cout<<"**Please Enter Valid  Bank Account Number Only \n";
                        goto j;
                    }
                k:
                    cout<<"\n Enter Salary Rs:";
                    cin>>salary;
                     while(!cin.good())
                       {
                           cout<<"**Please enter number values only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Salary of yearly (200000-2000000)Rs:";
                           cin>>salary;
                       }
                    if(salary>=200000 && salary<=2000000)
                    {
                    }
                    else
                    {
                        goto k;
                    }

                    ofstream Cashierout;
                    string file = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\Cashierid.txt";
                    Cashierout.open(file.c_str());
                    Cashierout<<Cashierid;
                    Cashierout.close();

                    llogin l;

                    uname=l.registerme();

                    p[uname.length()];
                        for (i = 0; i < sizeof(p); i++)
                            p[i] = uname[i];


                    //l.username;
                    time_t now;
                    struct tm nowLocal;
                    now=time(NULL);
                    nowLocal=*localtime(&now);
                    dd=nowLocal.tm_mday;
                    mm=nowLocal.tm_mon+1;
                    yyyy=nowLocal.tm_year+1900;
                    cout<<endl;
            }

            void viewcashier(int count)
            {
                cout<<"\n\t\t\t\t"<<count<<"--Cashier Details ";
                cout<<"\n Cashier User Name:"<<p;
                cout<<"\n Name(name-middlename-sername):"<<name<<" "<<middlename<<" "<<sername;
                cout<<"\n Address:"<<address;
                cout<<"\n Contact number:"<<contact_no;
                cout<<"\n Age:"<<age;
                cout<<"\n Gender:"<<gender;
                cout<<"\n PAN Card Number:"<<PAN_NO;
                cout<<"\n Aadhaar Card number:"<<Aadhaar_no;
                cout<<"\n Bank Account number:"<<Bank_Acc_no;
                cout<<"\n Salary Rs:"<<salary;
                cout<<"\n Join-Date:"<<dd<<"/"<<mm<<"/"<<yyyy;
            }
};

class CashierMember: public cashierdetails, public llogin
{
     private:
            int count=0;
            int pk=0;
            int cashierswitchchoice;
            char searchi[20];
            char searchii[20];
            LONGLONG ForgotPassPhoneNumber;
            int flag;


            ifstream filein;
            ofstream fileout;

            void AddCashier()
            {
                system("cls");
                cashierdetails cha;

                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    cout<<"\n**Error: Unable to open file...\n";
                else
                {
                    cha.addcashier();
                    file.write((char *)&cha,sizeof(cashierdetails));
                }
               file.close();

               //l.login();

               cashierswitch();
            }

            void DeleteCashier()
            {
                system("cls");
                cashierdetails cha;
                flag=0;

                cout<<"\n\n\n\tDelete Record";
                cout<<"\n\nEnter First Name and SerName of Cashier to Delete  :  ";
                cin>>searchi;
                cin>>searchii;

                filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::in);
                if(!filein)
                {
                    cout<<"\n**Error: Unable to open file...\n";
                    flag=1;
                }

                else
                {
                    system("cls");
                    fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdatapp.dat",ios::binary | ios::out);
                    filein.read((char *)&cha, sizeof(cashierdetails));

                    while(!filein.eof())
                        {
                            if(strcmp(searchi,cha.getcashiername()) && strcmp(searchii,cha.getcashiersername()) )
                                {
                                    flag=1;
                                    fileout.write((char *)&cha, sizeof(cashierdetails));
                                }
                            filein.read((char *)&cha, sizeof(cashierdetails));
                        }
                    filein.close();
                    fileout.close();

                    remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat");
                    rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdatapp.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat");
                }
                 if(flag==0)
                   cout<<"\nSorry!!! Record Not Found ";

                 cashierswitch();
            }

            void UpdatCahier()
            {
                flag=0;
                system("cls");
                cashierdetails cha;
                cout<<"Enter Aadhaar Card Number of cashier that should be searched:";
                cin>>searchi;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::out |ios::in);
                if(!file.is_open())
                     cout<<"\n**Error: Unable to open file...\n";
                else
                {
                    while(file.read((char *)&cha,sizeof(cashierdetails)))
                    {
                          if(strcmp(searchi,cha.getcashiername())==0)
                          {
                              file.seekg(0,ios::cur);
                              cout<<"\nenter new record";
                              cha.addcashier();
                              file.seekp(file.tellg()-sizeof(cashierdetails));
                              file.write((char *)&cha,sizeof(cashierdetails));
                              flag=1;
                          }
                    }
               }
               if(flag==0)
               {
                   system("cls");
                   cout<<"\n**No Record Found";
               }
               file.close();

               cashierswitch();
            }

            void ViewCashier()
            {
                flag=0;
                system("cls");
                cashierdetails cha;
                count=0;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    cout<<"**error";
                else
                {
                    while(file.read((char *)&cha,sizeof(cashierdetails)))
                    {
                               flag=1;
                               count++;
                               cha.viewcashier(count);
                    }
                }
                if(flag==0)
                {
                   system("cls");
                   cout<<"\n**No Record Found";
                }
                file.close();

                cashierswitch();
            }

            void SearchCashier()
            {
                flag=0;
                system("cls");
                cashierdetails cha;

                cout<<"Enter Aadhaar Card Number of cashier that should be searched:";
                cin>>searchi;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    cout<<"error";
                else
                {
                    while(file.read((char *)&cha,sizeof(cashierdetails)))
                    {
                               if(strcmp(searchi,cha.getcashiername())==0)
                                    {
                                        flag=1;
                                        cha.viewcashier(count);
                                    }
                    }
               }
               if(flag==0)
               {
                   system("cls");
                   cout<<"\n**No Record Found";
               }
               file.close();

               cashierswitch();
            }
    public:

            int ForgotPass()
            {
                flag=0;
                cashierdetails cha;
                string m;
                cout<<"Enter Phone Number:";
                cin>>ForgotPassPhoneNumber;
                LONGLONG demono;
                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    cout<<"error";
                else
                {
                    while(file.read((char *)&cha,sizeof(cashierdetails)))
                    {
                               if(ForgotPassPhoneNumber==cha.getphonenumber())
                                    {
                                            flag=1;
                                            demono=cha.getphonenumber();
                                            m=cha.getuname();
                                    }
                    }
               }
               file.close();
cout<<"1\n";
                if(flag==0)
               {
                   system("cls");
                   cout<<"\n**No Record Found";
               }
cout<<"2\n";

                    ofstream logintime;
                    string filee = "L:\\xampp\\htdocs\\tmp.txt";
                    logintime.open(filee.c_str());
                    logintime<<91;
                    logintime<<demono;
                    logintime.close();
        cout<<"3\n";

                    ofstream op;
                    string mmmmm = "L:\\xampp\\htdocs\\code.txt";
                    op.open(mmmmm.c_str());
                    op<<"0099";
                    op.close();
cout<<"4\n";

                    llogin ll;
                    string u;
                    cout<<"\n Enter OTP:";
                    cin>>u;
                    cout<<u;

                    remove("L:\\xampp\\htdocs\\tmp.txt");
                    remove("L:\\xampp\\htdocs\\code.txt");
                    if(u=="0099")
                    {
                        ll.forgotpassword(m);
                        cout<<"5\n";
                    }
                    else
                    {
                        cout<<"6\n";
                    }
                cout<<"7\n";
            }

            int getcashierchoice()
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   Cashier Management System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t AddCashier \n\t\t\t2.\t DeleteCashier \n\t\t\t3.\t SearchCashier \n\t\t\t4.\t ViewCashier \n\t\t\t5.\t UpdatCahier \n\t\t\t6.\t BackUpCashierData \n\t\t\t7.\t RestoreCashierData \n\t\t\t8.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> cashierswitchchoice;

                while(!cin.good())
                   {
                       system("cls");
                       cout<<"**Please enter number values only \n";
                       cin.clear();
                       cin.ignore(2000000,'\n');
                            cout<<"\n\n\t\t\t------------------------------";
                            cout<<"\n\t\t\t   Cashier Management System";
                            cout<<"\n\t\t\t------------------------------";
                            cout<<"\n\n\t\t\t What you want to do?\n";
                            cout<<"\n\t\t\t1.\t AddCashier \n\t\t\t2.\t DeleteCashier \n\t\t\t3.\t SearchCashier \n\t\t\t4.\t ViewCashier \n\t\t\t5.\t UpdatCahier \n\t\t\t6.\t BackUpCashierData \n\t\t\t7.\t RestoreCashierData \n\t\t\t8.\t Exit\n";
                            cout<<"\n\nEnter your option: ";
                       cin >> cashierswitchchoice;
                   }
                return cashierswitchchoice;
            }

            int cashierswitch()
            {
                k:
                cashierswitchchoice=getcashierchoice();
                backupandrestore GBP;
                cashierdetails cha;

                switch(cashierswitchchoice)
                    {
                        case 1:
                            AddCashier();
                            break;
                        case 2:
                            DeleteCashier();
                            break;
                        case 3:
                            SearchCashier();
                            break;
                        case 4:
                            ViewCashier();
                            break;
                        case 5:
                            UpdatCahier();
                            break;
                        case 6:
                            GBP.BackUpswitch<cashierdetails>(cha);
                            goto k;
                            break;
                        case 7:
                            GBP.Restoreswitch<cashierdetails>(cha);
                            goto k;
                            break;
                        case 8:return 0;
                        default:
                                system("cls");
                                cout<<"**Wrong Choice";
                                goto k;
                    }
        }

            string CashierLogin()
            {
                cashierdetails cha;
                llogin l;
                cout<<"\n11\n";
                char *getusername=l.login();
                cout<<"\ngetusername==="<<getusername;
                char *ll="00";
                if(strcmp(getusername,ll)!=0)
                {
                    cout<<"getusername:"<<getusername;

                    fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary | ios::out |ios::in| ios::app);
                    if(!file.is_open())
                        cout<<"error";
                    else
                    {
                        while(file.read((char *)&cha,sizeof(cashierdetails)))
                        {
                                   if(strcmp(getusername,cha.getuname())==0)
                                        {
                                            flag=1;
                                            cout<<cha.getuname()<<endl;
                                            cout<<cha.getcashiername();
                                            //cin>>getusername;
                                            string uname;
                                            string usname;
                                            uname=cha.getcashiername();

                                            usname=cha.getcashiersername();
                                            string ufname;
                                            ufname=uname+" "+usname;
                                            return ufname;
                                        }
                        }
                   }
                }
            else
                cout<<"Cashier login else part\n";
               return "00";
            }
};
