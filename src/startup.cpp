#include "startup.h"

startup::startup()
{
	for (int i=0;i<=100;i+=5)
    {
        system("cls");
		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Loading...\n\n\t\t",i);
		printf("");
		for (int j=0; j<i;j+=2)
		{
            printf(" ");
		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83)
		{
			Sleep(100);
		}
    }
}

startup::~startup()
{

}
