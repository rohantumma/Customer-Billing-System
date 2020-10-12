#include "includefiles.h"
#include "backupandrestore.h"

class DeliveryBoy :protected dategeti
{
    private:
            char del_boyfirstname[15],del_boymiddlename[15],del_boylastname[15],address[50],licenseno[16],pan_no[11],bikeno[13];
            int a,b,c,d,e,f,g,h,i,j,o,l,m,n,p,q;
            int dd,mm,yyyy;
            unsigned int deliveryboyage;
            unsigned long int deliveryboysalary;
            LONGLONG contact_no,aadhaarno,bank_account_no;
            int length_licenseno,length_pan_no,length_bikeno,length_address;

    public:
            string time;
            int count=0;
            int flag=0;
            int deliveryboyswitchchoice;

            char alpha(char del_boyfirstname) // checking Entered Name is in alphabets or not
            {
              if(isalpha(del_boyfirstname))
                    return del_boyfirstname;
              else
                  {
                    cout<<"**Enter char only";
                    return 0;
                  }
            }

            int digit(LONGLONG contact_no) //Checking Entered Contact Number Is is Digit Or not
            {
              if(isdigit(contact_no))
                    return 1;
              else
                {
                    cout<<"**Enter Number only";
                    return 0;
                }
            }

            char *getdeliveryname() //This is return name.that is used in searching in file
            {
                return del_boyfirstname;
            }

            void adddeliveryboy() //Get all Delivery Boy  information from user
            {
                a:
                    cout<<"\n Enter Name(name-middlename-sername):";
                    cin>>del_boyfirstname;
                    if(alpha(*del_boyfirstname)!=0)
                        {
                            if(strlen(del_boyfirstname)>=2)
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
                    cin>>del_boymiddlename;
                    if(alpha(*del_boymiddlename)!=0)
                        {
                            if(strlen(del_boymiddlename)>=1)
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
                    cin>>del_boylastname;
                    if(alpha(*del_boylastname)!=0)
                        {
                            if(strlen(del_boylastname)>=2)
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
                       cout<<"\n Enter address:";
                       cin>>address;
                       if(strlen(address)>=10 && strlen(address)<=50)
                           goto e;
                       else
                        {
                           cout<<"\n **Enter Address valid (Minimum 10 characters And Maximum) only";
                           goto d;
                        }
                e:
                    cout<<"\n Enter Contact number:";
                    cin>>contact_no;
                    while(!cin.good())
                        {
                            cout<<" **Please enter number values only \n";
                            cin.clear();
                            cin.ignore(2000000,'\n');
                            cout<<"\n Enter Contact number:";
                            cin>>contact_no;
                        }
                    if(contact_no>=1000000000 && contact_no<=9999999999)
                        goto f;
                    else
                    {
                        cout<<" **Enter Contact number Valid (10 Digits) Only:\n";
                        goto e;
                    }
                f:
                    cout<<"\n Enter Delivery Boy Age:";
                    while(!(cin>>deliveryboyage))
                        {
                            cout<<" **Please enter number values only \n";
                            cin.clear();
                            cin.ignore(2000000,'\n');
                            cout<<"\n Enter Delivery Boy Age:";
                            cin>>deliveryboyage;
                        }
                    if(deliveryboyage>=18 && deliveryboyage<=45)
                        goto g;
                    else
                    {
                        cout<<" **Enter Delivery Boy Age (18-45) Only:\n";
                        goto f;
                    }
                g:
                    cout<<"\n Enter License No:";
                    cin>>licenseno;
                    length_licenseno=strlen(licenseno);
                    if(length_licenseno==15)
                       goto h;
                    else
                    {
                       cout<<"\n **Enter License Number valid (15 Digit) only";
                        goto g;
                    }
                h:
                    cout<<"\n Enter Delivery Boy Salary(Annual Salary): Rs ";
                    while(!(cin>>deliveryboysalary))
                        {
                            cout<<" **Please enter number values only \n";
                            cin.clear();
                            cin.ignore(2000000,'\n');
                            cout<<"\n Enter Delivery Boy Salary(Annual Salary): Rs ";
                            cin>>deliveryboysalary;
                        }
                    if(deliveryboysalary>=200000 && deliveryboysalary<=500000)
                           goto i;
                    else
                    {
                        cout<<" **Enter Delivery Boy Salary (Rs 200000-500000) Only:\n";
                        goto h;
                    }
                i:
                    cout<<"\n Enter Aadhaar No:";
                    while(!(cin>>aadhaarno))
                        {
                            cout<<" **Please enter number values only \n";
                            cin.clear();
                            cin.ignore(2000000,'\n');
                            cout<<"\n Enter Aadhaar No:";
                            cin>>aadhaarno;
                        }
                    if(aadhaarno>=100000000000 && aadhaarno<=999999999999)
                        goto j;
                    else
                    {
                        cout<<" **Enter Aadhaar number Valid (12 Digits) Only:\n";
                        goto i;
                    }
                j:
                    cout<<"\n Enter Pan Card No:";
                    cin>>pan_no;
                    length_pan_no=strlen(pan_no);
                    if(length_pan_no==10)
                       goto o;
                    else
                    {
                        cout<<"\n **Enter Pan Card Number valid (10 Digit) only";
                        goto j;
                    }
                o:
                    cout<<"\n Enter Bike No( like mh13.xx.0000):";
                    cin>>bikeno;
                    length_bikeno=strlen(bikeno);
                    if(length_bikeno==12)
                       goto p;
                    else
                    {
                        cout<<"\n **Enter Bike Number valid ( like mh13.xx.0000) only";
                        goto o;
                    }
                p:
                    cout<<"\n Enter Bank Account No:";
                    while(!(cin>>bank_account_no))
                        {
                            cout<<" **Please enter number values only \n";
                            cin.clear();
                            cin.ignore(2000000,'\n');
                            cout<<"\n Enter Bank Account No:";
                            cin>>bank_account_no;
                        }
                    if(bank_account_no>=1000000000000000 && bank_account_no<=9999999999999999)
                      goto q;
                    else
                    {
                        cout<<" **Enter bank account number Valid (16 Digits) Only:\n";
                        goto p;
                    }
                q:
                    time_t now;
                    struct tm nowLocal;
                    //now=time(NULL);
                    nowLocal=*localtime(&now);
                    dd=nowLocal.tm_mday;
                    mm=nowLocal.tm_mon+1;
                    yyyy=nowLocal.tm_year+1900;
                    cout<<endl;
            }

            void viewdeliveryboy(int count) // Method For Displaying information
            {
                cout<<"\n\t\t\t\t"<<count<<"--Delivery Boy Details ";

                cout<<"\n Name:"<<del_boyfirstname<<" "<<del_boymiddlename<<" "<<del_boylastname;
                cout<<"\n Address:"<<address;

                cout<<"\n Contact No:"<<contact_no;
                cout<<"\n Age:"<<deliveryboyage;
                cout<<"\n License No:"<<licenseno;

                cout<<"\n Salary Rs:"<<deliveryboysalary;
                cout<<"\n Aadhaar No:"<<aadhaarno;
                cout<<"\n Pan Card No:"<<pan_no;

                cout<<"\n Bike No:"<<bikeno;
                cout<<"\n Bank Account No:"<<bank_account_no;
                cout<<"\n Join-Date:"<<dd<<"/"<<mm<<"/"<<yyyy;
            }
};

class DeliveryBoy1 :protected DeliveryBoy
{
    public:
            int k;
            char searchdeliveryboyfirstname[15];
            char searchdeliveryboylastname[15];

    protected:
            void AddDeliveryBoy() // Delivery Boy Registration
            {
                system("cls");
                DeliveryBoy del;
                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    {
                        cout<<"**Error: Unable to open a file...\n";
                    }
                else
                    {
                        del.adddeliveryboy();
                        file.write((char *)&del,sizeof(DeliveryBoy));
                    }
                file.close();
                deliveryboyswitch();  // it shows the menu again
            }

            void ViewDeliveryBoy() // Display All Delivery Boy information
            {
                system("cls");
                count=0;
                DeliveryBoy del;

                ifstream file;
                file.open("E:\\rohan\\project\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat",ios::binary | ios::out);
                if(!file.is_open())
                    {
                        cout<<"**Error: Unable to open a file...\n";
                    }
                else
                    {
                        while(file.read((char *)&del,sizeof(DeliveryBoy)))
                        {
                            flag=1;
                            count++;
                            del.viewdeliveryboy(count);
                        }
                    }
                file.close();
                deliveryboyswitch();  // it shows menu again
            }

            void SearchDeliveryBoy() //Method for search Particular Delivery Boy
            {
                flag=0;
                system("cls");

                DeliveryBoy del;
                cout<<"\n **Enter First Name of Delivery Boy :";
                cin>>searchdeliveryboyfirstname;
                cin>>searchdeliveryboylastname;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat",ios::binary | ios::out |ios::in|ios::app);
                if(!file.is_open())
                        cout<<"\n**Error: Unable to open file...\n";
                else
                {
                    while(file.read((char *)&del,sizeof(DeliveryBoy)))
                    {
                        if(strcmp(searchdeliveryboyfirstname,del.getdeliveryname())==0 && strcmp(searchdeliveryboylastname,del.getdeliveryname())==0)
                        {
                            flag=1;
                            del.viewdeliveryboy(count);
                        }
                    }
                }
                if(flag==0)
                {
                    system("cls");
                    cout<<"\n **No Record Found";
                }
                file.close();
                deliveryboyswitch();  // it shows menu again
            }

            void DeleteDeliveryBoy() //Method for Delete Particular Delivery Boy
            {
                ifstream filein;
                ofstream fileout;

                system("cls");
                DeliveryBoy del;

                flag=0;
                cout<<"\n\n\n\tDelete Record";
                cout<<"\n\nEnter First Name of Delivery Boy to Delete  :  ";
                cin>>searchdeliveryboyfirstname;
                cin>>searchdeliveryboylastname;

                filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat",ios::binary | ios::in);
                if(!filein)
                        cout<<"\n**Error: Unable to open file...\n";
                else
                {
                    system("cls");
                    fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydatanew.dat",ios::binary | ios::out);
                    filein.read((char *)&del, sizeof(DeliveryBoy));

                    while(!filein.eof())
                        {
                            if(strcmp(searchdeliveryboyfirstname,del.getdeliveryname()) && strcmp(searchdeliveryboyfirstname,del.getdeliveryname()))
                                {
                                    flag=1;
                                    fileout.write((char *)&del, sizeof(DeliveryBoy));
                                }
                            filein.read((char *)&del, sizeof(DeliveryBoy));
                        }
                    filein.close();
                    fileout.close();

                    remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat");
                    rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydatanew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat");
                }

                if(flag==0)
                    cout<<"\n **Sorry!!! Record Not Found ";

                deliveryboyswitch();// it shows menu again
            }

            void UpdateDeliveryBoy() //Method for Update Particular Delivery Boy
            {
                flag=0;
                system("cls");
                DeliveryBoy del;

                cout<<"Enter First Name of Delivery Boy that should be searched:";
                cin>>searchdeliveryboyfirstname;
                cin>>searchdeliveryboylastname;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DeliveryboyFile\\deliveryboydata.dat",ios::binary | ios::out |ios::in);
                if(!file.is_open())
                    cout<<"\n **Error: Unable to open file....";
                else
                {
                    system("cls");
                    file.read((char *)&del,sizeof(DeliveryBoy));
                    while(!file.eof())
                        {
                            if(strcmp(searchdeliveryboyfirstname,del.getdeliveryname())==0 && strcmp(searchdeliveryboyfirstname,del.getdeliveryname())==0)
                                {
                                    file.seekg(0,ios::cur);
                                    cout<<"\nEnter new record ";
                                    del.adddeliveryboy();
                                    file.seekp(file.tellg()-sizeof(DeliveryBoy));
                                    file.write((char *)&del,sizeof(DeliveryBoy));
                                    flag=1;
                                }
                            file.read((char *)&del,sizeof(del));
                        }
                }
                if(flag==0)
                {
                    system("cls");
                    cout<<"\n**No Record Found";
                }
                file.close();
                deliveryboyswitch(); // it shows menu again
            }

    public:
            int getdeliveryboychoice() //Get choice from user and return to the switch case method
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t Delivery Boy Management System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t AddDeliveryBoy \n\t\t\t2.\t DeleteDeliveryBoy \n\t\t\t3.\t SearchDeliveryBoy \n\t\t\t4.\t ViewDeliveryBoy \n\t\t\t5.\t UpdateDeliveryBoy \n\t\t\t6.\t BackUpDeliveryBoyData \n\t\t\t7.\t RestoreDeliveryBoyData \n\t\t\t8.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> deliveryboyswitchchoice;
                while(!cin.good())
                {
                    system("cls");
                    cout<<" **Please enter number values only... \n";
                    cin.clear();
                    cin.ignore(2000000,'\n');
                    cout<<"\n\n\t\t\t------------------------------";
                    cout<<"\n\t\t\t   Delivery Boy Management System";
                    cout<<"\n\t\t\t------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t AddDeliveryBoy \n\t\t\t2.\t DeleteDeliveryBoy \n\t\t\t3.\t SearchDeliveryBoy \n\t\t\t4.\t ViewDeliveryBoy \n\t\t\t5.\t UpdateDeliveryBoy \n\t\t\t6.\t BackUpDeliveryBoyData \n\t\t\t7.\t RestoreDeliveryBoyData \n\t\t\t8.\t Exit\n";
                    cout<<"\n\n Enter your option: ";
                    cin >> deliveryboyswitchchoice;
                }
                return deliveryboyswitchchoice;//return user choice
            }

            int deliveryboyswitch() // Switch case method
            {
                k:
                    deliveryboyswitchchoice=getdeliveryboychoice();
                    DeliveryBoy del;
                    backupandrestore GBP;
                    switch(deliveryboyswitchchoice)
                    {
                        case 1:
                                AddDeliveryBoy();
                                break;
                        case 2:
                                DeleteDeliveryBoy();
                                break;
                        case 3:
                                SearchDeliveryBoy();
                                break;
                        case 4:
                                ViewDeliveryBoy();
                                break;
                        case 5:
                                UpdateDeliveryBoy();
                                break;
                        case 6:
                                GBP.BackUpswitch<DeliveryBoy>(del);
                                goto k;
                                break;
                        case 7:
                                //restore.restorecashierfile();
                                goto k;
                                break;
                        case 8:return 0;

                        default:
                                system("cls");
                                cout<<" **Wrong Choice";
                                goto k;
                    }
            }
};
