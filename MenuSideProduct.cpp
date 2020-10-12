#include "includefiles.h"
#include "backupandrestore.h"

using namespace std;

class Product
{
    private:

        int a,b,c,d,e,f,g,h,i,j,x,quantity;
        int probexpdate;
        int dd,mm,yyyy;
        char productname[15],producttype[15],prodbrand[15];
        char supplierfirstname[10],suppliermiddlename[10],supplierlastname[10];
        float priceperproduct;
        LONGLONG supplierphone;
        string Cold="Cold";
        string Warm="Warm";
        string ColdDrink="ColdDrink";
        int menuswitchchoice;


    public:
       int count=0;
       char alpha(char productname)
        {
            if(isalpha(productname))
               {
                   return productname;
               }
            else{
                cout<<" **Enter Char Only\n";
                return 0;
               }
        }


        char *getfun()
            {
                return productname;
            }

    public:

    //GETTING PRODUCT DETAILS FROM ADMIN
        void addmenuproduct()
        {

            a:
               cout<<"\n Enter Product Name:";
               cin>>productname;
               if(alpha(*productname)!=0)
               {
                   goto b;
               }

               else
                {
                  goto a;
                }

            b:
                   cout<<"\n Enter Product Brand:";
                   cin>>prodbrand;
                   if(alpha(*prodbrand)!=0)
                    {
                        goto g;
                    }
                    else
                    {
                        goto b;
                    }

            g:
                      cout<<"\n Enter Quantity Of Product:";
                      while(!(cin >> quantity))
                        {
                           cout<<" **Enter Integers Only\n";
                           cin.clear();
                           cin.ignore(20000,'\n');
                           cout<<"\n Enter Quantity Of Product:";
                        }
                       if(quantity>=1 && quantity<=1000)
                           {
                               goto i;
                           }
                           else
                           {
                               cout<<" **Enter Valid Quantity\n";
                               goto g;
                           }

            i:
               cout<<"\n Enter Product Price(Per Product(Rs)):";
               while(!(cin >> priceperproduct))
               {
                   cout<<" **Enter Integers Only\n";
                   cin.clear();
                   cin.ignore(20000,'\n');
                   cout<<"\n Enter Product Price:";
               }
               if(priceperproduct>=1 && priceperproduct<=3000)
                   {
                       goto f;
                   }
                   else
                   {
                       cout<<" **Enter Valid Amount\n";
                       goto i;
                   }

            f:
               cout<<"\n Enter Product Type(Cold / Warm / ColdDrink):";
               cin>>producttype;
               if(alpha(*producttype)!=0)
               {
                   string Cold1(producttype);
                   if(Cold1==Cold || Cold1==Warm || Cold1==ColdDrink)
                   {
                        goto j;
                   }
                   else
                   {
                   cout<<" **Please Enter Given Product Types Only\n";
                   cout<<endl;
                   goto f;
                   }
               }
               else
                {
                    cin.clear();
                    cin.ignore();
                }

            j:
               cout<<"\n Enter Probable Expiry Date(1 to 12):";
               while(!(cin>>probexpdate))
               {
                   cout<<" **Enter Integers Only\n";
                   cin.clear();
                   cin.ignore(20000,'\n');
                   cout<<"\n Enter Probable Expiry Date(1 to 12):";
               }
               if(probexpdate>=1 && probexpdate<=12)
               {
                        goto c;
               }
               else
               {
                    cout<<" **Enter Expiry Date Given Range Only\n";
                    goto j;
               }

            c:
               cout<<"\n Enter supplier name(First,Middle,Last):";
               cin>>supplierfirstname;
               if(alpha(*supplierfirstname)!=0)
               {
                   goto d;
               }

               else{
                    cin.clear();
                    cin.ignore();
                    goto c;
               }

            d:
               cin>>suppliermiddlename;
               if(alpha(*suppliermiddlename)!=0)
               {
                   goto e;
               }

               else{
                    cin.clear();
                    cin.ignore();
                    goto d;
               }

            e:
               cin>>supplierlastname;
               if(alpha(*supplierlastname)!=0)
               {
                   goto h;
               }
               else{
                    cin.clear();
                    cin.ignore();
                    goto e;
               }

            h:
                   cout<<"\n Enter supplier phone number:";
                   while(!(cin >> supplierphone))
                   {
                       cout<<" **Enter Integers Only\n";
                       cin.clear();
                       cin.ignore(20000,'\n');
                       cout<<"\n Enter supplier phone number:";
                   }
                  if(supplierphone>=100000000 && supplierphone<=9999999999)
                   {
                       goto x;
                   }
                   else
                   {
                       cout<<" **Enter 10 Digits Only\n";
                       goto h;
                   }
            x:
                    time_t now;
                    struct tm nowLocal;
                    now=time(NULL);
                    nowLocal=*localtime(&now);
                    dd=nowLocal.tm_mday;
                    mm=nowLocal.tm_mon+1;
                    yyyy=nowLocal.tm_year+1900;
                    cout<<endl;
        }

    //VIEW PRODUCT
        void viewmenuproduct(int count)
            {
               cout<<"\n\t\t\t\t"<<count<<"--Menu Product Details ";
               cout<<"\n Product Name:"<<productname;
               cout<<"\n Quantity:"<<quantity;
               cout<<"\n Price(per product(Rs)):"<<priceperproduct;
               cout<<"\n Product Type:"<<producttype;
               cout<<"\n Total Amount(In Rs):"<<quantity*priceperproduct;
               cout<<"\n Delivery Date:"<<dd<<" "<<mm<<" "<<yyyy;
               cout<<"\n Probable Exp Date:"<<probexpdate<<" Month";
               cout<<"\n Supplier Name:"<<supplierfirstname<<" "<<suppliermiddlename<<" "<<supplierlastname;
               cout<<"\n Supplier Phone Number:"<<supplierphone;
               cout<<endl;
            }
        void updateq()
            {
                quantity=quantity-1;
            }
};

class MenuSideProduct : protected Product
{

    private:
            int menuswitchchoice,productitemnumber,countnum;
            int flag=0;
            char searchproductname[15],productname[30];
            string path="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\MenusideproductdataFile\\menuproductdata.dat";
            string demopath="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\MenusideproductdataFile\\menuproductdatanew.dat";
        //ADD PRODUCTS DETAILS
             void AddMenuProduct()
            {
                system("cls");
                Product pro;
                cout<<"\n How Many Products Want To Enter:";
                while(!(cin >> productitemnumber))
                {
                    cout<<" **Enter Numbers Only\n";
                    cin.clear();
                    cin.ignore(2000000,'\n');
                    cout<<"\n How Many Products Want To Enter:";
                }

                fstream file;
                file.open(path,ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"\n error";
                }
                else
                {
                    for(menuswitchchoice=1;menuswitchchoice<=productitemnumber;menuswitchchoice++)
                    {
                            pro.addmenuproduct();
                            file.write((char *)&pro,sizeof(Product));
                    }
                }
               file.close();
               menuproductswitch();
            }
    public: //METHOD FOR VIEW PRODUCT
            void ViewMenuProduct()
            {
                system("cls");
                int count=0;
                Product pro;
                ifstream file;
                //menuswitchchoice=1;
                file.open(path,ios::binary | ios::out);
                if(!file.is_open())
                {
                    cout<<"**error\n";
                }

                else
                {

                    while(file.read((char *)&pro,sizeof(Product)))
                    {

                        //cout<<"\n\t"<<menuswitchchoice<<"-Product\n";
                        flag=1;
                        count++;
                        pro.viewmenuproduct(count);
                        //menuswitchchoice++;
                    }
                }
                file.close();

               if(flag==0)
               {
                   cout<<"**No Record Found";
               }
               menuproductswitch();
            }
            //Method for search Particular Product
            void SearchMenuProduct()
            {
                flag=0;
                system("cls");
                Product pro;
                cout<<"Enter Name of Product Want To Search :";
                cin>>searchproductname;

                fstream file(path,ios::binary | ios::out|ios::in| ios::app);
                   if(!file.is_open())
                      {
                          cout<<"\n **Error: Unable to open file...\n";
                      }
                   else
                      {
                         while(file.read((char *)&pro,sizeof(Product)))
                        {
                         if(strcmp(searchproductname,pro.getfun())==0)
                            {
                         flag=1;
                         pro.viewmenuproduct(count);
                            }
                        }
                      }
                    if(flag==0)
                           {
                               system("cls");
                               cout<<"\n**No Record Found";
                           }
                           file.close();
                           menuproductswitch();

            }
    private://Method for Delete Particular Product
            void deletemenuproduct()
                {
                 ifstream filein;
                 ofstream fileout;
                 system("cls");
                 Product pro;
                 flag=0;

                     cout<<"\n\n\n\tDelete Record";
                     cout<<"\n\nEnter Name of Product Want to Delete  :  ";
                     cin>>searchproductname;

                     filein.open(path,ios::binary | ios::in);
                  if(!filein)
                      cout<<"File not found";
                  else
                    {
                       fileout.open(demopath,ios::binary | ios::out);
                       filein.read((char *)&pro, sizeof(Product));

                  while(!filein.eof())
                      {
                        if(strcmp(searchproductname,pro.getfun()))
                                {
                                    flag=1;
                                    fileout.write((char *)&pro, sizeof(Product));
                                }
                        filein.read((char *)&pro, sizeof(Product));
                      }
                                filein.close();
                                fileout.close();

                    remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\MenusideproductdataFile\\menuproductdata.dat");
                    rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\MenusideproductdataFile\\menuproductdatanew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\MenusideproductdataFile\\menuproductdata.dat");
                    }
                  if(flag==0)
                     cout<<"\n\nSorry!!! Record Not Found ";

            menuproductswitch();
                 }
        //Method for Update Particular Product
            void updatemenuproduct()
              {
                    flag=0;
                    system("cls");
                    Product pro;
                    cout<<"Enter Name Of Product That Should Be Searched:";
                    cin>>searchproductname;

                   fstream file(path,ios::binary | ios::out |ios::in);
                   if(!file.is_open())
                      {
                         cout<<"Error: Unable to open file....";
                      }
                   else
                      {
                         file.read((char *)&pro,sizeof(Product));
                         while(!file.eof())
                           {
                              if(strcmp(searchproductname,pro.getfun())==0)
                                 {
                                    file.seekg(0,ios::cur);
                                    cout<<"\nEnter new record ";
                                    pro.addmenuproduct();
                                    file.seekp(file.tellg()-sizeof(Product));
                                    file.write((char *)&pro,sizeof(Product));
                                    flag=1;
                                  }
                                file.read((char *)&pro,sizeof(pro));
                            }
                        }

                    if(flag==0)
                          {
                               system("cls");
                               cout<<"\n**No Record Found";
                          }
                           file.close();
                           menuproductswitch();
                }

            int menuproduct()
                {
                    cout<<"\n\n\t\t\t------------------------------";
                    cout<<"\n\t\t\t   Menu Pizza Product System";
                    cout<<"\n\t\t\t------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t AddMenuProduct \n\t\t\t2.\t DeleteMenuProduct \n\t\t\t3.\t SearchMenuProduct \n\t\t\t4.\t ViewMenuProduct \n\t\t\t5.\t UpdateMenuProduct \n\t\t\t6.\t UpdateMenuProductQ\n 7.exit";
                    cout<<"\n\nEnter your option: ";
                    cin >> menuswitchchoice;
                     while(!cin.good())
                       {
                           system("cls");
                           cout<<"**Please enter number values only \n";
                           cin.clear();
                           cin.ignore(2000000,'\n');
                                cout<<"\n\n\t\t\t------------------------------";
                                cout<<"\n\t\t\t   Menu Pizza Product System";
                                cout<<"\n\t\t\t------------------------------";
                                cout<<"\n\n\t\t\t What you want to do?\n";
                                cout<<"\n\t\t\t1.\t AddMenuProduct \n\t\t\t2.\t DeleteMenuProduct \n\t\t\t3.\t SearchMenuProduct \n\t\t\t4.\t ViewMenuProduct \n\t\t\t5.\t UpdateMenuProduct \n\t\t\t6.\t UpdateMenuProductQ\n7.exit";
                                cout<<"\n\nEnter your option: ";
                           cin >> menuswitchchoice;
                       }
                    return menuswitchchoice;
                }
    public:
            int menuproductswitch()
                {
                menuswitchchoice=menuproduct();

                switch(menuswitchchoice)
                    {
                    case 1:
                        AddMenuProduct();
                        break;
                    case 2:
                       deletemenuproduct();
                        break;
                    case 3:
                        SearchMenuProduct();
                        break;
                    case 4:
                        ViewMenuProduct();
                        break;
                    case 5:
                       updatemenuproduct();
                        break;
                    /*case 6:
                        b.backupfiles();
                        goto k;
                        break;
                    case 7:
                        restore.restorecashierfile();
                        goto k;
                        break;*/
                    case 6:updatemenuproductQ();
                            break;
                    case 7:return 0;
                    default:
                            system("cls");
                            cout<<"**Wrong Choice";
                            menuproductswitch();
                }
        }

            void updatemenuproductQ()
              {
                    flag=0;
                    system("cls");
                    Product pro;
                    cout<<"Enter Name Of Product That Should Be Searched:";
                    cin>>searchproductname;

                   fstream file(path,ios::binary | ios::out |ios::in);
                   if(!file.is_open())
                      {
                         cout<<"Error: Unable to open file....";
                      }
                   else
                      {
                         file.read((char *)&pro,sizeof(Product));
                         while(!file.eof())
                           {
                              if(strcmp(searchproductname,pro.getfun())==0)
                                 {
                                    file.seekg(0,ios::cur);
                                    cout<<"\nEnter new record ";
                                    pro.updateq();
                                    file.seekp(file.tellg()-sizeof(Product));
                                    file.write((char *)&pro,sizeof(Product));
                                    flag=1;
                                  }
                                file.read((char *)&pro,sizeof(pro));
                            }
                        }

                    if(flag==0)
                          {
                               system("cls");
                               cout<<"\n**No Record Found";
                          }
                           file.close();
                           menuproductswitch();
                }


};
