#include "includefiles.h"

class discountandgst
{
    public:

        char disc_name[20];
        char disc_desc[50];
        float disc_percent;

    public:
            int count,flag;
            //Check Entered Data is Character or not
            char alpha(char disc_name)
            {
              if(isalpha(disc_name))
              {
                return disc_name;
              }
              else{
                    cout<<"\n **Enter char only";
                    return 0;
                  }
            }
            //Check Entered Data is Digit or not
            int digit(int disc_price)
            {
              if(isdigit(disc_price))
              {
                return 1;
              }
              else
                {
                    cout<<"\n **Enter Number only";
                    return 0;
                }
            }

            float getdiscount()
            {
                return disc_percent;
            }

        //Get Discount Name
        char *getdiscountname()
        {
            return disc_name;
        }

        //Adding the discount
        void add_discount()
        {
            a:
            cout<<"\n Enter discount name:";
            cin>>disc_name;
            if(alpha(*disc_name)!=0)
                {
                    goto b;
                }
            else
                {
                    goto a;
                }

            b:
            cout<<"\n Enter discount description:";
            cin>>disc_desc;
            if(alpha(*disc_desc)!=0)
            {
                goto c;
            }
            else
            {
                goto b;
            }

            c:
            cout<<"\n Enter Discount Percentage:";
             while(!(cin >> disc_percent))
               {
                   cout<<"\n **Enter Integers Only";
                   cin.clear();
                   cin.ignore(2000000,'\n');
                   if(disc_percent>0 && disc_percent<100)
                   {

                   }
                   else
                        goto c;

               }

        }

        //Displaying discount
        void view_discount(int count)
        {
            cout<<"\n\t\t\t\t"<<count<<"--Discount Details ";
            cout<<"\n Name:"<<disc_name;
            cout<<"\n Description:"<<disc_desc;
            cout<<"\n Discount Percentage:"<<disc_percent<<"%";
        }

};


class discount : public discountandgst
{
public:
    char searchdiscount[50];
    int discountswitchchoice;
    string path="C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DiscountFile\\discountandgst.dat";
    //Add discount in a file

    void Add_Discount()
    {
            system("cls");
            discountandgst disgst;

            fstream file;
            file.open(path,ios::binary | ios::out |ios::in| ios::app);
            if(!file.is_open())
            {
                cout<<"\n **Error....";
            }
            else
            {
                        disgst.add_discount();

                        file.write((char *)&disgst,sizeof(discountandgst));
            }
           file.close();
           //return to menu
           discountswitch();
    }
    //View discount in a file
    void View_Discount()
    {
                        system("cls");
                        count=0;
                        discountandgst disgst;
                        ifstream file;
                        file.open(path,ios::binary | ios::out);
                        if(!file.is_open())
                        {
                            cout<<"\n **Error: Unable to open a file...";
                        }
                        else
                        {
                            while(file.read((char *)&disgst,sizeof(discountandgst)))
                            {
                                flag=1;
                                count++;
                                disgst.view_discount(count);
                            }
                        }
                       file.close();
                       //return to menu
                       discountswitch();
    }

    //Delete discount from a file
    void Delete_Discount()
    {

                        ifstream filein;
                        ofstream fileout;
                        system("cls");
                        discountandgst disgst;
                        flag=0;
                        cout<<"\n\n\n\tDelete Record";
                        cout<<"\n\nEnter First Name of Discount to Delete  :  ";
                        cin>>searchdiscount;
                        filein.open(path,ios::binary | ios::in);
                        if(!filein)
                            cout<<"\n **File not found";
                        else
                        {
                            fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DiscountFile\\discountandgstnew.dat",ios::binary | ios::out);
                            filein.read((char *)&disgst, sizeof(discountandgst));

                            while(!filein.eof())
                            {
                                if(strcmp(searchdiscount,disgst.getdiscountname()))
                                {
                                    flag=1;
                                    fileout.write((char *)&disgst, sizeof(discountandgst));


                                }
                                filein.read((char *)&disgst, sizeof(discountandgst));
                            }
                            filein.close();
                            fileout.close();

                            remove("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DiscountFile\\discountandgst.dat");
                            rename("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DiscountFile\\discountandgstnew.dat","C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\DiscountFile\\discountandgst.dat");
                         }
                         if(flag==0)
                         {
                            cout<<"\n\nSorry!!! Record Not Found";
                         }

                       //return to menu
                        discountswitch();
    }

    float applydiscount()
    {
                        discountandgst disgst;
                        ifstream file;
                        file.open(path,ios::binary | ios::out);
                        if(!file.is_open())
                        {
                            cout<<"\n **Error: Unable to open a file...";
                        }
                        else
                        {
                            while(file.read((char *)&disgst,sizeof(discountandgst)))
                            {
                                disc_percent=disgst.getdiscount();
                                flag=1;
                            }
                        }
                       file.close();
                       return disc_percent;
    }

     //Discount Choice
    int getdiscountchoice()
    {
                    cout<<"\n\n\t\t\t------------------------------";
                    cout<<"\n\t\t\t  Discount Management System";
                    cout<<"\n\t\t\t------------------------------";
                    cout<<"\n\n\t\t\t What you want to do?\n";
                    cout<<"\n\t\t\t1.\t Add Discount \n\t\t\t2.\t View Discount \n\t\t\t3.\t Delete Discount\n\t\t\t4.\t Exit\n";
                    cout<<"\n\nEnter your option: ";
                    cin >> discountswitchchoice;
                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"\n **Please enter number values only... \n";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t------------------------------";
                        cout<<"\n\t\t\t Discount Management System";
                        cout<<"\n\t\t\t------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t Add Discount \n\t\t\t2.\t View Discount \n\t\t\t3.\t Delete Discount\n\t\t\t4.\t Exit\n";
                        cout<<"\n\n Enter your option: ";
                        cin >> discountswitchchoice;
                    }
                    //return user choice to the discount switch case function
                    return discountswitchchoice;
        }

    // Discount Switch Case(Menu)
    int discountswitch()
    {

                    discountswitchchoice=getdiscountchoice();
                    switch(discountswitchchoice)
                    {
                    case 1:
                        Add_Discount();
                        break;
                    case 2:
                        View_Discount();
                        break;
                    case 3:
                        Delete_Discount();
                        break;
                    case 4:
                        float p;
                        p=applydiscount();
                        cout<<"\np="<<p;
                        cin>>p;
                        return 0;
                    default:
                        system("cls");
                        cout<<"\n **Wrong Choice";
                        //return to menu
                        discountswitch();
                    }
        }
};
