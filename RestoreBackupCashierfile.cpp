#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctime>

#include <dirent.h>


using namespace std;


class restorebackupcashierfile
{
    string dirname;
    string line;
    public:
        int restorecashierfile()
            {
                cout<<"\n Enter filename starting with CashierDatabackup (yera,month,day):";
                cin>>dirname;
                            ifstream fin;
                            fin.open("E:\\rohan\\project\\project7\\backupdata\\cashierdatabackup\\CashierDatabackup"+dirname+".dat",ios::binary |ios::in|ios::out);
                            ofstream writefile;
                            string file = "E:\\rohan\\project\\project7\\DataFiles\\\CashierdataFile\\cashierdata.dat";
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
                cout<<"**CashierData Restore Complete";
                return 0;
            }
};


