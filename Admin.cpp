#include "includefiles.h"
#include "backupandrestore.h"
#include "AdminLogin.cpp"

class Manager
{
    private:
            char a,b,c,d,e,f,g,h,i,j,k;
            int dd,mm,yyyy;
            char op=0;

            string Male="Male";
            string Female="Female";
            string Others="Others";

            string male="male";
            string female="female";
            string others="others";

            char alpha(char name)
            {
              if(isalpha(name))
                  {
                    return name;
                  }
              else{
                    cout<<"**Enter Character Only\n";
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
                    cout<<"**Enter Number only\n";
                    return 0;
                }
            }

    public:
            char *getmanagername()
            {
                return name;
            }

            char *getmanagersername()
            {
                return sername;
            }

            void addmanager()
            {
                    cout<<"\n\t\t\t\t Enter Manager Details";
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
                               cout<<"**Please Enter Number Values Only \n";
                               cin.clear();
                               cin.ignore(2000000,'\n');
                               cout<<"\n Enter Contact number:";
                               cin>>contact_no;
                           }

                    if(contact_no>=1000000000 && contact_no<=9999999999)
                        goto f;

                    else
                    {
                        cout<<"** Please Enter Contact number Valid (10 Digits) Only:\n";
                        goto e;
                    }

                f:
                    cout<<"\n Enter Age:";
                    cin>>age;

                    while(!cin.good())
                       {
                           cout<<"**Please Enter Number Values Only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Age:";
                           cin>>age;
                       }
                    if(age>=18 && age<=50)
                        goto g;

                    else
                    {
                        cout<<"** Please Enter Age (18-50) Only:\n";
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
                            cout<<"**Please Enter From following (Male/Female/Others) Only\n";
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
                           cout<<"**Please Enter Number Values Only \n";
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
                               cout<<"**Please Enter Number Values Only \n";
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
                           cout<<"**Please Enter Number Values Only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Salary Rs:";
                           cin>>salary;
                       }
                    if(salary>=500000 && salary<=2000000)
                       {}
                    else
                    {
                        cout<<"**Enter Salary f Yearly RS(500000-2000000)\n";
                        goto k;
                    }

                    time_t now;
                    struct tm nowLocal;
                    now=time(NULL);
                    nowLocal=*localtime(&now);
                    dd=nowLocal.tm_mday;
                    mm=nowLocal.tm_mon+1;
                    yyyy=nowLocal.tm_year+1900;
                    cout<<endl;
                cout<<"\n\t\t\tManager UserName And PassWord System\n";
            }

            void viewmanager(int count)
            {
                cout<<"\n\t\t\t\t"<<count<<"--Manager Details ";
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

    private:
            char username[10],password[10],name[10],middlename[10],sername[10],address[30],gender[7];
            char PAN_NO[11];
            LONGLONG Bank_Acc_no;
            LONGLONG salary;
            LONGLONG contact_no;
            LONGLONG Aadhaar_no;
            unsigned int age;
};

class ManagerDetails : public Manager ,public adminlogin
{
    private:
            int count=0,flag,pk=0,managerswitchchoice;
            char searchi[20];
            ifstream filein;
            ofstream fileout;

    private:
            void AddManager()
            {
                system("cls");
                Manager man;

                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    cout<<"**File Not Present\n";

                else
                {
                    man.addmanager();
                    file.write((char *)&man,sizeof(Manager));
                }
               file.close();

              // adminlogin l;
              //  registerme();
              // l.login();

               Managerswitch();
            }

            void DeleteManager()
            {
                system("cls");
                Manager man;
                flag=0;
                cout<<"\n\n\n\tDelete Record";
                cout<<"\n\nEnter the Product id of the Product to Delete  :  ";
                cin>>searchi;

                filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat",ios::binary | ios::in);
                if(!filein)
                    cout<<"\n**Error: Unable to open file...\n";
                else
                {
                    fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdatanew.dat",ios::binary | ios::out);
                    filein.read((char *)&man, sizeof(Manager));
                    while(!filein.eof())
                    {
                        if(strcmp(searchi,man.getmanagername()))
                        {
                            flag=1;
                            fileout.write((char *)&man, sizeof(Manager));
                        }
                        filein.read((char *)&man, sizeof(Manager));
                    }
                    filein.close();
                    fileout.close();

                    remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat");
                    rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdatanew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat");
                }
                 if(flag==0)
                   cout<<"\n\nSorry!!! Record Not Found ";
                 Managerswitch();
            }

            void UpdateManager()
            {
                flag=0;
                system("cls");
                Manager man;

                cout<<"Enter Aadhaar Card Number of cashier that should be searched:";
                cin>>searchi;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat",ios::binary | ios::out |ios::in);
                if(!file.is_open())
                {
                    cout<<"\n**Error: Unable to open file...\n";
                }
                else
                {
                    file.read((char *)&man,sizeof(Manager));
                    while(!file.eof())
                    {
                          if(strcmp(searchi,man.getmanagername())==0)
                          {
                              flag=1;
                              file.seekg(0,ios::cur);
                              cout<<"\nEnter Updated Record";
                              man.addmanager();
                              file.seekp(file.tellg()-sizeof(Manager));
                              file.write((char *)&man,sizeof(Manager));

                          }
                          file.read((char *)&man,sizeof(Manager));
                    }
               }
               if(flag==0)
               {
                   system("cls");
                   cout<<"\n**No Record Found";
               }
               file.close();
               Managerswitch();
            }

            void ViewManager()
            {
                flag=0;
                system("cls");
                Manager man;
                count=0;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"**error";
                }
                else
                {
                    while(file.read((char *)&man,sizeof(Manager)))
                    {
                               flag=1;
                               count++;
                               man.viewmanager(count);
                    }
                }
                if(flag==0)
                {
                   system("cls");
                   cout<<"\n**No Record Found";
                }
                file.close();
                Managerswitch();
            }

            void SearchManager()
            {
                flag=0;
                system("cls");
                Manager man;

                cout<<"Enter Aadhaar Card Number of cashier that should be searched:";
                cin>>searchi;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\managerdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"error";
                }
                else
                {
                    while(file.read((char *)&man,sizeof(Manager)))
                    {
                       if(strcmp(searchi,man.getmanagername())==0)
                            {
                                flag=1;
                                man.viewmanager(count);
                            }
                    }
               }
               if(flag==0)
               {
                   system("cls");
                   cout<<"\n**No Record Found";
               }
               file.close();
               Managerswitch();
            }

            int getmanagerchoice()
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   Manager Management System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t AddManager \n\t\t\t2.\t DeleteManager \n\t\t\t3.\t SearchManager \n\t\t\t4.\t ViewManager \n\t\t\t5.\t UpdateManager \n\t\t\t6.\t BackUpManagerData \n\t\t\t7.\t RestoreManagerData \n\t\t\t8.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> managerswitchchoice;

                while(!cin.good())
                   {
                       system("cls");
                       cout<<"**Please enter number values only \n";
                       cin.clear();
                       cin.ignore(2000000,'\n');
                            cout<<"\n\n\t\t\t------------------------------";
                            cout<<"\n\t\t\t   Manager Management System";
                            cout<<"\n\t\t\t------------------------------";
                            cout<<"\n\n\t\t\t What you want to do?\n";
                            cout<<"\n\t\t\t1.\t AddManager \n\t\t\t2.\t DeleteManager \n\t\t\t3.\t SearchManager \n\t\t\t4.\t ViewManager \n\t\t\t5.\t UpdateManager \n\t\t\t6.\t BackUpManagerData \n\t\t\t7.\t RestoreManagerData \n\t\t\t8.\t Exit\n";
                            cout<<"\n\nEnter your option: ";
                       cin >> managerswitchchoice;
                   }
                return managerswitchchoice;
            }
    public:
            int Managerswitch()
            {
                int k;
                k:
                managerswitchchoice=getmanagerchoice();
                backupandrestore GBP;
                Manager man;

                switch(managerswitchchoice)
                    {
                        case 1:
                            AddManager();
                            break;
                        case 2:
                            DeleteManager();
                            break;
                        case 3:
                            SearchManager();
                            break;
                        case 4:
                            ViewManager();
                            break;
                        case 5:
                            UpdateManager();
                            break;
                        case 6:
                            GBP.BackUpswitch<Manager>(man);
                            goto k;
                            break;
                        case 7:
                            GBP.Restoreswitch<Manager>(man);
                            goto k;
                            break;
                        case 8:return 0;
                        default:
                                system("cls");
                                cout<<"**Wrong Choice";
                                goto k;
                    }
        }
};
