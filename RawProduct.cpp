#include "includefiles.h"
#include "backupandrestore.h"

using namespace std;

class rawproduct
{
   private:
            char rawproductname[15],rawproducttype[15],dealerfirstname[10],dealermiddlename[10],dealerlastname[10];
            unsigned long int rawexpdate,rawquantity;
            int dd,mm,yyyy;
            LONGLONG dealerphone;
            string veg,nonveg;
            float pricerawproduct;

            char *raw_p_Goods="Goods";
            char *raw_p_Vegitable="Vegetables";
            char *raw_p_Spices="Spices";
            char *raw_p_Cook_Essen="Cooking";
            char *raw_p_Grocery="Grocery";

            char *raw_p_goods="goods";
            char *raw_p_vegitable="vegetables";
            char *raw_p_spices="spices";
            char *raw_p_cook_Essen="cooking";
            char *raw_p_grocery="grocery";

   public:

            char alpha(char rawproductname)
            {
                if(isalpha(rawproductname))
                   {
                       return rawproductname;
                   }
                else{
                    cout<<" **Enter Char Only\n";
                    return 0;
                   }
            }

            char *getrawproductname()
            {
                return rawproductname;
            }

            char *getrawproducttype()
            {
                return rawproducttype;
            }
            //GETTING RAW PRODUCT DETAILS FROM ADMIN
            void addrawproduct()
            {
                a:
                    cout<<"\n Enter Raw Product Name:";
                    cin>>rawproductname;

                      if(alpha(*rawproductname)!=0)
                       {
                           if(strlen(rawproductname)>=3)
                                goto m;
                           else
                           {
                               cout<<" **Enter Valid Raw ProductName\n";
                               goto a;
                           }
                       }
                       else
                          goto a;
                m:
                    cout<<"\n Enter Raw Product Type:";
                    cin>>rawproducttype;
                    if(alpha(*rawproducttype)!=0)
                       {
                           if (strcmp(rawproducttype,raw_p_Goods)==0 ||strcmp(rawproducttype,raw_p_Vegitable)==0 ||strcmp(rawproducttype,raw_p_Spices)==0||strcmp(rawproducttype,raw_p_Cook_Essen)==0 ||strcmp(rawproducttype,raw_p_Grocery)==0 ||strcmp(rawproducttype,raw_p_goods)==0 ||strcmp(rawproducttype,raw_p_vegitable)==0 ||strcmp(rawproducttype,raw_p_spices)==0||strcmp(rawproducttype,raw_p_cook_Essen)==0 ||strcmp(rawproducttype,raw_p_grocery)==0 )
                                goto b;
                           else
                           {
                               cout<<" **Enter Valid Raw ProductName\n";
                               goto m;
                           }
                       }
                       else
                          goto a;

                b:
                    cout<<"\n Enter Dealer Name(First,Middle,Last):";
                    cin>>dealerfirstname;
                    if(alpha(*dealerfirstname)!=0)
                        {
                            if(strlen(dealerfirstname)>=2)
                                goto c;
                            else
                            {
                                cout<<" **Please Enter Valid Dealer Name\n";
                                goto d;
                            }
                        }
                    else
                        goto d;
                c:
                   cin>>dealermiddlename;
                    if(alpha(*dealermiddlename)!=0)
                        {
                            if(strlen(dealermiddlename)>=1)
                                goto d;
                            else
                            {
                                cout<<" **Please Enter Valid Dealer Middle Name\n";
                                goto c;
                            }
                        }
                    else
                        goto c;
                d:
                    cin>>dealerlastname;
                    if(alpha(*dealerlastname)!=0)
                        {
                            if(strlen(dealerlastname)>=2)
                                goto e;
                            else
                            {
                                cout<<"**Please Enter Valid Dealer Last Name\n";
                                goto d;
                            }
                        }
                    else
                        goto d;
                e:

                cout<<"\n Enter Dealer Phone Number:";
                while(!(cin >> dealerphone))
                       {
                           cout<<" **Enter Integers Only\n";
                           cin.clear();
                           cin.ignore(20000,'\n');
                           cout<<"\n Enter Dealer Phone Number:";
                       }
                      if(dealerphone>=100000000 && dealerphone<=9999999999)
                       {
                           goto f;
                       }
                       else
                       {
                           cout<<" **Enter 10 Digits Only\n";
                           goto e;
                       }

                f:
                cout<<"\n Enter Price Of Raw Product (Per/Product)Rs:";
                while(!(cin >> pricerawproduct))
                   {
                       cout<<" **Enter Integers Only\n";
                       cin.clear();
                       cin.ignore(20000,'\n');
                       cout<<"\n Enter Price Of Raw Produce(Rs):";
                   }
                   if(pricerawproduct>=1 && pricerawproduct<=3000)
                       {
                           goto g;
                       }
                       else
                       {
                           cout<<" **Enter Valid Amount\n";
                           goto f;
                       }
                    g:
                    cout<<"\n Enter Quantity Of Raw Product:";
                          while(!(cin >> rawquantity))
                            {
                               cout<<" **Enter Integers Only\n";
                               cin.clear();
                               cin.ignore(20000,'\n');
                               cout<<"\n Enter Quantity Of Product:";
                            }
                           if(rawquantity>=1 && rawquantity<=1000)
                               {
                                   goto h;
                               }
                               else
                               {
                                   cout<<" **Enter Valid Quantity\n";
                                   goto g;
                               }

                 h:
                    time_t now;
                    struct tm nowLocal;
                    now=time(NULL);
                    nowLocal=*localtime(&now);
                    dd=nowLocal.tm_mday;
                    mm=nowLocal.tm_mon+1;
                    yyyy=nowLocal.tm_year+1900;

                cout<<"\n Enter Probable Expiry Month(1 to 12):";
                 while(!(cin>>rawexpdate))
                   {
                       cout<<" **Enter Integers Only\n";
                       cin.clear();
                       cin.ignore(20000,'\n');
                       cout<<"\n Enter Probable Expiry Date(1 to 12):";
                   }
                   if(rawexpdate>=1 && rawexpdate<=12)
                   {}
                   else
                   {
                        cout<<" **Enter Expiry Date Given Range Only\n";
                        goto h;
                   }
            }
            //VIEW ALL RAW PRODUCT
            void viewrawproduct(int count)
            {
                cout<<"\n\t\t\t\t"<<count<<"--Menu Product Details ";
                cout<<"\n Raw Product Name:"<<rawproductname;
                cout<<"\n Raw Product Type:"<<rawproducttype;
                cout<<"\n Dealer Name:"<<dealerfirstname<<" "<<dealermiddlename<<" "<<dealerlastname;
                cout<<"\n Dealer Phone Number:"<<dealerphone;
                cout<<"\n Price Of Raw Product(Rs):"<<pricerawproduct;
                cout<<"\n Quantity:"<<rawquantity;
                cout<<"\n Total Amount:"<<pricerawproduct*rawquantity;
                cout<<"\n Delivery-Date:"<<dd<<"/"<<mm<<"/"<<yyyy;
                cout<<"\n Probable Expiry Month Of Raw Product:"<<rawexpdate<<" Months";
                cout<<endl;
            }
            void UpdateRawProductQuantity()
            {
                rawquantity=rawquantity-1;
            }
};

class RawMainProduct : protected rawproduct
{
    private:
            boolean flag;
            char searchrawproductname[15];
            int count;
            int menurawproductchoice,rawproductitemnumber;
            char searcherawproductname[15];
            char searcherawproducttype[15];

         //ADD RAW PRODUCTS DETAILS
         void AddRawProduct()
        {
            system("cls");
            rawproduct rp;
            cout<<"\n How Many Raw Products Want To Enter:";
            while(!(cin >> rawproductitemnumber))
            {
                cout<<" **Enter Numbers Only\n";
                cin.clear();
                cin.ignore(2000000,'\n');
                cout<<"\n How Many Products Want To Enter:";
            }

            fstream file;
            file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat",ios::binary | ios::out |ios::in| ios::app);
            if(!file.is_open())
            {
                cout<<"\n error";
            }
            else
            {
                for(menurawproductchoice=1;menurawproductchoice<=rawproductitemnumber;menurawproductchoice++)
                {
                        rp.addrawproduct();
                        file.write((char *)&rp,sizeof(rawproduct));
                }
            }
           file.close();
           rawproductswitch();
        }

            //VIEW ALL RAW PRODUCTS
         void ViewRawProduct()
        {
            system("cls");
            int count=0;
            rawproduct rp;
            ifstream file;
            //menuswitchchoice=1;
            file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat",ios::binary | ios::out);
            if(!file.is_open())
            {
                cout<<"**error\n";
            }

            else
            {
                while(file.read((char *)&rp,sizeof(rawproduct)))
                {
                    //cout<<"\n\t"<<menuswitchchoice<<"-Product\n";
                    flag=1;
                    count++;
                    rp.viewrawproduct(count);
                    //menuswitchchoice++;
                }
            }
            file.close();

           if(flag==0)
           {
               cout<<"**No Record Found";
           }
           rawproductswitch();
        }

    //SEARCH PARTICULAR RAW PRODUCT
        void SearchRawProduct()
        {
            flag=0;
            system("cls");
            rawproduct rp;
            a:
            cout<<"\n Enter Name of Raw Product Want To Search :";
            cin>>searchrawproductname;
            if(alpha(*searchrawproductname)!=0)
            {
                goto b;
            }
            else
            {
                cout<<" **Enter Valid Raw Product Name\n";
                goto a;
            }
            b:
            cout<<"\n Enter Name of Raw Product Type Want To Search :";
            cin>>searcherawproducttype;
            if(alpha(*searcherawproducttype)!=0)
            {}
            else
            {
                cout<<" **Enter Valid Raw Product Type Name\n";
                goto b;
            }

            fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat",ios::binary | ios::out|ios::in| ios::app);
               if(!file.is_open())
                  {
                      cout<<"\n **Error: Unable to open file...\n";
                  }
               else
                  {
                     while(file.read((char *)&rp,sizeof(rawproduct)))
                    {
                     if(strcmp(searchrawproductname,rp.getrawproductname())==0 && strcmp(searcherawproducttype,rp.getrawproducttype())==0 )
                        {
                         flag=1;
                         rp.viewrawproduct(count);
                        }
                    }
                  }
                if(flag==0)
                       {
                           system("cls");
                           cout<<"\n**No Record Found";
                       }
                       file.close();
                       rawproductswitch();

        }

        //DELETE PARTICULAR RAW PRODUCT
        void DeleteRawProduct()
            {
             ifstream filein;
             ofstream fileout;
             system("cls");
             rawproduct rp;
             flag=0;

                 cout<<"\n\n\n\tDelete Record";
                 cout<<"\n Enter Name of Raw Product Want to Delete  :  ";
                 cin>>searchrawproductname;
                 cout<<"\n Enter Name of Raw Product Type Want To Search :";
                 cin>>searcherawproducttype;

                 filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat",ios::binary | ios::in);
              if(!filein)
                  cout<<"File not found";
              else
                {
                   fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductDatanew.dat",ios::binary | ios::out);
                   filein.read((char *)&rp, sizeof(rawproduct));

              while(!filein.eof())
                  {
                    if(strcmp(searchrawproductname,rp.getrawproductname())&& strcmp(searcherawproducttype,rp.getrawproducttype()))
                            {
                                flag=1;
                                fileout.write((char *)&rp, sizeof(rawproduct));
                                //cout<<"Deleted..";
                            }
                    filein.read((char *)&rp, sizeof(rawproduct));
                  }
                            filein.close();
                            fileout.close();

                remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat");
                rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductDatanew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat");
                }
              if(flag==0)
                 cout<<"\n\nSorry!!! Record Not Found ";

                rawproductswitch();
             }

     //UPDATE PARTICULAR RAW MATERIAL
         void UpdateRawProduct()
          {
                flag=0;
                system("cls");
                rawproduct rp;
                 cout<<"\n Enter Name of Raw Product Want to Delete  :  ";
                 cin>>searchrawproductname;
                 cout<<"\n Enter Name of Raw Product Type Want To Search :";
                 cin>>searcherawproducttype;

               fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\RawproductdataFile\\RawProductData.dat",ios::binary | ios::out |ios::in);
               if(!file.is_open())
                  {
                     cout<<"\n **Error: Unable to open file....";
                  }
               else
                  {
                     file.read((char *)&rp,sizeof(rawproduct));
                     while(!file.eof())
                       {
                          if(strcmp(searcherawproductname,rp.getrawproductname())==0 && strcmp(searcherawproducttype,rp.getrawproducttype())==0 )
                             {
                                file.seekg(0,ios::cur);
                                cout<<"\nEnter new record ";
                                rp.addrawproduct();
                                file.seekp(file.tellg()-sizeof(rawproduct));
                                file.write((char *)&rp,sizeof(rawproduct));
                                flag=1;
                              }
                            file.read((char *)&rp,sizeof(rp));
                        }
                    }

                if(flag==0)
                      {
                           system("cls");
                           cout<<"\n**No Record Found";
                      }
                       file.close();
                       rawproductswitch();
            }

    private:
        int menurawproduct()
        {
            cout<<"\n\n\t\t\t------------------------------";

            cout<<"\n\t\t\t------------------------------";
            cout<<"\n\n\t\t\t What you want to do?\n";
           cout<<"\n\t\t\t1.\t AddMenuProduct \n\t\t\t2.\t DeleteMenuProduct \n\t\t\t3.\t SearchMenuProduct \n\t\t\t4.\t ViewMenuProduct \n\t\t\t5.\t UpdateMenuProduct \n\t\t\t6.QUANTITY\n";
            cout<<"\n\nEnter your option: ";
            cin >> menurawproductchoice;
             while(!cin.good())
               {
                   system("cls");
                   cout<<"**Please enter number values only \n";
                   cin.clear();
                   cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t------------------------------";
                        cout<<"\n\t\t\t   Raw Product   ";
                        cout<<"\n\t\t\t------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t AddMenuProduct \n\t\t\t2.\t DeleteMenuProduct \n\t\t\t3.\t SearchMenuProduct \n\t\t\t4.\t ViewMenuProduct \n\t\t\t5.\t UpdateMenuProduct \n\t\t\t6.QUANTITY\n";
                        cout<<"\n\nEnter your option: ";
                   cin >> menurawproductchoice;
               }
            return menurawproductchoice;
        }
public:
       int rawproductswitch()
        {
            menurawproductchoice=menurawproduct();

            switch(menurawproductchoice)
                {
                case 1:
                    AddRawProduct();
                    break;
                case 2:
                   DeleteRawProduct();
                    break;
                case 3:
                    SearchRawProduct();
                    break;
                case 4:
                    ViewRawProduct();
                    break;
                case 5:
                   UpdateRawProduct();
                    break;
                /*case 6:
                    b.backupfiles();
                    goto k;
                    break;
                case 7:
                    restore.restorecashierfile();
                    goto k;
                    break;*/
                case 6:UpdateRawProductQuantity();
                        break;
                case 7:return 0;
                default:
                        system("cls");
                        cout<<"**Wrong Choice";
                        rawproductswitch();
            }
    }
};
