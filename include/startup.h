#include "includefiles.h"

#ifndef STARTUP_H
#define STARTUP_H

using namespace std;

class startup
{
    public:
        startup();
        void cls()
        {
            system("cls");
        }
        void LoadLogo()
        {
            cls();
            char welcome[50]="WELCOME";
            char welcome2[50]=" TO";
            char welcome3[50]=" Dominoz";
            char welcome4[50]=" Pizza SYSTEM";
            printf("\n\n\n\n\n\t\t\t");
            for(int wlc=0; wlc<strlen(welcome);wlc++)
            {
                printf(" %c",welcome[wlc]);
                Sleep(100);
            }
            printf("\n\n\t\t\t\t ");
            for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++)
            {
                printf(" %c",welcome2[wlc2]);
                Sleep(100);
            }
            printf("\n\n\n\t\t\t ");
            for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++)
            {
                if(welcome3[wlc3]!='D')
                {
                    printf(" %c",welcome3[wlc3]);
                }
                else
                {
                    printf(" %c",welcome3[wlc3]);
                }
                Sleep(100);
            }
            printf("\n\n\n\t\t\t\t ");
            for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++)
            {
                if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E')
                {
                    printf(" %c",welcome4[wlc3]);
                }
                else
                {
                    printf(" %c",welcome4[wlc3]);
                }
                Sleep(100);
            }
        }

        void backuploader(void)
        {
            for (int i=15;i<=100;i+=5)
            {
                cls();
                printf("\n\n\n\n\n\n\n\t\t\t\t");
                printf("%d %% Backing UP DATA...\n\n\t\t",i);
                printf("");
                for (int j=0; j<i;j+=2)
                {
                      printf(" ");
                }
                Sleep(50);
                if(i==90 || i==50 || i==96 || i==83)
                {
                    Sleep(50);
                }
            }
        }
    virtual ~startup();

    protected:

    private:
};

#endif // STARTUP_H
