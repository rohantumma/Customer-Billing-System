#include "includefiles.h"

//#include <dirent.h>
//#include "backup.cpp"
//#include "gstcal.cpp"


using namespace std;

class llogin
{
    private:
            int logincount=0;
            int choice=0;
            bool cinfail;
            int confirmation;
            char username[25];
            time_t now= time(0);
            string password;
            string password2;
            string line;
            string line1;

            string u;

            string c;

            int i;
            char p[25];
            long int filetimeint=0;

            int writetofile(string username)
            {
                ofstream writefile;
                string file = "C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpass.txt";

                writefile.open(file.c_str(),ios::app);

                // declaring character array : p
                //string to char

                p[password.length()];
                for (i = 0; i < sizeof(p); i++)
                    p[i] = password[i];

                ////encryption

                //// Encrypted string username
                for(i = 0; (i < 100 && username[i] != '\0'); i++)
                        username[i] = username[i] + 2; //the key for encryption is 3 that is added to ASCII value
                    //cout << "\nEncrypted string username: " << username << endl;

                //// Encrypted string password
                for(i = 0; (i < 100 && p[i] != '\0'); i++)
                        p[i] = p[i] + 2; //the key for encryption is 3 that is added to ASCII value
                                         //cout << "\nEncrypted string password: " << p << endl;

                writefile <<"$"<<endl<<username<<endl;
                writefile <<p<<endl<<"$$"<<endl;

                writefile.close();
                return 0;
                //choice=0;
                //mainmenu(choice);

            }

            int exit()
            {
                return 0;
            }

    public:

            int forgotpassword(string  u)
            {
                int countline=0;
                ifstream fin;
                fin.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpass.txt");
                ofstream writefile;

                string file = "C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpassnew.txt";
                writefile.open(file.c_str());

                while (fin)
                {
                        // Read a Line from File
                        getline(fin, line);
                        p[line.length()];
                        for (i = 0; i < sizeof(p); i++) {
                        p[i] = line[i];
                        }
                        //decencryption

                        for(i = 0; (i < 25 && p[i] != '\0'); i++)
                        p[i] = p[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value

                        line=p;

                        if(line==u)
                        {

                            line1=line;
                            cout<<"line1=="<<line1;
                            getline(fin, line);
                            getline(fin, line);
                            getline(fin, line);
                        }
                        else
                        {
                            p[line.length()];
                            for (i = 0; i < sizeof(p); i++)
                            p[i] = line[i];

                            for(i = 0; (i < 100 && p[i] != '\0'); i++)
                                p[i] = p[i] + 2;

                            writefile<<p<<endl;
                        }
               }
               writefile.close();
               fin.close();
               remove("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpass.txt");
               rename("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpassnew.txt","C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpass.txt");
                writingnewpass(line1);
                return 0;
            }

            int writingnewpass(string line1)
            {
                cout<<"line1="<<line1;
                cout <<"\n Please enter the password:";
                cin >> password;
                cout << "\n Please renter your password:";
                cin >> password2;

                if (password == password2)
                {
                    if((password.length()>=12)!=0)
                    {
                        cin.clear();
                        cin.ignore(80000,'\n');

                        writetofile(line1);
                    }
                    else
                    {
                        cout <<"**Sorry Password Must Be 12 char long\n";
                        registerpassword();
                    }
                }
                else{
                    cout <<"**Sorry Password And Username Are Same\n";
                    registerpassword();
                }
                return 0;
            }


    public:
            char *login()
            {
                string demo="demo";
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t        Cashier System   ";
                cout<<"\n\t\t\t------------------------------";
                cout << "\n Please enter your username: ";

                cin>>username;
                cout << "\n Please enter the password: ";
                cin >> password;
                int count;

                ifstream fin;
                fin.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpass.txt");
                time(&now);
                ifstream time;
                time.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\"+password+".txt");
                getline(time, line);
                    stringstream filetime(line);
                    filetime>>filetimeint;


                   if((now-filetimeint)>=300)
                     {
                        int tt=0;
                        int pp=0;
                        int m;
                        while (fin)
                            {
                            // Read a Line from File
                                getline(fin, line);
                                p[line.length()];
                                for (i = 0; i < sizeof(p); i++) {
                                    p[i] = line[i];
                                }
                                //decencryption

                                for(i = 0; (i < 25 && p[i] != '\0'); i++)
                                    p[i] = p[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value

                                line=p;
                                tt++;
                                if(username==line)
                                    {
                                        cout <<"username="<<line << endl;
                                        count=1;
                                        pp=tt;
                                        goto point;
                                    }
                                if(password==line)
                                    {
                                        m=tt--;
                                        m--;
                                        if(pp==m)
                                        {
                                        cout <<"password="<<line << endl;
                                        count=11;
                                        }
                                    }
                                point:;
                            }

                        fin.close();

                        if(count==11)
                            {
                               cout <<"\n You are being  logged in!";
                               cout<<username;
                               return username;
                            }
                        else{
                            cout<<"**Note Able To \n**Please Check UserName And Password\n";

                            if(logincount<3)
                            {
                                choice=1;
                                logincount++;
                                login();
                            }
                            else
                            {
                                cout<<"**You Are Out Of Your Limit\n";

                                    // convert now to string form
                                   ofstream logintime;
                                   string file = "C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\"+password+".txt";
                                    logintime.open(file.c_str());
                                    logintime<<now;
                                    logintime.close();
                                    return "00";
                            }
                        }
                     }
                else
                {
                    cout<<"**Wait For 5 Munits\n";
                    return "00";
                }
                return username;
            }

            void registerpassword()
            {
                cout <<"\n Please enter the password:";
                cin >> password;
                cout << "\n Please renter your password:";
                cin >> password2;

                if (password == password2)
                {
                    if((password.length()>=12)!=0)
                    {
                        cin.clear();
                        cin.ignore(80000,'\n');

                        writetofile(username);
                    }
                    else
                    {
                        cout <<"**Sorry Password Must Be 12 char long\n";
                        registerpassword();
                    }
                }
                else{
                    cout <<"**Sorry Password And Username Are Same\n";
                    registerpassword();
                }
            }

            char *registerme()
            {
                cout <<"\n Please enter your username:";
                cin>>username;
                cout << "\n Username:"<< username << "\n Confirm? \n\n[1] Yes\n[2] No" << endl;
                cin >> confirmation;
                if (confirmation == 1)
                {
                    ifstream fin;
                    fin.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\chashier\\chashierpass.txt");
                    while(fin)
                    {
                    // Read a Line from File
                        getline(fin, line);
                        p[line.length()];
                        for (i = 0; i < sizeof(p); i++) {
                            p[i] = line[i];
                        }
                        //decencryption
                        for(i = 0; (i < 25 && p[i] != '\0'); i++)
                            p[i] = p[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value

                        line=p;
                        //cout<<"Username="<<username<<"line="<<line;
                        if(username==line)
                            {
                                cout<<"**Username Is Already Used\n";
                                registerme();
                                //registerpassword();
                                i=1;
                            }
                    }
                    if(username!=line)
                    {
                        if((strlen(username)>=8)!=0)
                            registerpassword();
                        else
                        {
                         cout <<"**Sorry UserName Must Be 8 char long\n";
                         registerme();
                        }
                    }
                    fin.close();
                }
                else
                {
                    cout << "Sorry invalid input, Please try again" << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                    registerme();
                }

                return username;
            }
};
