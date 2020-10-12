#include "includefiles.h"
#include "backupandrestore.h"

class Pizza
{
    private:
            char pizzaname[15];
            char pizzadescription[61];
            char pizzasize[20];
            char pizzatype[20];
            int id;

            float pizzaprice;

    public:
            float getprice()
            {
                return pizzaprice;
            }
            void addpizza()
            {
                cout<<"\nId";
                cin>>id;
                cout<<"\n Enter pizzaname:";
                cin>>pizzaname;
                cout<<"\n Enter Pizza Desp";
                cin>>pizzadescription;
                cout<<"\n Enter Size";
                cin>>pizzasize;
                cout<<"\n Enter Type";
                cin>>pizzatype;
                cout<<"\n ENter price";
                cin>>pizzaprice;
            }

            void viewpizza()
            {
                cout<<pizzaname<<pizzadescription<<pizzasize<<pizzatype<<pizzaprice;
            }
};

class pizzamenue : Pizza
{
    public:
            int flag;
            float price;
            void AddPizza()
            {

                system("cls");
                Pizza man;

                fstream file;
                file.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\pk.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                    cout<<"**File Not Present\n";

                else
                {
                    man.addpizza();
                    file.write((char *)&man,sizeof(Pizza));
                }
               file.close();
            }

            float ViewPizza()
            {
                flag=0;
                Pizza man;

                fstream file("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\ManagerdataFile\\pk.dat",ios::binary | ios::out |ios::in| ios::app);
                if(!file.is_open())
                {
                    cout<<"**error";
                }
                else
                {
                    while(file.read((char *)&man,sizeof(Pizza)))
                    {

                               flag=1;
                               price=man.getprice();
                               man.viewpizza();
                    }
                }
                if(flag==0)
                {
                   system("cls");
                   cout<<"\n**No Record Found";
                }
                file.close();
                return price;
            }
};
