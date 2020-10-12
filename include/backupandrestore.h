#ifndef BACKUPANDRESTORE_H
#define BACKUPANDRESTORE_H

#include "includefiles.h"

class dategeti
{
    private:
            int year,month,day,testting;
            string datestring;

            string dateyear,datemonth;
            stringstream ss;

    public:
            string dirname;
            string dateday;
            int Backupswitchchoice;

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

class backupandrestore : dategeti
{
        string sourfurniturebackupfile;
        string sourfurniturebackupfilename;
        string destifurniturebackupfile;
        string destifurniturebackupfilename;

        string sourcashierbackupfile;
        string sourcashierbackupfilename;
        string desticashierbackupfile;
        string desticashierbackupfilename;

        string sourmanagerbackupfile;
        string sourmanagerbackupfilename;
        string destimanagerbackupfile;
        string destimanagerbackupfilename;

    public:

        ifstream filein;
        ofstream fileout;

    private:
            template<class TP>
            int backupfiles(TP& tp,string sourfurniturebackupfile,string sourfurniturebackupfilename,string destifurniturebackupfile,string destifurniturebackupfilename)
            {
                    dirname=getdate();
                    system("cls");
                    filein.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\"+sourfurniturebackupfile+"\\"+sourfurniturebackupfilename+".dat",ios::binary | ios::in);
                    if(!filein)
                        cout<<"File not found";
                    else
                    {
                        fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\backupdata\\"+destifurniturebackupfile+"\\"+destifurniturebackupfilename+dateday+".dat",ios::binary | ios::out);
                        filein.read((char *)&tp, sizeof(tp));
                        while(!filein.eof())
                        {
                                cout<<"4\n";
                                fileout.write((char *)&tp, sizeof(tp));
                                filein.read((char *)&tp, sizeof(tp));
                        }
                        filein.close();
                        fileout.close();
                        cout<<"**Data BackUp Complete";
                    }
                return 0;
            }

            template <class FB>
            void FurnitureBackup(FB& fb)
            {
                sourfurniturebackupfile="FurnitureFile";
                sourfurniturebackupfilename="Furnituredata";
                destifurniturebackupfile="furnituredatabackup";
                destifurniturebackupfilename="FurnitureDataBackup";
                backupfiles(fb,sourfurniturebackupfile,sourfurniturebackupfilename,destifurniturebackupfile,destifurniturebackupfilename);
                BackUpswitch(fb);
            }

            template <class CB>
            void CashierBackup(CB& cb)
            {
                sourcashierbackupfile="CashierdataFile";
                sourcashierbackupfilename="cashierdata";
                desticashierbackupfile="cashierdatabackup";
                desticashierbackupfilename="CashierDatabackup";
                backupfiles(cb,sourcashierbackupfile,sourcashierbackupfilename,desticashierbackupfile,desticashierbackupfilename);
                BackUpswitch(cb);
            }

            template <class MB>
            void ManagerBackup(MB& mb)
            {
                sourmanagerbackupfile="ManagerdataFile";
                sourmanagerbackupfilename="managerdata";
                destimanagerbackupfile="managerdatabackup";
                destimanagerbackupfilename="ManagerDatabackup";
                backupfiles(mb,sourmanagerbackupfile,sourmanagerbackupfilename,destimanagerbackupfile,destimanagerbackupfilename);
                BackUpswitch(mb);
            }

            template <class DLB>
            void DeliveryboyBackup(DLB& dlb)
            {
                cout<<"4\n";
                sourmanagerbackupfile="DeliveryboyFile";
                sourmanagerbackupfilename="deliveryboydata";
                destimanagerbackupfile="deliveryboydatabackup";
                destimanagerbackupfilename="DeliveryboyDatabackup";
                backupfiles(dlb,sourmanagerbackupfile,sourmanagerbackupfilename,destimanagerbackupfile,destimanagerbackupfilename);
                BackUpswitch(dlb);
            }
                                    ////////////////////////
                                    ////////////////////////
                                    /////RESTORE_DATA///////
                                    ////////////////////////
                                    ////////////////////////
    public:
            backupandrestore();
            virtual ~backupandrestore();

            int getbackupdata()
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   BackUp Management System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t ManagerBackup \n\t\t\t2.\t CashierBackup \n\t\t\t3.\t FurnitureBackup \n\t\t\t4.\t DeliveryboyBackup \n\t\t\t5.\t UpdateFurniture \n\t\t\t6.\t BackUpFurniture \n\t\t\t7.\t RestoreFurniture \n\t\t\t8.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> Backupswitchchoice;

                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"**Please enter number values only \n";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t------------------------------";
                        cout<<"\n\t\t\t   BackUp Management System";
                        cout<<"\n\t\t\t------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t ManagerBackup \n\t\t\t2.\t CashierBackup \n\t\t\t3.\t FurnitureBackup \n\t\t\t4.\t DeliveryboyBackup \n\t\t\t5.\t UpdateFurniture \n\t\t\t6.\t BackUpFurniture \n\t\t\t7.\t RestoreFurniture \n\t\t\t8.\t Exit\n";
                        cout<<"\n\nEnter your option: ";
                        cin >> Backupswitchchoice;
                    }
                return Backupswitchchoice;
            }

            template <class BUP>
            int BackUpswitch(BUP& bup)
            {
                k:
                // funrestorebackupcashierfile restore;
                Backupswitchchoice=getbackupdata();
                switch(Backupswitchchoice)
                    {
                        case 1:
                            ManagerBackup(bup);
                            break;
                        case 2:
                            CashierBackup(bup);
                            break;
                        case 3:
                            cout<<"1\n";
                            FurnitureBackup(bup);
                            break;
                        case 4:
                            DeliveryboyBackup(bup);
                            break;
                        case 5:
                           // updatefurniture();
                            break;
                        case 6:
                           // restore.backupfiles();
                            goto k;
                            break;
                        case 7:
                           // restore.restorecashierfile();
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
            template<class RS>
            int restorefiles(RS& rs,string sourfurniturebackupfile,string sourfurniturebackupfilename,string destifurniturebackupfile,string destifurniturebackupfilename)
            {
                    cout<<"3\n";
                    cout<<"\n Enter Date Of Restoring BackUp(yera,month,day):";
                    cin>>dirname;
                    //system("cls");
                    cout<<sourfurniturebackupfile<<"\n"<<sourfurniturebackupfilename+dirname;
                    cout<<"\n"<<destifurniturebackupfile<<"\n"<<destifurniturebackupfilename;

                    filein.open("C:\\Users\\rohan\\Google Drive\\project7\\backupdata\\"+sourfurniturebackupfile+"\\"+sourfurniturebackupfilename+dirname+".dat",ios::binary | ios::in |ios::out);
                    if(!filein)
                        cout<<"File not found";
                    else
                    {
                        fileout.open("C:\\Users\\rohan\\Google Drive\\project7\\DataFiles\\"+destifurniturebackupfile+"\\"+destifurniturebackupfilename+".dat",ios::binary | ios::out | ios::in);
                        filein.read((char *)&rs, sizeof(rs));
                        while(!filein.eof())
                        {
                                cout<<"4\n";
                                fileout.write((char *)&rs, sizeof(rs));
                                filein.read((char *)&rs, sizeof(rs));
                        }
                        filein.close();
                        fileout.close();
                        cout<<"**Data BackUp Complete";
                    }
                return 0;
            }

            template <class MR>
            void ManagerRestore(MR& mr)
            {
                sourfurniturebackupfile="managerdatabackup";
                sourfurniturebackupfilename="ManagerDatabackup";
                destifurniturebackupfile="ManagerdataFile";
                destifurniturebackupfilename="managerdata";
                restorefiles(mr,sourfurniturebackupfile,sourfurniturebackupfilename,destifurniturebackupfile,destifurniturebackupfilename);
                Restoreswitch(mr);
            }

            template <class CR>
            void CashierRestore(CR& cr)
            {
                sourfurniturebackupfile="cashierdatabackup";
                sourfurniturebackupfilename="CashierDatabackup";
                destifurniturebackupfile="CashierdataFile";
                destifurniturebackupfilename="cashierdata";
                restorefiles(cr,sourfurniturebackupfile,sourfurniturebackupfilename,destifurniturebackupfile,destifurniturebackupfilename);
                Restoreswitch(cr);
            }

            template <class FR>
            void FurnitureRestore(FR& fr)
            {
                sourfurniturebackupfile="furnituredatabackup";
                sourfurniturebackupfilename="FurnitureDataBackup";
                destifurniturebackupfile="FurnitureFile";
                destifurniturebackupfilename="Furnituredata";
                restorefiles(fr,sourfurniturebackupfile,sourfurniturebackupfilename,destifurniturebackupfile,destifurniturebackupfilename);
                Restoreswitch(fr);
            }

            template <class DR>
            void DeliveryboyRestore(DR& dr)
            {
                sourfurniturebackupfile="deliveryboydatabackup";
                sourfurniturebackupfilename="DeliveryboyDatabackup";
                destifurniturebackupfile="DeliveryboyFile";
                destifurniturebackupfilename="deliveryboydata";
                restorefiles(dr,sourfurniturebackupfile,sourfurniturebackupfilename,destifurniturebackupfile,destifurniturebackupfilename);
                Restoreswitch(dr);
            }

    public:
            int getrestoredata()
            {
                cout<<"\n\n\t\t\t------------------------------";
                cout<<"\n\t\t\t   Restore Management System";
                cout<<"\n\t\t\t------------------------------";
                cout<<"\n\n\t\t\t What you want to do?\n";
                cout<<"\n\t\t\t1.\t ManagerRestore \n\t\t\t2.\t CashierRestore \n\t\t\t3.\t FurnitureRestore \n\t\t\t4.\t DeliveryboyRestore \n\t\t\t5.\t UpdateFurniture \n\t\t\t6.\t BackUpFurniture \n\t\t\t7.\t RestoreFurniture \n\t\t\t8.\t Exit\n";
                cout<<"\n\nEnter your option: ";
                cin >> Backupswitchchoice;

                    while(!cin.good())
                    {
                        system("cls");
                        cout<<"**Please enter number values only \n";
                        cin.clear();
                        cin.ignore(2000000,'\n');
                        cout<<"\n\n\t\t\t------------------------------";
                        cout<<"\n\t\t\t   BackUp Management System";
                        cout<<"\n\t\t\t------------------------------";
                        cout<<"\n\n\t\t\t What you want to do?\n";
                        cout<<"\n\t\t\t1.\t ManagerRestore \n\t\t\t2.\t CashierRestore \n\t\t\t3.\t FurnitureRestore \n\t\t\t4.\t DeliveryboyRestore \n\t\t\t5.\t UpdateFurniture \n\t\t\t6.\t BackUpFurniture \n\t\t\t7.\t RestoreFurniture \n\t\t\t8.\t Exit\n";
                        cout<<"\n\nEnter your option: ";
                        cin >> Backupswitchchoice;
                    }
                return Backupswitchchoice;
            }

            template <class RES>
            int Restoreswitch(RES& res)
            {
                k:
                Backupswitchchoice=getrestoredata();
                switch(Backupswitchchoice)
                    {
                        case 1:
                            ManagerRestore(res);
                            break;
                        case 2:
                            CashierRestore(res);
                            break;
                        case 3:
                            FurnitureRestore(res);
                            break;
                        case 4:
                            DeliveryboyRestore(res);
                            break;
                        case 5:
                           // updatefurniture();
                            break;
                        case 6:
                           // restore.backupfiles();
                            goto k;
                            break;
                        case 7:
                           // restore.restorecashierfile();
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

};
#endif // BACKUPANDRESTORE_H
