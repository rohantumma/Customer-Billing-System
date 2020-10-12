#ifndef FURNITURE_H
#define FURNITURE_H

#include "includefiles.h"
#include "backupandrestore.h"

class Furniture
{
    private:
            char alpha(char furniture_brand_name)
            {
                if(isalpha(furniture_brand_name))
                    return furniture_brand_name;

                else
                {
                    cout<<"**Enter char only";
                    return 0;
                }
            }

    public:
            Furniture();
            virtual ~Furniture();

            char *getfunBname()
            {
                return furniture_brand_name;
            }

            char *getfunTname()
            {
                return furniture_type;
            }

            void addfurniture()
            {
              cout<<"\n\t\t\t\t Enter Furniture Details";

                a:
                    cout<<"\n Enter Brand Name:";
                    cin>>furniture_brand_name;
                    if(alpha(*furniture_brand_name)!=0)
                        {
                            goto b;
                        }
                    else{goto a;}

                b:
                    cout<<"\n Enter Furniture Type:";
                    cin>>furniture_type;
                    if(alpha(*furniture_type)!=0)
                        {
                            goto c;
                        }
                    else{goto b;}

                c:
                    cout<<"\n Enter Furniture DealerName:";
                    cin>>furn_dealername;
                    if(alpha(*furn_dealername)!=0)
                        {
                            goto d;
                        }
                    else{goto c;}

                d:
                    cout<<"\n Enter Furniture Dealer Contact number:";
                    cin>>furn_dealermoblie_number;

                         while(!cin.good())
                           {
                               cout<<"**Please enter number values only \n";
                               cin.clear();
                               cin.ignore(2000000,'\n');
                               cout<<"\n Enter Furniture Dealer Contact number:";
                               cin>>furn_dealermoblie_number;
                           }
                    if(furn_dealermoblie_number>=1000000000 && furn_dealermoblie_number<=9999999999)
                        { goto e; }
                    else
                    {
                        cout<<"** Enter Contact number Valid (10 Digits) Only:\n";
                        goto d;
                    }

                e:
                    cout<<"\n Enter Furniture Quantity:";
                    cin>>furn_quantity;

                     while(!cin.good())
                       {
                           cout<<"**Please enter number values only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Furniture Quantity(1-1000):";
                           cin>>furn_quantity;
                       }
                    if(furn_quantity>=1 && furn_quantity<=1000)
                      {goto f;}
                    else
                    {
                        cout<<"\n**Enter Furniture Quantity(1-1000) Only:";
                        goto e;
                    }

                f:
                    cout<<"\n Enter Furniture Per price Rs:";
                    cin>>furn_price;

                     while(!cin.good())
                       {
                           cout<<"**Please enter number values only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                           cout<<"\n Enter Furniture Per price Rs:";
                           cin>>furn_price;
                       }
                    if(furn_price>=10000 && furn_price<=100000)
                    {
                        total_price=furn_quantity*furn_price;
                    }
                    else
                    {
                        cout<<"\n**Enter Valid Furniture Per price Rs:";
                        goto f;
                    }
                    time_t now;
                    struct tm nowLocal;
                    now=time(NULL);
                    nowLocal=*localtime(&now);
                    dd=nowLocal.tm_mday;
                    mm=nowLocal.tm_mon+1;
                    yyyy=nowLocal.tm_year+1900;
                    cout<<endl;
            }

            void viewfurniture(int count)
            {
                cout<<"\n\t\t\t\t"<<count<<"--Furniture Details ";
                cout<<"\n Brand Name:"<<furniture_brand_name;
                cout<<"\n Furniture Type:"<<furniture_type;
                cout<<"\n Furniture DealerName:"<<furn_dealername;
                cout<<"\n Furniture Dealer Contact number:"<<furn_dealermoblie_number;
                cout<<"\n Furniture Quantity:"<<furn_quantity;
                cout<<"\n Enter Furniture Per price Rs:"<<furn_price;
                cout<<"\n Furniture Total Price Rs:"<<total_price;
                cout<<"\n Delivery-Date:"<<dd<<"/"<<mm<<"/"<<yyyy;
            }

    private:
            char furniture_type[20];
            char furn_dealername[20];
            char furniture_brand_name[20];
            char furn_delivery_date[9];
            unsigned int furn_quantity;
            LONGLONG total_price;
            unsigned long furn_price;
            LONGLONG furn_dealermoblie_number;
            int dd,mm,yyyy;
            char a,b,c,d,e,f,g;
};

class FurnitureFun : protected Furniture
{
    private:
            void AddFurniture()
            {
                Furniture fun;
                system("cls");
                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"error";
                }
                else
                {
                    fun.addfurniture();
                    file.write((char *)&fun,sizeof(Furniture));
                }
               file.close();
               furnitureswitch();
            }

            void ViewFurniture()
            {
                flag=0;
                system("cls");
                count=0;
                Furniture fun;
                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"**error";
                }
                else
                {
                    while(file.read((char *)&fun,sizeof(Furniture)))
                    {
                               flag=1;
                               count++;
                               fun.viewfurniture(count);
                    }
                }
                if(flag==0)
                {
                   system("cls");
                   cout<<"\n**No Record Found";
                }
                file.close();
                furnitureswitch();
            }

            void deletefurniture()
            {
                system("cls");
                Furniture fun;

                flag=0;
                cout<<"\n\n\n\tDelete Record\n";

                filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat",ios::binary | ios::in);
                if(!filein)
                        cout<<"\n**Error: Unable to open file...\n";
                else
                {
                    cout<<"\n Enter Brand Name Of That Furniture To Be Searched:";
                    cin>>searchfunbrand;
                    cout<<"\n Enter Furniture Type That To Be Searched:";
                    cin>>searchfuntype;
                    system("cls");
                    fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredatanew.dat",ios::binary | ios::out);
                    filein.read((char *)&fun, sizeof(Furniture));

                    while(!filein.eof())
                        {
                            cout<<"\n2";
                            if(strcmp(searchfunbrand,fun.getfunBname())==0 && strcmp(searchfuntype,fun.getfunTname())==0 )
                                {
                                    cout<<"\n3";
                                    flag=1;
                                    fileout.write((char *)&fun, sizeof(Furniture));
                                }
                            filein.read((char *)&fun, sizeof(Furniture));
                        }
                    filein.close();
                    fileout.close();

                    remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat");
                    rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredatanew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat");
                }

                if(flag==0)
                    cout<<"\n **Sorry!!! Record Not Found ";

                furnitureswitch();// it shows menu again

            }

            void updatefurniture()
            {
                flag=0;
                system("cls");
                Furniture fun;
                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat",ios::binary | ios::out |ios::in);
                if(!file.is_open())
                {
                    cout<<"\n**Error: Unable to open file...\n";
                }
                else
                {
                    cout<<"Enter Brand Name Of That Furniture To Be Searched:";
                    cin>>searchfunbrand;
                    cout<<"Enter Furniture Type That To Be Searched:";
                    cin>>searchfuntype;
                    file.read((char *)&fun,sizeof(Furniture));
                    while(!file.eof())
                    {
                          if(strcmp(searchfunbrand,fun.getfunBname())==0 && strcmp(searchfuntype,fun.getfunTname())==0 )
                          {
                              file.seekg(0,ios::cur);
                              cout<<"\nenter new record";
                              fun.addfurniture();
                              file.seekp(file.tellg()-sizeof(Furniture));
                              file.write((char *)&fun,sizeof(Furniture));
                              flag=1;
                          }
                          file.read((char *)&fun,sizeof(Furniture));
                    }
               }
               if(flag==0)
               {
                   system("cls");
                   cout<<"\n**No Record Found";
               }
               file.close();
               furnitureswitch();
            }

            void searchfurniture()
            {
                    flag=0;
                    system("cls");
                    Furniture fun;
                    fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\FurnitureFile\\Furnituredata.dat",ios::binary | ios::out |ios::in| ios::app);
                    if(!file.is_open())
                    {
                        cout<<"error";
                    }
                    else
                    {
                        cout<<"Enter Brand Name Of That Furniture To Be Searched:";
                        cin>>searchfunbrand;
                        cout<<"Enter Furniture Type That To Be Searched:";
                        cin>>searchfuntype;
                        file.read((char *)&fun,sizeof(Furniture));
                        while(!file.eof())
                        {
                                   if(strcmp(searchfunbrand,fun.getfunBname())==0 && strcmp(searchfuntype,fun.getfunTname())==0 )
                                        {
                                                    flag=1;
                                                    fun.viewfurniture(count);
                                        }
                                   file.read((char *)&fun,sizeof(Furniture));
                        }
                   }
                   if(flag==0)
                   {
                      // system("cls");
                       cout<<"\n**No Record Found";
                   }
                   file.close();
                   furnitureswitch();
                }

    public:
            int getfurniturechoice()
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   Furniture Management System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t AddFurniture \n\t\t\t2.\t DeleteFurniture \n\t\t\t3.\t SearchFurniture \n\t\t\t4.\t ViewFurniture \n\t\t\t5.\t UpdateFurniture \n\t\t\t6.\t BackUpFurniture \n\t\t\t7.\t RestoreFurniture \n\t\t\t8.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> furnitureswitchchoice;

                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"**Please enter number values only \n";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t------------------------------";
                        cout<<"\n\t\t\t   Furniture Management System";
                        cout<<"\n\t\t\t------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t AddFurniture \n\t\t\t2.\t DeleteFurniture \n\t\t\t3.\t SearchFurniture \n\t\t\t4.\t ViewFurniture \n\t\t\t5.\t UpdateFurniture \n\t\t\t6.\t BackUpFurniture \n\t\t\t7.\t RestoreFurniture \n\t\t\t8.\t Exit\n";
                        cout<<"\n\nEnter your option: ";
                        cin >> furnitureswitchchoice;
                    }
                return furnitureswitchchoice;
            }

            int furnitureswitch()
            {
                k:
                backupandrestore GBP;
                Furniture fun;
                furnitureswitchchoice=getfurniturechoice();
                switch(furnitureswitchchoice)
                    {
                        case 1:
                            AddFurniture();
                            break;
                        case 2:
                            deletefurniture();
                            break;
                        case 3:
                            searchfurniture();
                            break;
                        case 4:
                            ViewFurniture();
                            break;
                        case 5:
                            updatefurniture();
                            break;
                        case 6:
                            GBP.BackUpswitch<Furniture>(fun);
                            goto k;
                            break;
                        case 7:
                           GBP.Restoreswitch<Furniture>(fun);
                            goto k;
                            break;
                        case 8:return 0;
                        default:
                            system("cls");
                            cout<<"**Wrong Choice";
                            goto k;
                    }
                return 0;
            }

    private:
            int  k,flag,count;
            char searchfunbrand[10];
            char searchfuntype[10];
            int  furnitureswitchchoice;

            ifstream filein;
            ofstream fileout;
};
#endif // FURNITURE_H
