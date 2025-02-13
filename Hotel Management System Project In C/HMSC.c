#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void add(); // FUNCTIONS
void list();
void edit(); // GLOBALLY DECLARED FUNCTIONS N VARIABLE
void delete1();
void search();

void setcolor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xB0) + (ForgC & 0x0B);
		//	SetConsoleTextAttributes(hStdOut,wColor);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void first()
{
	printf("\n \n       ****************************************************************************************************");
	printf("\n  \n \n                             BHARATI VIDYAPEETH DEEMED UNIIVERSITY, PUNE");
	printf("\n  \n                           Yashwantrao Mohite Institute of Management, Karad");
	printf("\n  \n                                        HOTEL MANAGEMENT SYSTEM");
	printf("\n  \n                                             Project By");
	printf("\n  \n                                     -- Ms. Aarti Mallayya Swami ");
	printf("\n  \n                                     -- Ms. Anushka Sanjay Yadav ");
	printf("\n  \n \n                                         Under the guidance of:");
	printf("\n  \n                                          DR. A. M. PATIL-NIKAM ");
	printf("\n  \n                                                                        PRESS ANY KEY TO CONTINUE...");
	printf("\n \n       ****************************************************************************************************");

	getch();
	system("cls");
}

void login()
{
	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "user";
	char pass[10] = "pass";
	do
	{
		system("cls");

		printf("\n\n  **************************  LOGIN FORM  **************************  ");
		printf(" \n\n                       ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n\n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13)
				break;
			else
				printf("*");
			i++;
		}
		pword[i] = '\0';
		// char code=pword;
		i = 0;
		// scanf("%s",&pword);
		if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0)
		{
			printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");

			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;

			getch();
		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();
	}
	system("cls");
}

struct CustomerDetails // STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
} s;

int main()
{ // MAIN FUNCTION
	int i = 0;

	time_t t;
	time(&t);
	char customername;
	char choice;
	first();
	login();
	system("cls");
	while (1) // INFINITE LOOP
	{
		system("cls");
		setcolor(10);
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n\n");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n\n");
		setcolor(10);
		printf("\t\t *Please enter your choice for menu*:");
		printf("\n\n");
		printf(" \n Enter 1 -> Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 -> Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 6 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\nCurrent date and time : %s", ctime(&t));
		for (i = 0; i < 80; i++)
			printf("-");

		choice = getche();
		choice = toupper(choice);
		switch (choice) // SWITCH STATEMENT
		{
		case '1':
			add();
			break;
		case '2':
			list();
			break;
		case '3':
			delete1();
			break;
		case '4':
			search();
			break;
		case '5':
			edit();
			break;
		case '6':
			system("cls");
			printf("\n\n\t *****THANK YOU*****");
			printf("\n\t FOR TRUSTING OUR SERVICE");
			//	Sleep(2000);
			exit(0);
			break;
		default:
			system("cls");
			printf("Incorrect Input");
			printf("\n Press any key to continue");
			getch();
		}
	}
}

void add()
{
	FILE *f;
	char test;
	f = fopen("add.txt", "a+");
	if (f == 0)
	{
		f = fopen("add.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while (1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s", s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s", s.name);
		printf("Enter Address:\n");
		scanf(" %s", s.address);
		printf("Enter Phone Number:\n");
		scanf("%s", s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s", s.nationality);
		printf("Enter Email:\n");
		scanf(" %s", s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s", &s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s", &s.arrivaldate);
		fwrite(&s, sizeof(s), 1, f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if ((f = fopen("add.txt", "r")) == NULL)
		exit(0);
	system("cls");
	printf("ROOM  ");
	printf(" NAME\t ");
	printf("\t\t    ADDRESS ");
	printf("\t\t         PHONENUMBER ");
	printf("\t NATIONALITY ");
	printf("\t  EMAIL ");
	printf("\t\t   PERIOD ");
	printf("\t    ARRIVALDATE \n");

	for (i = 0; i < 150; i++)
		printf("-");
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		printf("\n%s  %s \t\t    %s\t\t  %s \t %s  \t  %s\t    %s\t\t      %s\n", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);
	}
	printf("\n");
	for (i = 0; i < 150; i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f, *t;
	int i = 1;
	char roomnumber[20];
	if ((t = fopen("temp.txt", "w")) == NULL)
		exit(0);
	if ((f = fopen("add.txt", "r")) == NULL)
		exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s", roomnumber);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.roomnumber, roomnumber) == 0)
		{
			i = 0;
			continue;
		}
		else
			fwrite(&s, sizeof(s), 1, t);
	}
	if (i == 1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
		// remove("E:/file.txt");
		// rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt", "add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
	system("cls");
	FILE *f;
	char roomnumber[20];
	int flag = 1;
	f = fopen("add.txt", "r+");
	if (f == 0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.roomnumber, roomnumber) == 0)
		{
			flag = 0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number :\t%s", s.roomnumber);
			printf("\nName        :\t%s", s.name);
			printf("\nAddress     :\t%s", s.address);
			printf("\nPhone number:\t%s", s.phonenumber);
			printf("\nNationality :\t%s", s.nationality);
			printf("\nEmail       :\t%s", s.email);
			printf("\nPeriod      :\t%s", s.period);
			printf("\nArrival date:\t%s", s.arrivaldate);
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k = 1;
	char roomnumber[20];
	long int size = sizeof(s);
	if ((f = fopen("add.txt", "r+")) == NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]", roomnumber);
	fflush(stdin);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.roomnumber, roomnumber) == 0)
		{
			k = 0;
			printf("\nEnter Room Number     :");
			gets(s.roomnumber);
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s", &s.name);
			printf("\nEnter Address        :");
			scanf("%s", &s.address);
			printf("\nEnter Phone number :");
			scanf("%f", &s.phonenumber);
			printf("\nEnter Nationality :");
			scanf("%s", &s.nationality);
			printf("\nEnter Email :");
			scanf("%s", &s.email);
			printf("\nEnter Period :");
			scanf("%s", &s.period);
			printf("\nEnter Arrival date :");
			scanf("%s", &s.arrivaldate);
			fseek(f, size, SEEK_CUR); // to go to desired position infile
			fwrite(&s, sizeof(s), 1, f);
			break;
		}
	}
	if (k == 1)
	{
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}
	else
	{
		fclose(f);
		printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
		getch();
	}
}
