#include "includefiles.h"

#include "CustomerDetails.cpp"
#include "discount.cpp"

//#include "CashierDetails.cpp"
static string CUSTNAME;
static string CUNAME;

static int countn=0;
static int countnn=0;
static int countm=0;

static float pizzamenueprice=0;
static float productmenueprice=0;
static float totalprice=0;

static int InvoiceNo=0;
static int DeletedNO=0;
static int OrderNoDaily=0;
static int OrderNo=0;

static int PizzaFlag=0;
static int ProductFlag=0;
static int OrderCount=0;

class Pizza
{
    public:

            char pizzaname[15];
            char pizzadescription[30];
            char pizzatype[15];
            char pizzasize[10];

            int pizzaid1=0;
            int productid=0;

            float pizzaprice=0;
            string line;
            char *pizzaproducttype1="Veg";
            char *pizzaproducttype2="Non-Veg";
            char *pizzasize1="small";
            char *pizzasize2="Mediam";
            char *pizzasize3="large";
            int counti=0,sizechchoice=0,length_pizzadescription=0,pizzatypechoice=0;

            float getpizzaprice()
            {
                return pizzaprice;
            }
            float getproductprice()
            {
                return priceperproduct;
            }
            int getpizzaid()
            {
                return pizzaid1;
            }
            int getproductid()
            {
                return productid;
            }
            char *getpizza()
            {
                return pizzaname;
            }
            char *getpizzatype()
            {
                return pizzatype;
            }
            char alpha(char pizzaname)
            {
               if(isalpha(pizzaname))
                {
                    return pizzaname;
                }
                else{
                      cout<<" **Enter Char Only\n";
                      return 0;
                   }
            }

    public:
            int a,b,c,d,e,f,g,h,i,j,x,quantity;
            int probexpdate=0;
            int dd=0,mm=0,yyyy=0;
            char productname[15],producttype[15],prodbrand[15];
            char supplierfirstname[10],suppliermiddlename[10],supplierlastname[10];
            float priceperproduct=0;
            LONGLONG supplierphone=0;
            string Cold="Cold";
            string Warm="Warm";
            string ColdDrink="ColdDrink";
            int menuswitchchoice=0;

            void addmenuproduct()
            {
                ifstream pizzaidin;
                pizzaidin.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productmenueid.txt");
                getline(pizzaidin, line);

                stringstream pizzain(line);
                pizzain>>productid;

                productid++;
                pizzaidin.close();

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

                    ofstream pizzaidout;
                    string file = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productmenueid.txt";
                    pizzaidout.open(file.c_str());
                    pizzaidout<<productid;
                    pizzaidout.close();
            }

            void viewmenuproduct(int counti)
            {
               cout<<"\n\t\t\t\t"<<counti<<"--Menu Product Details ";
               cout<<"\n Product Name:"<<productname;
               cout<<"\n Product Name:"<<prodbrand;
               cout<<"\n Quantity:"<<quantity;
               cout<<"\n Price(per product(Rs)):"<<priceperproduct;
               cout<<"\n Product Type:"<<producttype;
               cout<<"\n Total Amount(In Rs):"<<quantity*priceperproduct;
               cout<<"\n Delivery Date:"<<dd<<" "<<mm<<" "<<yyyy;
               cout<<"\n Probable Exp Date:"<<probexpdate<<" Month";
               cout<<"\n Supplier Name:"<<supplierfirstname<<" "<<suppliermiddlename<<" "<<supplierlastname;
               cout<<"\n Supplier Phone Number:"<<supplierphone;
            }

            void viewmenuproduct()
            {
                    cout<<"\n\t\t"<<productname<<"\t "<<prodbrand<<"\t "<<producttype<<"\t\t"<<priceperproduct;
            }


public:
            //METHOD FOR ADD PIZZA PRODUCT DETAILS
            void addpizzaproduct()
            {

                ifstream pizzaidin;
                pizzaidin.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productid.txt");
                getline(pizzaidin, line);
                stringstream pizzain(line);
                pizzain>>pizzaid1;
                pizzaid1++;
                pizzaidin.close();
                a:
                    cout<<"\n Enter Pizza Name:";
                    cin>>pizzaname;
                     if(alpha(*pizzaname)!=0)
                       {
                           goto b;
                       }

                       else
                        {
                          goto a;
                        }
                b:
                    cout<<"\n Enter Pizza Description:";
                    cin>>pizzadescription;
                    length_pizzadescription=strlen(pizzadescription);
                    if(length_pizzadescription>=1 && length_pizzadescription<=60)
                    {
                        goto c;
                    }
                    else
                    {
                        cout<<"\n **Enter Address valid (Minimum 20 characters) only";
                        goto b;
                    }
                c:  cout<<"\n Enter Pizza Size(small/normal/large)";
                    cin>>pizzasize;
                    if(strcmp(pizzasize,pizzasize1)==0)
                      {
                          d:
                                cout<<"\n Enter Price:";
                                while(!(cin>>pizzaprice))
                                {
                                    cout<<" **Please enter number values only \n";
                                    cin.clear();
                                    cin.ignore(2000000,'\n');
                                    cout<<"\n Enter Price:";
                                    cin>>pizzaprice;
                                }
                                if(pizzaprice>=70 && pizzaprice<=150)
                                {
                                    goto l;
                                }
                                else
                                {
                                    cout<<" **Enter Price Valid (70 to 150) Only:\n";
                                goto d;
                                }
                      }

                    else if(strcmp(pizzasize,pizzasize2)==0)
                        {
                                f:
                                cout<<"\n Enter Price:";
                                while(!(cin>>pizzaprice))
                                {
                                    cout<<" **Please enter number values only \n";
                                    cin.clear();
                                    cin.ignore(2000000,'\n');
                                    cout<<"\n Enter Price:";
                                    cin>>pizzaprice;
                                }
                                if(pizzaprice>=150 && pizzaprice<=300)
                                {
                                    goto l;
                                }
                                else
                                {
                                    cout<<" **Enter Price Valid (150 to 300) Only:\n";
                                    goto f;
                                }

                    }
                    else if(strcmp(pizzasize,pizzasize3)==0)
                        {
                                h:
                                cout<<"\n Enter Price:";
                                while(!(cin>>pizzaprice))
                                {
                                    cout<<" **Please enter number values only \n";
                                    cin.clear();
                                    cin.ignore(2000000,'\n');
                                    cout<<"\n Enter Price:";
                                    cin>>pizzaprice;
                                }
                                if(pizzaprice>=300 && pizzaprice<=450)
                                {
                                    goto l;
                                }
                                else
                                {
                                    cout<<" **Enter Price Valid (300 to 450) Only:\n";
                                    goto h;
                                }
                        }

                l:
                    cout<<"\n Enter Pizza Type:";
                    cin>>pizzatype;

                    if(strcmp(pizzaproducttype1,pizzatype)==0)
                    {
                        goto z;
                    }
                    else if(strcmp(pizzaproducttype2,pizzatype)==0)
                    {
                        goto z;
                    }
                    else
                    {
                        goto l;
                    }
                z:
                    ofstream pizzaidout;
                    string file = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productid.txt";
                    pizzaidout.open(file.c_str());
                    pizzaidout<<pizzaid1;
                    pizzaidout.close();
            }
            //METHOD FOR VIEW DETAILS OF PIIZA PRODUCT
            void viewpizzaproduct()
            {
                cout<<"\n "<<pizzaid1<<"\t"<<pizzaname<<"\t\t"<<pizzadescription<<"\t\t\t"<<pizzasize<<"\t\t"<<pizzatype<<"\t\t"<<pizzaprice;
            }

            void vieworderespizzaproduct()
            {
                cout<<"\n\t\t"<<pizzaname<<"\t\t"<<pizzasize<<"\t\t"<<pizzatype<<"\t\t"<<pizzaprice;
            }
};//END OF CLASS

class MenuPizza : protected Pizza , public discount
{
    public:
            int orderedpizza=0;
            int orderedproduct=0;

            string TIME;
            string t1,t2,t3;
            string DATE;
            string d1,d2,d3;


            int id;
            int pizzaitemnumber,pizzaswitchchoice;
            int flag=0;
            char searchpizzaname[15];
            string searchpizzaproducttype;
            int pizzaproducttype;



            //METHOD FOR SAVE PIZZA PRODUCT DETAILS INTO FILE
            void AddMenueProduct()
            {
                system("cls");
                Pizza pi;
                cout<<"\n How Many Products Want To Enter:";
                while(!(cin >> pizzaitemnumber))
                {
                    cout<<" **Enter Numbers Only\n";
                    cin.clear();
                    cin.ignore(2000000,'\n');
                    cout<<"\n How Many Products Want To Enter:";
                }

                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\menuproductdetails.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"\n error";
                }
                else
                {
                    for(pizzaswitchchoice=1;pizzaswitchchoice<=pizzaitemnumber;pizzaswitchchoice++)
                    {
                            pi.addmenuproduct();
                            file.write((char *)&pi,sizeof(Pizza));
                    }
                }
                 file.close();
            }
            void ViewMenueProduct()
            {
                Pizza pi;
                ifstream file;
                counti=0;

                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\menuproductdetails.dat",ios::binary | ios::out);
                if(!file.is_open())
                    {
                        cout<<"**error\n";
                    }
                else
                    {
                        while(file.read((char *)&pi,sizeof(Pizza)))
                            {
                                counti++;
                                flag=1;
                                pi.viewmenuproduct(counti);
                            }
                    }
               file.close();

                if(flag==0)
                    {
                        cout<<"**No Record Found";
                    }
                //getpizzaproductswitch();
            }
            void ViewMenueProductOrder()
            {
                Pizza pi;
                ifstream file;

                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\menuproductdetails.dat",ios::binary | ios::out);
                if(!file.is_open())
                    {
                        cout<<"**error\n";
                    }
                else
                    {
                        cout<<"\n No\tProduct Name\tProduct Brand\tProduct Price\tAvalable Stock";
                        while(file.read((char *)&pi,sizeof(Pizza)))
                            {
                                flag=1;
                                pi.viewmenuproduct();
                            }
                    }
               file.close();

                if(flag==0)
                    {
                        cout<<"**No Record Found";
                    }
                //getpizzaproductswitch();
            }


////////////////////////////////////////#################################################################################
//#######################################################################################################################
////////////////////////////////////////#################################################################################
//#######################################################################################################################
////////////////////////////////////////#################################################################################
//#######################################################################################################################


            void AddPizzaProduct()
            {
                system("cls");
                Pizza pi;
                cout<<"\n How Many Products Want To Enter:";
                while(!(cin >> pizzaitemnumber))
                {
                    cout<<" **Enter Numbers Only\n";
                    cin.clear();
                    cin.ignore(2000000,'\n');
                    cout<<"\n How Many Pizza Products Want To Enter:";
                }
                for(int pk=1;pk<=pizzaitemnumber;pk++)
                    {
                        fstream file;
                        file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::out|ios::in|ios::app);
                        if(!file.is_open())
                        {
                            cout<<"\n error";
                        }
                        else
                        {

                                    pi.addpizzaproduct();
                                    file.write((char *)&pi,sizeof(Pizza));
                        }
                         file.close();
                    }
            }

            void ViewPizzaProduct()
            {
                system("cls");
                Pizza pi;
                fstream file;

                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::out|ios::in);
                if(!file.is_open())
                    {
                        cout<<"**error\n";
                    }
                else
                    {
                        cout<<"\n No\tPizza Name\tPizza Decription\tPizza Size\tPizza Type\tPizza Price";

                        while(file.read((char *)&pi,sizeof(Pizza)))
                            {
                                cout<<"1\n";
                                flag=1;
                                //count++;
                                pi.viewpizzaproduct();
                                cout<<"2\n";
                            }
                            cout<<"3\n";
                        file.close();
                    }
                file.close();
                cout<<"4\n";

                if(flag==0)
                    {
                        cout<<"**No Record Found";
                    }
             cout<<"5\n";
            }



////////////////////////////////////////#################################################################################
//#######################################################################################################################
////////////////////////////////////////#################################################################################
//#######################################################################################################################
////////////////////////////////////////#################################################################################
//#######################################################################################################################

    private:
                time_t now= time(0);
                int texthorizontal()
                {
                    char input[100];
                    int index;
                    cout<<"\n Enter a string value:";
                    cin>>input;
                    for (index=0;input[index]!='\0';index++)
                    {
                    cout<<input[index]<<"\t\t\t\t\t\t"<<input[index];
                    cout<<"\n";
                    }
                    return 0;
                }
    public:
                /*void billgenerater()
                {
                    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\n\t\t\t\t <:D=> ";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Domino's Pizza"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\n\t\t----------------------------------------------------------"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"\n\t\tSHOW ROOM NO.1165 MILLENNIUM SQUARE COLLECTOR OFFICE ROAD,"
                                     "\n\t\t\tRupa Bhavani Rd, Solapur, Maharashtra 413003\n";
                    cout<<"\t\t\t\tCell No: 1860 210 0000\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\t\t----------------------------------------------------------\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                    cout<<"\t\tInvoice No:"<<" 100\t\t\t\t"<<"GST No:"<<"20157854"<<endl;
                    cout<<"\t\tDate:"<<" 18/06/2019\t\t\t"<<"Time:"<<" 21:12"<<endl;
                    cout<<"\t\tOrder No:"<<"65"<<endl;
                    cout<<"\t\tServer Name:"<<" Raj Gone\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\t\t----------------------------------------------------------\n";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"\t\t\t\t\tDelivery"<<endl;
                    cout<<"\n\t\tCustomer Name:"<<" Umesh Shriniwas Udata";
                    cout<<"\n\t\tCustomer Address:"<<" Flat No 73,Shreepath Apartment,\n\t\t\t\t\tAshok Chowk,Solapur.";
                    cout<<"\n\t\tCell No Of Customer:"<<" 7798320468\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\t\t----------------------------------------------------------\n";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"\t\tItem Name"<<"\t"<<"Quantity"<<"\t"<<"Price"<<"\t\t"<<"Amount"<<"\n\n\n\n\n\n\n\n\n\n";
                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\t\t----------------------------------------------------------\n";
                    SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                    cout<<"\t\tTotal Item:"<<"\t\t\t\t"<<"Total Amount:"<<"\n\n";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"\t\tThanks You... :) !  Visit Again... :)!!"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);

                }*/



            /*int Addtime (string CUSTNAME)
            {
                dateandtime dat;
                fstream file;

                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Ordertime.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"\n error";
                }
                else
                {
                            dat.time();
                            file.write((char *)&dat,sizeof(dateandtime));
                }
                 file.close();
            }
            string showtime(string CUSTNAME)
            {
                dateandtime dat;
                ifstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Ordertime.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"\n error";
                }
                else
                {
                          while(file.read((char *)&dat,sizeof(dateandtime)))
                            {

                                t1=hour;
                                t2=mini;
                                t3=sec;
                                TIME=t1+":"+t2+":"+t3;
                                return TIME;
                            }
                }
                 file.close();

            }


            int Adddate (string CUSTNAME)
            {
                dateandtime dat;
                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderdate.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"\n error";
                }
                else
                {
                            dat.date();
                            file.write((char *)&dat,sizeof(dateandtime));
                }
                 file.close();
            }

            string showdate(string CUSTNAME)
            {
                dateandtime dat;
                ifstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderdata.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"\n error";
                }
                else
                {
                          while(file.read((char *)&dat,sizeof(dateandtime)))
                            {

                                d1=dat.getday();
                                d2=dat.getmonth();
                                d3=dat.getyear();
                                DATE=d1+"/"+d2+"/"+d3;
                                return DATE;
                            }
                }
                 file.close();

            }*/



            float takeorderpizza()
            {
                pizzamenueprice=0;
                countn=0;
                cout<<"11\n";
                ViewPizzaProduct();

                ofstream pizzaidout;
                string filei = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productid.txt";
                pizzaidout.open(filei.c_str());
                pizzaidout<<"*****"<<endl;
                pizzaidout.close();
                int point;
                point:

                        Pizza pi;
                        ifstream file;
                        char *y="y";
                        char *n="n";
                        char choice[10];

                        file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::out);
                        if(!file.is_open())
                            {
                               // cout<<"**error\n";
                            }
                        else
                            {
                                cout<<"\n Enter Id";
                                cin>>id;
                                while(file.read((char *)&pi,sizeof(Pizza)))
                                    {
                                        flag=1;
                                        if(id==pi.getpizzaid())
                                        {
                                            pizzamenueprice=pizzamenueprice+pi.getpizzaprice();
                                            string file = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productid.txt";
                                            pizzaidout.open(file.c_str(),ios::app);
                                            pizzaidout<<id<<"\n";
                                            countn=countn+1;
                                            cout<<countn;
                                            pizzaidout.close();
                                            PizzaFlag=1;
                                            OrderCount++;
                                        }
                                    }
                            }
                       file.close();
                       cout<<"\n Wnat To Add Another Pizza(y/n):";
                       cin>>choice;
                       if(strcmp(choice,y)==0)
                       {
                           goto point;
                       }
                       else
                       {
                           return pizzamenueprice;
                       }
                        if(flag==0)
                            {
                                cout<<"**No Record Found";
                            }
                    return 0;
            }

            float takeorderproduct()
            {
                productmenueprice=0;
                countnn=0;
                ViewMenueProductOrder();


                ofstream pizzaidout;
                string filei = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productmenueid.txt";
                pizzaidout.open(filei.c_str());
                pizzaidout<<"*****"<<endl;
                pizzaidout.close();

                int point;
                point:

                        Pizza pi;
                        ifstream file;
                        char *y="y";
                        char *n="n";
                        char choice[10];

                        file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\menuproductdetails.dat",ios::binary | ios::out);
                        if(!file.is_open())
                            {
                                //cout<<"**error\n";
                            }
                        else
                            {
                                cout<<"\n Enter Id";
                                cin>>id;
                                while(file.read((char *)&pi,sizeof(Pizza)))
                                    {
                                        flag=1;
                                        if(id==pi.getproductid())
                                        {
                                            productmenueprice=productmenueprice+pi.getproductprice();
                                            string file = "C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productmenueid.txt";
                                            pizzaidout.open(file.c_str(),ios::app);
                                            pizzaidout<<id<<"\n";
                                            countnn=countnn+1;
                                            cout<<id;
                                            pizzaidout.close();
                                            ProductFlag=1;
                                            OrderCount++;
                                        }
                                    }
                            }
                       file.close();
                       cout<<"\n Wnat To Add Another Product(y/n):";
                       cin>>choice;
                       if(strcmp(choice,y)==0)
                       {
                           goto point;
                       }
                       else
                       {
                           return productmenueprice;
                       }
                        if(flag==0)
                            {
                                cout<<"**No Record Found";
                            }
                    return 0;
            }

            float takeprintbill(string CUNAME)
            {
                ifstream invoicein;
                    invoicein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\InvoiceNo.txt");
                    getline(invoicein, line);
                    stringstream invoiceline(line);
                    invoiceline>>InvoiceNo;
                invoicein.close();

                InvoiceNo++;

                ofstream invoiceout;
                    string m="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\InvoiceNo.txt";
                    invoiceout.open(m.c_str());
                    invoiceout<<InvoiceNo;
                invoiceout.close();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                ifstream ordernoin;
                ordernoin.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\OrderNo.txt");
                getline(ordernoin, line);

                    stringstream ordernoinline(line);
                    ordernoinline>>OrderNo;
                ordernoin.close();


                OrderNo++;

                ofstream ordernoout;
                    string p="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\OrderNo.txt";
                    ordernoout.open(m.c_str());
                    ordernoout<<OrderNo;
                ordernoout.close();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                time(&now);
                ifstream dailyorderreset;
                dailyorderreset.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\OrderNoDaily.txt");
                getline(dailyorderreset, line);
                    stringstream ordertimein(line);
                    ordertimein>>OrderNoDaily;
                dailyorderreset.close();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                if((now-OrderNoDaily)<=85000)
                     {}

                CustomerDetailsData CDD;
                CUSTNAME=CDD.AddFacetoFace();

                pizzamenueprice=0;
                productmenueprice=0;

                system("cls");
                //cout<<CUSTNAME<<endl;

               // Addtime(CUSTNAME);
               // Adddate(CUSTNAME);

                countm=0;
                Pizza pi;

                ifstream fin;
                ifstream file;
                ofstream fileout;




                    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

                    SetConsoleTextAttribute(h,FOREGROUND_RED);
                    cout<<"\n\t\t\t\t <:D=> ";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                    cout<<"Domino's Pizza"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED);
                    cout<<"\n\t\t----------------------------------------------------------"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                    cout<<"\n\t\tSHOW ROOM NO.1165 MILLENNIUM SQUARE COLLECTOR OFFICE ROAD,"
                                     "\n\t\t\tRupa Bhavani Rd, Solapur, Maharashtra 413003\n";
                    cout<<"\t\t\t\tCell No: 1860 210 0000\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED);
                    cout<<"\t\t----------------------------------------------------------\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_BLUE);
                    cout<<"\t\tInvoice No:"<<InvoiceNo<<" \t\t\t\t"<<"GST No:"<<"20157854"<<endl;
                    cout<<"\t\tDate:"<</*showdate(CUSTNAME)*/"DATE"<<" \t\t\t"<<"Time:"<</*showtime(CUSTNAME)*/"TIME"<<endl;
                    cout<<"\t\tOrder No:"<<OrderNo<<endl;
                    cout<<"\t\tServer Name:"<<CUNAME<<"\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED);
                    cout<<"\t\t----------------------------------------------------------\n";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                    cout<<"\t\t\t\t\tDelivery"<<endl;
                    cout<<"\n\t\tCustomer Name:"<<CUSTNAME;
                    cout<<"\n\t\tCustomer Address:"<<" Flat No 73,Shreepath Apartment,\n\t\t\t\t\tAshok Chowk,Solapur.";
                    cout<<"\n\t\tCell No Of Customer:"<<" 7798320468\n"<<endl;
                    SetConsoleTextAttribute(h,FOREGROUND_RED);
                    cout<<"\t\t----------------------------------------------------------\n";
                    SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                    cout<<"\n\t\tName\t\tBrand/Size\tType\tPrice";


                fin.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productid.txt");
                while(fin)
                {
                   // cout<<"2\n";
                    getline(fin, line);
                    stringstream orderpizzaid(line);
                    orderpizzaid>>orderedpizza;
                    countm=countm+1;
                        //cout<<"\ncoutnm="<<countm;

                        file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::out);
                        fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderpizza.dat",ios::binary | ios::out |ios::app);
                        if(!file.is_open())
                        {
                         //cout<<"**error\n";
                        }
                        else
                        {
                            file.read((char *)&pi,sizeof(Pizza));
                            while(!file.eof())
                            {
                                        if(orderedpizza==pi.getpizzaid())
                                        {
                                            //pi.viewpizzaproduct();
                                            if(countm>1)
                                            {
                                                if(countm<=countn+1)
                                                {
                                                    //pi.vieworderespizzaproduct();
                                                    fileout.write((char *)&pi, sizeof(Pizza));
                                                }
                                            }
                                        }
                                        file.read((char *)&pi,sizeof(Pizza));
                            }

                            fileout.close();
                            file.close();
                        }

                }
                fin.close();


                countm=0;
                fin.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\productmenueid.txt");
                while(fin)
                {
                    getline(fin, line);
                    stringstream orderproductid(line);
                    orderproductid>>orderedproduct;
                    countm=countm+1;
                    //cout<<"\ncoutnm  p="<<countm;

                        file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\menuproductdetails.dat",ios::binary | ios::out);
                        fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderproduct.dat",ios::binary | ios::out |ios::app);
                        if(!file.is_open())
                        {
                        //cout<<"**error\n";
                        }
                        else
                        {
                            file.read((char *)&pi,sizeof(Pizza));
                            while(!file.eof())
                            {
                                        if(orderedproduct==pi.getproductid())
                                        {
                                                    //pi.vieworderespizzaproduct();
                                                    if(countm>1)
                                                        {
                                                            if(countm<=countnn+1)
                                                            {
                                                                fileout.write((char *)&pi, sizeof(Pizza));
                                                            }
                                                        }
                                        }
                                        file.read((char *)&pi,sizeof(Pizza));
                            }

                            fileout.close();
                            file.close();
                        }

                }
                fin.close();

                if(PizzaFlag==1)
                {
                Pizza pi;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderpizza.dat",ios::binary | ios::out | ios::in);
                    //cout<<"\n PizzaName  PizzaSize  PizzaType  PizzaPrice";
                    while(file.read((char *)&pi,sizeof(Pizza)))
                        {
                            pi.vieworderespizzaproduct();
                            pizzamenueprice=pizzamenueprice+pi.getpizzaprice();
                        }
                file.close();
                PizzaFlag=0;
                }

                if(ProductFlag==1)
                {
                    Pizza pi;
                    file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderproduct.dat",ios::binary | ios::out | ios::in);
                        //cout<<"\n No\tProduct Name\tProduct Brand\tProduct Price\tAvalable Stock";
                        while(file.read((char *)&pi,sizeof(Pizza)))
                            {
                                flag=1;
                                pi.viewmenuproduct();
                                productmenueprice=productmenueprice+pi.getproductprice();
                            }
                    file.close();
                    ProductFlag=0;
                }


               // remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\OrderPizza.dat");
               // remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\Orderproduct.dat");




                SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"\t\t----------------------------------------------------------\n";
                SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);


                cout<<"\n\t\tTotal Pizza Price:"<<pizzamenueprice;
                cout<<"\n\t\tTotal Side Poduct Price:"<<productmenueprice;
                totalprice=pizzamenueprice+productmenueprice;

                cout<<"\n\n\t\tTotal Item:"<<OrderCount<<"\t\t\t"<<"Total Amount:"<<totalprice<<"\n\n";

                disc_percent=totalprice*(applydiscount()/100);
                totalprice=totalprice-disc_percent;
                cout<<"\n\t\tTotal Disscount:"<<disc_percent<<"\t\t"<<"Total Amount To Pay:"<<totalprice<<"\n\n";

                SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                cout<<"\t\tThanks You... :) !  Visit Again... :)!!"<<endl;
                SetConsoleTextAttribute(h,FOREGROUND_INTENSITY);
                OrderCount=0;

                return totalprice;
            }

            int deleteorder()
            {
                cout<<CUSTNAME;
                //rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderpizza.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\Orderpizza.dat")
                //delete ("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderpizza.dat");
                string mmm="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderpizza.dat";
                remove(mmm.c_str());

                mmm="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderproduct.dat";
                remove(mmm.c_str());

                mmm="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Ordertime.dat";
                remove(mmm.c_str());

                mmm="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\order\\"+CUSTNAME+" Orderdate.dat";
                remove(mmm.c_str());

                ifstream deletedin;
                deletedin.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\DeletedOreder.txt");
                getline(deletedin, line);
                stringstream deletedline(line);
                deletedline>>DeletedNO;
                deletedin.close();

                DeletedNO++;

                ofstream Deletedout;
                string m="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\DeletedOreder.txt";
                Deletedout.open(m.c_str());
                Deletedout<<DeletedNO;
                Deletedout.close();
                return 0;
            }



////////////////////////////////////////#################################################################################
//#######################################################################################################################
////////////////////////////////////////#################################################################################
//#######################################################################################################################
////////////////////////////////////////#################################################################################
//#######################################################################################################################




            void SearchPizzaProduct()
            {
                    flag=0;
                    system("cls");
                    Pizza pi;
                    //count=0;
                    cout<<"\n Enter Name of Pizza Product Want To Search:";
                    cin>>searchpizzaname;

                    fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::out|ios::in| ios::app);
                        if(!file.is_open())
                            {
                                cout<<"\n **Error: Unable to open file...\n";
                            }
                            else
                                {   cout<<"\n No\tPizza Name\tPizza Decription\tPizza Size\tPizza Type\tPizza Price";
                                    while(file.read((char *)&pi,sizeof(Pizza)))
                                        {
                                            if(strcmp(searchpizzaname,pi.getpizza())==0)
                                                {
                                                    flag=1;
                                                    pi.viewpizzaproduct();
                                                }
                                        }
                                }
                                if(flag==0)
                                    {
                                        system("cls");
                                        cout<<"\n**No Record Found";
                                    }
                           file.close();
                           getpizzaproductswitch();
            }

            //METHOD FOR DELETE THE PIZZA PRODUCT BY TH PIZZA NAME
            void DeletePizzaProduct()
            {
                ifstream filein;
                ofstream fileout;
                system("cls");
                Pizza pi;
                flag=0;

                 cout<<"\n\n\n\tDelete Record";
                 cout<<"\n\nEnter Name of Pizza Product Want to Delete  :  ";
                 cin>>searchpizzaname;

                 filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::in);
              if(!filein)
                  cout<<"File not found";
              else
                {
                   fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetailsnew.dat",ios::binary | ios::out);
                   filein.read((char *)&pi, sizeof(Pizza));

              while(!filein.eof())
                  {
                    if(strcmp(searchpizzaname,pi.getpizza()))
                            {
                                flag=1;
                                fileout.write((char *)&pi, sizeof(Pizza));
                            }
                    filein.read((char *)&pi, sizeof(Pizza));
                  }
                            filein.close();
                            fileout.close();

                remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat");
                rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetailsnew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat");
                }
              if(flag==0)
                 cout<<"\n\nSorry!!! Record Not Found ";

                getpizzaproductswitch();
        }

            //METHOD FOR UPDATE THE PIZZA PRODUCT BY THE PIZZA NAME
            void UpdatePizzaProduct()
            {
                flag=0;
                system("cls");
                Pizza pi;
                cout<<"Enter Name Of Product That Should Be Searched:";
                cin>>searchpizzaname;

               fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\Menupizzaproductdatafile\\pizzadetails.dat",ios::binary | ios::out |ios::in);
               if(!file.is_open())
                  {
                     cout<<"Error: Unable to open file....";
                  }
               else
                  {
                     file.read((char *)&pi,sizeof(Pizza));
                     while(!file.eof())
                       {
                          if(strcmp(searchpizzaname,pi.getpizza())==0)
                             {
                                file.seekg(0,ios::cur);
                                cout<<"\nEnter new record ";
                                pi.addpizzaproduct();
                                file.seekp(file.tellg()-sizeof(Pizza));
                                file.write((char *)&pi,sizeof(Pizza));
                                flag=1;
                              }
                            file.read((char *)&pi,sizeof(pi));
                        }
                    }

                if(flag==0)
                      {
                           system("cls");
                           cout<<"\n**No Record Found";
                      }
                       file.close();
                      getpizzaproductswitch();
            }

            //DISPLAY MENU
            int pizzaproduct()
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   Pizza Product System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t AddPizzaProduct \n\t\t\t2.\t DeletePizzaProduct \n\t\t\t3.\t SearchPizzaProduct \n\t\t\t4.\t ViewPizzaProduct \n\t\t\t5.\t UpdatePizzaProduct \n\t\t\t6.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> pizzaswitchchoice;
                 while(!cin.good())
                   {
                       system("cls");
                       cout<<"**Please enter number values only \n";
                       cin.clear();
                       cin.ignore(2000000,'\n');
                            cout<<"\n\n\t\t\t------------------------------";
                            cout<<"\n\t\t\t   Pizza Product System";
                            cout<<"\n\t\t\t------------------------------";
                            cout<<"\n\n\t\t\t What you want to do?\n";
                            cout<<"\n\t\t\t1.\t AddPizzaProduct \n\t\t\t2.\t DeletePizzaProduct \n\t\t\t3.\t SearchPizzaProduct \n\t\t\t4.\t ViewPizzaProduct \n\t\t\t5.\t UpdatePizzaProduct \n\t\t\t6.\tExit\n";
                            cout<<"\n\nEnter your option: ";
                       cin >> pizzaswitchchoice;
                   }
                return pizzaswitchchoice;
            }

            //SWITCH FUNCTION
            int getpizzaproductswitch()
            {
                pizzaswitchchoice=pizzaproduct();

                switch(pizzaswitchchoice)
                    {
                    case 1:
                        AddPizzaProduct();
                        getpizzaproductswitch();
                        break;
                    case 2:
                       DeletePizzaProduct();
                        break;
                    case 3:
                        SearchPizzaProduct();
                        break;
                    case 4:
                        ViewPizzaProduct();
                        getpizzaproductswitch();
                        break;
                    case 5:
                       UpdatePizzaProduct();
                        break;

                    case 6:
                        AddMenueProduct();
                        getpizzaproductswitch();
                        break;

                    case 7:
                        ViewMenueProduct();
                        getpizzaproductswitch();
                        break;

                    case 8:
                        return 0;

                    default:
                            system("cls");
                            cout<<"**Wrong Choice";
                            getpizzaproductswitch();
                }
        }
};//END OF CLASS
