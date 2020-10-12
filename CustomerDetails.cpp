#include "includefiles.h"

class CustomerDetails
{
    private:
            char customerfirstname[15],customermiddlename[15],customerlastname[15],address1[50],address2[50];
            int a,b,c,d,e,f,g;
            int length_address,length_address2,length_gender;
            char favourite_list[20];
            LONGLONG contact_no;

            int id=0;
            int dd,mm,yyyy;

            char ch,gender[7];
            char *gen1="male";
            char *gen2="female";
            char *gen3="others";
            char *gen11="Male";
            char *gen22="Female";
            char *gen33="Others";

    public:
            int count=0;
            int flag=0;
            //Check Entered Data is Character or not
            char alpha(char customerfirstname)
                {
                  if(isalpha(customerfirstname))
                  {
                    return customerfirstname;
                  }
                  else{
                        cout<<"\n **Enter char only";
                        return 0;
                      }
                }
            //Check Entered Data is Digit or not
            int digit(long contact_no)
                {
                  if(isdigit(contact_no))
                  {
                    return 1;
                  }
                  else
                    {
                        cout<<"\n **Enter Number only";
                        return 0;
                    }
                }
            //Get Customer First Name
            char *getcustomerfirstname()
                {
                    return customerfirstname;
                }
            char *getcustomermiddlename()
                {
                    return customermiddlename;
                }
            //Get Customer Last Name
            char *getcustomerlastname()
                {
                    return customerlastname;
                }
            //Add Function For Adding Irregular Customer only Face To Face Customers
            void facetoface()
                {
                       a:
                               cout<<"\n Enter Full name(first,middle,last):";
                               cin>>customerfirstname;
                               if(alpha(*customerfirstname)!=0)
                               {
                                   goto b;
                               }
                               else
                               {
                                   goto a;
                               }
                        b:
                                cin>>customermiddlename;
                                if(alpha(*customermiddlename)!=0)
                                {
                                    goto c;
                                }
                                else
                                {
                                    goto b;
                                }

                        c:
                               cin>>customerlastname;
                               if(alpha(*customerlastname)!=0)
                                {

                                }
                                else
                                {
                                    goto c;
                                }
                }
            //Add Function For Adding Irregular Customer only By Call Customers
            void bycall()
                {
                       a:
                               cout<<"\n Enter Full name(first,middle,last):";
                               cin>>customerfirstname;
                               if(alpha(*customerfirstname)!=0)
                               {
                                   goto b;
                               }
                               else
                               {
                                   goto a;
                               }
                        b:
                                cin>>customermiddlename;
                                if(alpha(*customermiddlename)!=0)
                                {
                                    goto c;
                                }
                                else
                                {
                                    goto b;
                                }

                        c:
                               cin>>customerlastname;
                               if(alpha(*customerlastname)!=0)
                                {
                                    goto d;
                                }
                                else
                                {
                                    goto c;
                                }
                        d:
                               cout<<"\n Enter address:";
                               cin>>address1;
                               length_address=strlen(address1);
                               if(length_address>=10 && length_address<=50)
                               {
                                   goto e;
                               }
                               else{
                                   cout<<"**Enter Address valid (Minimum 10 characters And Maximum 50) only\n";
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
                        f:      cout<<endl;
                }
            //Add Function For Adding Regular Customer
            void addregularcustomer()
                {

                        a:
                               cout<<"\n Enter Full name(first,middle,last):";
                               cin>>customerfirstname;
                               if(alpha(*customerfirstname)!=0)
                               {
                                   goto b;
                               }
                               else
                               {
                                   goto a;
                               }
                        b:
                                cin>>customermiddlename;
                                if(alpha(*customermiddlename)!=0)
                                {
                                    goto c;
                                }
                                else
                                {
                                    goto b;
                                }

                        c:
                               cin>>customerlastname;
                               if(alpha(*customerlastname)!=0)
                                {
                                    goto d;
                                }
                                else
                                {
                                    goto c;
                                }
                        d:
                               cout<<"\n Enter Address 1:";
                               cin>>address1;
                               if(strlen(address1)>=10 && strlen(address1)<=50)
                               {
                                   goto e;
                               }
                               else{
                                   cout<<"\n **Enter Address valid (Minimum 10 characters And Maximum) only";
                                    goto d;
                               }
                        e:
                               cout<<"\n If You want to insert Alternative Address (y/n?):";
                               cin>>ch;
                               if(ch=='Y'|| ch=='y')
                               {
                                 cout<<"\n Enter Address 2:";
                                 cin>>address2;
                                   if(strlen(address2)>=10 && strlen(address2)<=50)
                                   {
                                       goto f;
                                   }
                                   else{
                                       cout<<"\n **Enter Address valid (Minimum 10 characters And Maximum) only";
                                        goto e;
                                   }
                               }
                               else
                               {
                                   goto f;
                               }
                        f:
                                cout<<"\n Enter Contact number:";
                                cin>>contact_no;
                                while(!cin.good())
                                    {
                                        cout<<"\n **Please enter number values only ";
                                        cin.clear();
                                        cin.ignore(2000000,'\n');
                                        cout<<"\n Enter Contact number:";
                                        cin>>contact_no;
                                    }
                                if(contact_no>=1000000000 && contact_no<=9999999999)
                                {

                                    goto g;
                                }
                                else
                                {
                                    cout<<"\n **Enter Contact number Valid (10 Digits) Only:";
                                    goto f;
                                }

                        g:
                            cout<<"\n Enter Gender(male/female):";
                            cin>>gender;
                            if (strcmp(gender,gen1)==0 || strcmp(gender,gen2)==0 ||strcmp(gender,gen3)==0 ||strcmp(gender,gen11)==0 || strcmp(gender,gen22)==0 ||strcmp(gender,gen33)==0)
                            {
                                goto h;
                            }
                            else
                            {
                                cout<<"\n **Enter Gender valid (male/female) only";
                                goto g;
                            }

                        h:
                            //for getting system date
                                time_t now;
                                struct tm nowLocal;
                                now=time(NULL);
                                nowLocal=*localtime(&now);
                                dd=nowLocal.tm_mday;
                                mm=nowLocal.tm_mon+1;
                                yyyy=nowLocal.tm_year+1900;
                                cout<<endl;
                }
            //Display Function For Irregular Customer Only Face To Face
            void showfacetoface(int count)
                {
                    cout<<"\n\t\t\t\t"<<count<<"--Customer Details ";
                    cout<<"\nName:"<<customerfirstname<<" "<<customermiddlename<<" "<<customerlastname;
                }
            //Display Function For Irregular Customer Only By Call Customers
            void showbycall(int count)
                {
                    cout<<"\n\t\t\t\t"<<count<<"--Customer Details ";
                    cout<<"\nName:"<<customerfirstname<<" "<<customermiddlename<<" "<<customerlastname;
                    cout<<"\nAddress:"<<address1;
                    cout<<"\nContact No:"<<contact_no;
                }
                //Display Function For Regular Customer
            void showregularcustomer(int count)
                {
                    cout<<"\n\t\t\t\t"<<count<<"--Customer Details ";
                    cout<<"\n Customer ID:"<<count;
                    cout<<"\n Name:"<<customerfirstname<<" "<<customermiddlename<<" "<<customerlastname;
                    cout<<"\n Address 1:"<<address1;
                    cout<<"\n Address 2:"<<address2;
                    cout<<"\n Contact No:"<<contact_no;
                    cout<<"\n Gender:"<<gender;
                    cout<<"\n Join-Date:"<<dd<<"/"<<mm<<"/"<<yyyy;
                }
};

class CustomerDetailsData: private CustomerDetails
{
    private :
            char searchcustomerfirstname[20],searchcustomerlastname[20];
            int customerswitchchoice,regularcustomerswitchchoice,mainmenuswitchchoice;
            //Get User Choice For Irregular Customer Choice
            int getirregularcustomerchoice()
                {
                    cout<<"\n\n\t\t\t-----------------------------------";
                    cout<<"\n\t\t\t Irregular Customer Management System";
                    cout<<"\n\t\t\t-----------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t Add Face to Face \n\t\t\t2.\t Add By Call \n\t\t\t3.\t View Face to Face Customer\n\t\t\t4.\t View By Call Customer\n\t\t\t5.\t Back\n";

                    cout<<"\n\n Enter your option: ";
                    cin >> customerswitchchoice;
                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"\n **Please enter number values only...";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t-----------------------------------";
                        cout<<"\n\t\t\t Irregular Customer Management System";
                        cout<<"\n\t\t\t-----------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t Add Face to Face \n\t\t\t2.\t Add By Call \n\t\t\t3.\t View Face to Face Customer\n\t\t\t4.\t View By Call Customer\n\t\t\t5.\t Back\n";
                        cout<<"\n\n Enter your option:";
                        cin >> customerswitchchoice;
                    }
                    return customerswitchchoice;
                }
            //Irregular Customer Switch Case
            int irregularcustomerswitch()
                {
                    customerswitchchoice=getirregularcustomerchoice();
                    switch(customerswitchchoice)
                    {
                    case 1:
                        AddFacetoFace();
                        break;
                    case 2:
                        AddBycall();
                        break;
                    case 3:
                        ShowFacetoFace();
                        break;
                    case 4:
                        ShowBycall();
                        break;
                    case 5:
                        system("cls");
                        mainmenu();
                        break;

                    default:
                        system("cls");
                        cout<<"**Wrong Choice";
                        irregularcustomerswitch();
                    }
                }
            //Add Face To Face Irregular Customers
  public:   string AddFacetoFace()
                {
                    system("cls");
                    CustomerDetails cust;
                    fstream file;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\IrregularCustomer\\FaceToFace\\FaceToFaceCustomerData.dat",ios::binary | ios::out |ios::in| ios::app);
                    if(!file.is_open())
                    {
                        cout<<"**Error: Unable to open a file...\n";
                    }
                    else
                    {
                        cust.facetoface();
                        file.write((char *)&cust,sizeof(CustomerDetails));
                        string cname=cust.getcustomerfirstname();
                        string cmname=cust.getcustomermiddlename();
                        string clname=cust.getcustomerlastname();
                        string cfname=cname+" "+cmname+" "+clname;
                        return cfname;
                    }
                   file.close();
                   // Get Back to Irregular Customer Menu
                   //irregularcustomerswitch();
                }
 private:       //Add By Call Irregular Customers
            void AddBycall()
                {
                    system("cls");
                    CustomerDetails cust;
                    fstream file;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\IrregularCustomer\\ByCall\\ByCallCustomerData.dat",ios::binary | ios::out |ios::in| ios::app);
                    if(!file.is_open())
                    {
                        cout<<" **Error....";
                    }
                    else
                    {
                        cust.bycall();
                        file.write((char *)&cust,sizeof(CustomerDetails));
                    }
                   file.close();
                   // Get Back to Irregular Customer Menu
                   irregularcustomerswitch();

                }
            //Display All Irregular Customer Records But Only Face To Face Customers
            void ShowFacetoFace()
                {
                    system("cls");
                    count=0;
                    CustomerDetails cust;
                    ifstream file;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\IrregularCustomer\\FaceToFace\\FaceToFaceCustomerData.dat",ios::binary | ios::out);
                    if(!file.is_open())
                    {
                        cout<<" **Error: Unable to open a file...";
                    }
                    else
                    {
                        while(file.read((char *)&cust,sizeof(CustomerDetails)))
                        {
                            flag=1;
                            count++;
                            cust.showfacetoface(count);
                        }
                    }
                   file.close();
                   // Get Back to Irregular Customer Menu
                   irregularcustomerswitch();
                }
            //Display All Irregular Customer only By Call Customers
            void ShowBycall()
                {
                    system("cls");
                    count=0;
                    CustomerDetails cust;

                    ifstream file;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\IrregularCustomer\\ByCall\\ByCallCustomerData.dat",ios::binary | ios::out);
                    if(!file.is_open())
                    {
                        cout<<" **Error: Unable to open a file...";
                    }
                    else
                    {
                        while(file.read((char *)&cust,sizeof(CustomerDetails)))
                        {
                            flag=1;
                            count++;
                            cust.showbycall(count);
                        }
                    }
                   file.close();
                   // Get Back to Irregular Customer Menu
                   irregularcustomerswitch();
                }
            //Add Regular Customer Records
            void AddRegularCustomer()
                {
                    system("cls");
                    CustomerDetails cust;
                    fstream file;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\RegularCustomer\\RegularCustomerData.dat",ios::binary | ios::out |ios::in| ios::app);
                    if(!file.is_open())
                    {
                        cout<<" **Error....";
                    }
                    else
                    {
                        cust.addregularcustomer();
                        file.write((char *)&cust,sizeof(CustomerDetails));
                    }
                   file.close();
                   RegularCustomerSwitch();
                }
            //Display All Regular Customer Records
            void ShowRegularCustomer()
                {
                    system("cls");
                    count=0;
                    CustomerDetails cust;
                    ifstream file;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\RegularCustomer\\RegularCustomerData.dat",ios::binary | ios::out);
                    if(!file.is_open())
                    {
                        cout<<" **Error: Unable to open a file...";
                    }
                    else
                    {
                        while(file.read((char *)&cust,sizeof(CustomerDetails)))
                        {
                            flag=1;
                            count++;
                            cust.showregularcustomer(count);
                        }
                    }
                   file.close();
                   //Get Back to Regular Customer Menu
                   RegularCustomerSwitch();
                }
            //Search Regular Customer Record
            void SearchRegularCustomer()
                {
                    flag=0;
                    system("cls");
                    CustomerDetails cust;
                    cout<<"\n Enter First & Last Name of Customer :";
                    cin>>searchcustomerfirstname;
                    cin>>searchcustomerlastname;
                    fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\RegularCustomer\\RegularCustomerData.dat",ios::binary | ios::out |ios::in| ios::app);
                    if(!file.is_open())
                    {
                        cout<<"\n **Error: Unable to open file...\n";
                    }
                    else
                    {

                        while(file.read((char *)&cust,sizeof(CustomerDetails)))
                        {
                                   if(strcmp(searchcustomerfirstname,cust.getcustomerfirstname())==0 && strcmp(searchcustomerlastname,cust.getcustomerlastname())==0)
                                        {
                                            flag=1;
                                            cust.showregularcustomer(count);
                                        }
                        }
                   }
                   if(flag==0)
                   {
                       system("cls");
                       cout<<"\n **No Record Found";
                   }
                   file.close();
                   //Get Back to Regular Customer Menu
                   RegularCustomerSwitch();

                }
            //Update Regular Customer Record
            void UpdateRegularCustomer()
                {
                    flag=0;
                    system("cls");
                    CustomerDetails cust;
                    cout<<"\n Enter First & Last Name of Customer that should be searched:";
                    cin>>searchcustomerfirstname;
                    cin>>searchcustomerlastname;
                    fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\RegularCustomer\\RegularCustomerData.dat",ios::binary | ios::out |ios::in);
                    if(!file.is_open())
                    {
                        cout<<"\n **Error: Unable to open file....";
                    }
                    else
                    {
                        system("cls");
                        file.read((char *)&cust,sizeof(CustomerDetails));
                        while(!file.eof())
                        {
                              if(strcmp(searchcustomerfirstname,cust.getcustomerfirstname())==0 && strcmp(searchcustomerlastname,cust.getcustomerlastname())==0)
                              {
                                  file.seekg(0,ios::cur);
                                  cout<<"\n Enter new record:";
                                  cust.addregularcustomer();
                                  file.seekp(file.tellg()-sizeof(CustomerDetails));
                                  file.write((char *)&cust,sizeof(CustomerDetails));
                                  flag=1;
                               }
                              file.read((char *)&cust,sizeof(cust));
                        }

                   }
                   if(flag==0)
                   {
                       system("cls");
                       cout<<"\n **No Record Found";
                   }
                   file.close();
                   //Get Back to Regular Customer Menu
                   RegularCustomerSwitch();
                }
            // Delete Regular Customer Record
            void DeleteRegularCustomer()
                {
                    ifstream filein;
                    ofstream fileout;
                    system("cls");
                    CustomerDetails cust;
                    flag=0;
                    cout<<"\n\n\n\t Delete Record";
                    cout<<"\n\n Enter First & Last Name of Customer to Delete:";
                    cin>>searchcustomerfirstname;
                    cin>>searchcustomerlastname;
                    filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\CustomerDataFile\\RegularCustomer\\RegularCustomerData.dat",ios::binary | ios::in);
                    if(!filein)
                        cout<<"\n **Error: Unable to open file....";
                    else
                    {
                        system("cls");
                        fileout.open("E:\\Customer\\DataFiles\\CustomerDataFile\\\RegularCustomer\\RegularCustomerDataNew.dat",ios::binary | ios::out);
                        filein.read((char *)&cust, sizeof(CustomerDetails));

                        while(!filein.eof())
                        {
                            if(strcmp(searchcustomerfirstname,cust.getcustomerfirstname()) && strcmp(searchcustomerlastname,cust.getcustomerlastname()))
                            {
                                flag=1;
                                fileout.write((char *)&cust, sizeof(CustomerDetails));


                            }
                            filein.read((char *)&cust, sizeof(CustomerDetails));
                        }
                        filein.close();
                        fileout.close();

                        remove("E:\\Customer\\DataFiles\\CustomerDataFile\\\RegularCustomer\\RegularCustomerData.dat");
                        rename("E:\\Customer\\DataFiles\\CustomerDataFile\\\RegularCustomer\\RegularCustomerDataNew.dat","E:\\Customer\\DataFiles\\CustomerDataFile\\\RegularCustomer\\RegularCustomerData.dat");
                    }
                     if(flag==0)
                    {
                       cout<<"\n **Sorry!!! Record Not Found ";
                    }
                   //Get Back to Regular Customer Menu
                    RegularCustomerSwitch();
                }
            //Get Choice from user
            int getregularcustomerchoice()
                {
                    cout<<"\n\n\t\t\t-----------------------------------";
                    cout<<"\n\t\t\t Regular Customer Management System";
                    cout<<"\n\t\t\t-----------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t Add Regular Customer \n\t\t\t2.\t Delete Regular Customer \n\t\t\t3.\t Search Regular Customer \n\t\t\t4.\t View Regular Customer\n\t\t\t5.\t Update Regular Customer\n\t\t\t6.\t Back\n";
                    cout<<"\n\n Enter your option: ";
                    cin >> regularcustomerswitchchoice;
                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"\n Please enter number values only...";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t-----------------------------------";
                        cout<<"\n\t\t\t Regular Customer Management System";
                        cout<<"\n\t\t\t-----------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t Add Regular Customer \n\t\t\t2.\t Delete Regular Customer \n\t\t\t3.\t Search Regular Customer \n\t\t\t4.\t View Regular Customer\n\t\t\t5.\t Update Regular Customer\n\t\t\t6.\t Back\n";
                        cout<<"\n\nEnter your option: ";
                        cin >> regularcustomerswitchchoice;
                    }
                    return regularcustomerswitchchoice;
                }
            //Switch case for Regular Customer
            void RegularCustomerSwitch()
                {
                    int l;
                    l:
                    regularcustomerswitchchoice=getregularcustomerchoice();
                    switch(regularcustomerswitchchoice)
                    {
                    case 1:

                        AddRegularCustomer();
                        break;
                    case 2:
                        DeleteRegularCustomer();
                        break;
                    case 3:
                        SearchRegularCustomer();
                        break;
                    case 4:
                        ShowRegularCustomer();
                        break;
                    case 5:
                        UpdateRegularCustomer();
                        break;
                    case 6:
                        system("cls");
                        mainmenu();
                        break;
                    default:
                        system("cls");
                        cout<<" **Wrong Choice";
                        goto l;

                    }
                }
            //Main Customer Menu Choice
            int getmainmenuchoice()
                {
                    cout<<"\n\n\t\t\t------------------------------";
                    cout<<"\n\t\t\t  Customer Management System";
                    cout<<"\n\t\t\t------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t Irregular Customer \n\t\t\t2.\t Regular Customer \n\t\t\t3.\t Exit\n";
                    cout<<"\n\nEnter your option: ";
                    cin >> mainmenuswitchchoice;
                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"Please enter number values only... \n";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t------------------------------";
                        cout<<"\n\t\t\t Customer Management System";
                        cout<<"\n\t\t\t------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t Irregular Customer \n\t\t\t2.\t Regular Customer \n\t\t\t3.\t Exit\n";
                        cout<<"\n\n Enter your option: ";
                        cin >> mainmenuswitchchoice;
                    }
                    return mainmenuswitchchoice;
                }
    public:
            // Main Menu Switch Case
            int mainmenu()
                {
                    int x;
                    x:
                    mainmenuswitchchoice=getmainmenuchoice();
                    switch(mainmenuswitchchoice)
                    {
                    case 1:
                        system("cls");
                        irregularcustomerswitch();
                        break;
                    case 2:
                        system("cls");
                        RegularCustomerSwitch();
                        break;
                    case 3:
                        return 0;
                    default:
                        system("cls");
                        cout<<" **Wrong Choice";
                        goto x;
                    }
                }
};
