#include "includefiles.h"

using namespace std;

class adminlogin
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
            string roll;

            int i;
            char p[25];
            long int filetimeint=0;

            int writetofile(string username)
            {
                ofstream writefile;
                string file = "C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\manager\\managerpass.txt";

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
            int login(string roll)
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   "<<roll<<" LogIn   ";
                cout<<"\n\t\t\t------------------------------";
                cout << "\n Please enter your username: ";
                cin>>username;
                cout << "\n Please enter the password: ";
                cin >> password;
                int count;

                ifstream fin;
                fin.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\manager\\managerpass.txt");
                time(&now);
                ifstream time;
                time.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\manager\\"+password+".txt");
                getline(time, line);
                    stringstream filetime(line);
                    filetime>>filetimeint;


                   if((now-filetimeint)>=600)
                     {
                        int point;
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

                        if(count==11){
                               cout <<"\n You are being  logged in!";
                               return 1;
                            }
                        else{
                            cout<<"**Note Able To \n**Please Check UserName And Password\n";

                            if(logincount<3)
                            {
                                choice=1;
                                logincount++;
                                login(roll);
                            }
                            else
                            {
                                cout<<"**You Are Out Of Your Limit\n";
                                    // convert now to string form
                                   ofstream logintime;
                                   string file = "C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\manager\\"+password+".txt";
                                    logintime.open(file.c_str());
                                    logintime<<now;
                                    logintime.close();
                            }
                        }
                     }
                else
                {
                    cout<<"**Wait For 10 Munits\n";
                    return 0;
                }
                return 0;
            }
    public:
            int registerpassword()
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
                        return 1;
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

            int registerme()
            {
                cout <<"\n Please enter your username:";
                cin>>username;
                cout << "\n Username:"<< username << "\n Confirm? \n\n[1] Yes\n[2] No" << endl;
                cin >> confirmation;
                if (confirmation == 1)
                {
                    ifstream fin;
                    fin.open("C:\\Users\\rohan\\Google Drive\\project7\\PassWord\\manager\\managerpass.txt");
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
                                i=1;
                            }
                    }
                    if(username!=line)
                    {
                        if((strlen(username)>=8)!=0)
                            {
                                registerpassword();
                                return 1;
                            }
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
            }
};
