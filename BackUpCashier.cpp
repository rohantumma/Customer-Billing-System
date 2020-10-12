#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctime>

#include <dirent.h>


using namespace std;


class dateget
{
    int year,month,day,testting;
    string datestring;

    string dateyear,datemonth;
    stringstream ss;

    public:
        string dateday;
        string tostring(int testting)
        {
            string demo;
            ss << testting;
            demo = ss.str();
            return demo;
        }

        string getdate()
        {
            // current date/time based on current system
           time_t now = time(0);
           // convert now to string form
           char* dt = ctime(&now);
           // convert now to tm struct for UTC
           tm *gmtm = gmtime(&now);
           year=1900 +gmtm->tm_year;
           month=1+gmtm->tm_mon;
           day=gmtm->tm_mday ;

           dateyear=tostring(year);
           datemonth=tostring(month);
           dateday=tostring(day);

           dt = asctime(gmtm);
           datestring=dt;
           return datestring;
        }
};

class backupdata : dateget
{
    string dirname;
    string line;
    public:
        int backupfiles()
            {
                dirname=getdate();
                            ifstream fin;
                            fin.open("E:\\rohan\\project\\project7\\DataFiles\\CashierdataFile\\cashierdata.dat",ios::binary |ios::in|ios::out);
                            ofstream writefile;
                            string file = "E:\\rohan\\project\\project7\\backupdata\\cashierdatabackup\\CashierDatabackup"+dateday+".dat";
                            writefile.open(file.c_str());
                                while (fin)
                                    {
                                    // Read a Line from File
                                        getline(fin, line);
                                        // write to a Line File
                                         writefile<<line<<endl;
                                    }
                            writefile.close();
                            fin.close();
                cout<<"**Data BackUp Complete";
                return 0;
            }
};

