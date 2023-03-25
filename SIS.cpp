#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdio>
#include<windows.h>
#include<sstream>
using namespace std;

//global variables
ofstream fileo;
ifstream filei;
char ch;
string Usn,usn,psd,fname,ffname,bio,usern,pw,line,name,cntnum,address,id,qulify,sub,Class,gpa;
int tm,up;
int choice,CH=0,i;
//global functions:
void gotoxy(short x,short y)    // coordinate not defined, so to define 
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}	

	//animation functions:
		void animLoading()
		{
			char l[]={'L','O','A','D','I','N','G'};
			gotoxy(15,12);
			for(int i=0;i<7;i++)
			{
				cout<<l[i]<<'\t';
				Sleep(50);    //1000 means 1 sec so 0.05 sec
			}
			gotoxy(11,10);
			for (int i=0;i<60;i++){
				cout<<"!";
				gotoxy(i+11,10);						//Top Loading line
				cout.flush();						//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+11,14);						//Bottom Loading line
				cout<<"!";
				Sleep(50);
			}
			Sleep(1000);   //after one sec main page appears
			system("CLS");
		}
		
		void animDeleting()
		{
			char l[]={'D','E','L','E','T','I','N','G'};
			gotoxy(52,25);
			for(int i=0;i<8;i++)
			{
				cout<<l[i];
			}
			gotoxy(45,27);
			for (int i=0;i<20;i++){
				cout<<"!";
				gotoxy(i+45,23);						//Top Loading line
				cout.flush();						//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+45,27);						//Bottom Loading line
				cout<<"!";
				Sleep(15);
			}
			Sleep(1000);
			system("CLS");
		}
		
		void animSearching()
		{
			char l[]={'S','E','A','R','C','H','I','N','G'};
			gotoxy(52,25);
			for(int i=0;i<9;i++)
			{
				cout<<l[i];
			}
			gotoxy(45,27);
			for (int i=0;i<25;i++){
				cout<<"!";
				gotoxy(i+45,23);						//Top Loading line
				cout.flush();						//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+45,27);						//Bottom Loading line
				cout<<"!";
				Sleep(15);
			}
			Sleep(1000);
			system("CLS");
		}
		
		void animSucessfull()
		{
			char l[]={'S','U','C','E','S','S','F','U','L','L'};
			gotoxy(45,12);
			for(int i=0;i<10;i++)
			{
				cout<<l[i];
			}
			gotoxy(31,10);
			for (int i=0;i<40;i++){
				cout<<"!";
				gotoxy(i+31,10);						//Top Loading line
				cout.flush();						//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+31,14);						//Bottom Loading line
				cout<<"!";
				Sleep(1);
			}
			Sleep(100);
			system("CLS");
		}
		
		//saving
		void animSaving()
		{
			system("CLS");
			char l[]={'S','A','V','I','N','G'};
			gotoxy(45,12);
			for(int i=0;i<6;i++)
			{
				cout<<l[i];
			}
			gotoxy(31,10);
			for (int i=0;i<40;i++){
				cout<<"!";
				gotoxy(i+31,10);						//Top Loading line
				cout.flush();						//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+31,14);						//Bottom Loading line
				cout<<"!";
				Sleep(1);
			}
			Sleep(500);
			system("CLS");
		}
		
		void animDataNotFound()     //for searching when data is not found
		{
			char l[]={'N','O','T','F','O','U','N','D'};
			gotoxy(15,12);
			for(int i=0;i<8;i++)
			{
				cout<<l[i]<<'\t';
				Sleep(50);
			}
			gotoxy(11,10);
			for (int i=0;i<65;i++)
			{
				cout<<"!";
				gotoxy(i+11,10);    //Top Loading line
				cout.flush();	//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+11,14);						//Bottom Loading line
				cout<<"!";
				Sleep(50);
			}
			Sleep(1000);
		}
		
		void animDataFound()  //for searching when data is found
		{
			char l[]={'F','O','U','N','D'};
			gotoxy(15,12);
			for(int i=0;i<5;i++)
			{
				cout<<l[i]<<'\t';
				Sleep(50);
			}
			gotoxy(11,10);
			for (int i=0;i<45;i++){
				cout<<"!";
				gotoxy(i+11,10);	//Top Loading line
				cout.flush();		//Flush output buffer for delay()
				cout<<"!";
				gotoxy(i+11,14);						//Bottom Loading line
				cout<<"!";
				Sleep(50);
			}
			Sleep(1000);
		}
		
		//welcome msg
		void welcome()
		{
			
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>> Admin\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>> Teacher\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 3>> Student\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 4>> Exit\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
	class admin
	{
		public:
		void adminLogin()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminChoice()
		{
			system("CLS");     //Clears to open new page directly
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>ENTER DATA\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>SEARCH DATA\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 3>>UPDATE DATA\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 4>>DELETE DATA\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 5>>DISPLAY INFORMATION\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 6>>EXIT ADMIN\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminEnterDataChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---ENTERING DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>TEACHER\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>STUDENT\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
	
		void adminEnterDataTeacherLog()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t---ENTERING TEACHER'S DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminEnterDataStudentLog()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t---ENTERING STUDENT'S DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminEnterDataTeacherInfo()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t---ENTERING TEACHER'S DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t TEACHER ID:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t QUALIFACTION:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS ASSIGNED:\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminEnterDataStudentInfo()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t---ENTERING STUDENT'S DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ROLL NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminUpdateDataChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---UPDATING DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>TEACHER\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>STUDENT\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminUpdateTeacherChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---UPDATING TEACHER'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Teacher you want to update\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void adminUpdateDataTeacher()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---UPDATING TEACHER'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t TEACHER ID:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t QUALIFACTION:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS ASSIGNED:\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void adminUpdateStudentChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---UPDATING STUDENT'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Usename of Student you want to update\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		
		void adminUpdateDataStudent()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t---UPDATING STUDENT'S DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ROLL NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		
		void adminDeleteDataChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---DELETING DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>TEACHER\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>STUDENT\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminDeleteTeacher()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---DELETING TEACHER'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Teacher you want to delete\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void adminDeleteStudent()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---DELETING STUDENT'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Usename of Student you want to delete\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void adminSearchDataChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---SEARCHING DATA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>TEACHER\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>STUDENT\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminSearchTeacher()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---SEARCHING TEACHER'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Teacher you want to search\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void adminSearchStudent()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t   ---SEARCHING STUDENT'S DATA--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Student you want to search\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
			
		void adminDisplayChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t  ---DISPLAYING INFORMATION---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>TEACHER\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>STUDENT\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminDisplayTeacherChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING TEACHER'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Teacher you want to display\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}

		void adminDisplayTeacher()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING TEACHER'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t TEACHER ID:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t QUALIFACTION:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS ASSIGNED:\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminDisplayStudentChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t  ---DISPLAYING INFORMATION---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>INFORMATION\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>GPA        \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void adminDisplayStudentRollChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING STUDENT'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Student you want to display\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void adminDisplayStudent()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---A D M I N--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING STUDENT'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ROLL NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}	
	}adm; //class admin ending

	//teacher
	class teacher
	{
		public:
		void teacherChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>ENTER GPA  \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>UPDATE GPA  \t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 3>>DELETE GPA  \t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 4>>DISPLAY INFORMATION\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 5>>EXIT TEACHER\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherLogin()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherEnterMarksChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t       ---ENTERING GPA---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Student you want to enter GPA\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherEnterGPA()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---ENTERING GPA---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t      Enter GPA of Student you want to enter\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherUpdateMarksChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t       ---UPDATING GPA---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t    Enter Username of Student you want to update GPA\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherUpdateMarks()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---UPDATING GPA---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t      Enter GPA of Student you want to update\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherDeleteMarksChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t      ---DELETING MARKS---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t      Enter username of Student you want to delete\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherDisplayInformationChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t--- T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t  ---DISPLAYING INFORMATION---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>TEACHER\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>STUDENT\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherDisplayTeacherInformation()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING TEACHER'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t TEACHER ID:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t QUALIFACTION:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS ASSIGNED:\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherDisplayStudentChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---S T U D E N T--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t  ---DISPLAYING INFORMATION---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>INFORMATION\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>GPA        \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherDisplayStudentInformationChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING STUDENT'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Student you want to display information\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";	
		}
		
		void teacherDisplayMarksChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---T E A C H E R--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t       ---DISPLAYING GPA---\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\tEnter Username of Student you want to display GPA\t\t*";
			cout<<"\n\t\t*\t\t\t\t    -> \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void teacherDisplayStudentInformation()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---S T U D E N T--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING STUDENT'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ROLL NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
	}teach; //teacher class ending

	//student 
	class student
	{			
		public:
		void studentLogin()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---S T U D E N T--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void studentChoice()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---S T U D E N T--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 1>>DISPLAY INFORMATION\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 2>>DISPLAY GPA        \t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t 3>>EXIT STUDENT\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Enter Choice\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void studentDisplayInformation()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---S T U D E N T--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING STUDENT'S INFORMATION--- \t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t NAME:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ROLL NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CONTACT NO:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t ADDRESS:\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CLASS:\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}

		void displayGPA()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---S T U D E N T--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t      ---DISPLAYING STUDENT'S GPA--- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t Your GPA is: \t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
	}stu;  //class student ending
	
	void CreateAdmin()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t    ---ENTER ADMIN DETAILS  --- \t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}

	void DataAlreadyExist()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME ALREADY EXIST\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t CREATE NEW USERNAME: \t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PASSWORD:        \t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void InvalidLogin()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t USERNAME OR PASSWORD IS NOT CORRECT \t\t\t*";
			cout<<"\n\t\t*\t\t\t PLEASE TRY AGAIN \t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
		}
		
		void Registration()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t YOU ARE NOT REGISTERED\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t PLEASE REGISTER         \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
			Sleep(1000);
		}
		
		
	void NotAvailable()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t      DATA NOT AVAILABLE   \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
			Sleep(1000);
		}
		
		void AlreadyExists()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t    GPA Already EXIST\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
			Sleep(1000);
		}
		
		void gpaNotExist()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t        GPA NOT EXIST\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
			Sleep(1000);
		}
		
		
		void NotExist()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t            NOT EXIST\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
			Sleep(1000);
		}
		
		void LimitExceed()
		{
			cout<<"\n\n\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t    STUDENT INFORMATION SYSTEM \t\t\t*\t*";
			cout<<"\n\t\t*\t*\t\t\t\t\t\t\t\t*\t*";
			cout<<"\n\t\t*\t*****************************************************************\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t---  E R R O R  --- \t\t\t\t*";
			cout<<"\n\t\t*\t\t\t*********************************\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t          LIMIT EXCEED\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t*\t\t\t\t\t\t\t\t\t\t*";
			cout<<"\n\t\t";
			for(int i=0;i<81;i++)
			{
				cout<<"*";
			}
			cout<<"\n";
			Sleep(1000);
		}

//valid password
void password()
{
	ch=getch();
	while(ch!=13)
	{
		if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')||(ch>=33 && ch<=39)||(ch>=63 && ch<=64)||(ch==45)) 
		{
			cout<<"*";
			psd.push_back(ch);       	
		}
		if (ch=='\b') 
		{
			string::iterator p = psd.end();
        	p--;
	        string::iterator it = psd.erase(p);
			cout << "\b \b"; //to delete wrong character that user input
		}
		ch=getch();
	}
}

//searching username
void searchUsn(string str)
{
    string dir;
    ifstream file;
    switch(choice)
    {
    	case 1:
    		dir = str+"teach.txt";
    	break;
		
		case 2:
			dir = str+"std.txt";
		break;
	}
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        system("CLS");
		animDataNotFound();
		//file.close();
		return;
    }
    else
    {
        system("CLS");
		animDataFound();
		file.close();
	}
}

//valid username
void valid(string str)
{
    string dir,user;
    ifstream file;
    switch(choice)
    {
    	case 1:
    		dir = str+"teach.txt";
    		user = str + "std.txt";
    	break;
		
		case 2:
			dir = str+"std.txt";
			user = str + "teach.txt";
		break;
	}
    file.open(user.c_str());
    if(!file.is_open() && file.fail())
    {
    	file.open(dir.c_str());
    	if(!file.is_open()&& file.fail())
    	{
    		return;
		}
		else
		{
			goto bot;
		}
    	//file.close();
        return;
    }
    else
    {
    	bot:
        tm++;
        if(tm==3)
        {
			system("CLS");
			DataAlreadyExist();
			gotoxy(62,18);
			cin>>usn;
            return;
        }
        system("CLS");
        DataAlreadyExist();
        gotoxy(62,18);
        cin>>usn;
        valid(usn);
    }
}
//delete record
void del(string str)
{
	string dir,tech;
    ifstream file;
    tech = str+"teach.txt";
    switch(choice)
    {
    	case 1:
    		dir = str+"teach.txt";
    	break;
		case 2:
			dir = str+"std.txt";
		break;
	}
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
		system("CLS");
		animDataNotFound();//needs to be changed to record not found!!
		system("CLS");
		return;
    }
    else
    {
        const char* ffname=dir.c_str();
		file.close();
        animDeleting();
        remove(ffname);
        if(dir==tech)
        {
        	remove("teachinfo.txt");
		}
		animSucessfull();
   	}
}

void getgpa()
{
	int n=0;
	char c;
	ch=getch();
	while(ch!=27)
	{
		if((ch>='0'&&ch<='9')||ch=='.')
		{
			if(n==0&&ch<='4')
			{
				cout<<ch;
				gpa.push_back(ch);
				n++;
				c=ch;
			}
			else if(n==1&&ch==46)
			{
				cout<<ch;
				gpa.push_back(ch);
				n++;
			}
			else if((n==2&&c=='4')&&ch=='0')
		 	{
				cout<<ch;
				gpa.push_back(ch);
				n++;
			}
			else if(n==2&&c<'4')
			{
				cout<<ch;
				gpa.push_back(ch);
				n++;
			}
		}
		if(n==3)
		{
			break;
		}
		ch=getch();
	}
	
}

void getclass()
{
	ch=getch();
	while(ch!=27)
	{
		if(ch=='B')
		{
			cout<<ch;
			Class.push_back(ch);
			break;
		}
		ch=getch();		
	}
}

void getCntnum()
{
	int n=0;
	ch=getch();
	while(ch!=27)
	{
		if(ch>='0'&&ch<='9')
		{
			n++;
			cout<<ch;
			cntnum.push_back(ch);
		}
		if(n==10)
		{
			break;
		}
		ch=getch();		
	}
}

void getid()
{
	switch(choice)
	{
		case 1:
			ch=getch();
			while(ch!=27)
			{
				if(ch>='1'&&ch<='9')
				{
					char c='0';
					id.push_back(c);
					cout<<ch;
					id.push_back(ch);
					break;
				}
				ch=getch();		
			}
		break;
		case 2:
			int n=0;
			char c;
			ch=getch();
			while(ch!=27)
			{
				if(ch>='0'&&ch<='9')
				{
					if(n==0&&ch<='4')
					{
						cout<<ch;
						id.push_back(ch);
						n++;
						c=ch;
					}
					else if(n==1&&ch<='8')
					{
						cout<<ch;
						id.push_back(ch);
						n++;
					}
					else if(n==1&&c<'4')
					{
						cout<<ch;
						id.push_back(ch);
						n++;
					}
				}
				if(n==2)
				{
					break;
				}
				ch=getch();
			}
		break;				
	}
}
	void enteach()
	{
		cout.flush();
		gotoxy(47,18);
		cin.ignore();
		getline(cin,name);//name
		gotoxy(53,19);
		getCntnum(); //contact no
		gotoxy(50,20);
		getline(cin,address); //address
		gotoxy(53,21);
		getid(); //teacher id
		gotoxy(55,22);
		getline(cin,qulify); //qualification
		gotoxy(57,23);
		getclass();
		//getline(cin,Class); //class
		system("CLS");
	}
	
	void getteachinfo()
	{
		ifstream file;
		//fname = usn + "teach.txt";
		getline(file,usern);
		getline(file,pw);
		getline(file,name);
		getline(file,cntnum);
		getline(file,address);
		getline(file,id);
		getline(file,qulify);
		getline(file,Class);
	}
	
	void displayteach(string usn)
	{
		ifstream file;
		fname = usn + "teach.txt";
	    file.open(fname.c_str());
	    if(!file.is_open() && file.fail())
	    {
	        //file.close();
			system("CLS");
			animDataNotFound();//needs to be changed to record not found!!
			return;
	    }
	    else
	    {
	    	system("CLS");
	    	adm.adminDisplayTeacher();
	    	//getteachinfo();
			getline(file,usern);
			getline(file,pw);
			getline(file,name);
			getline(file,cntnum);
			getline(file,address);
			getline(file,id);
			getline(file,qulify);
			getline(file,Class);
			gotoxy(47,18);
			cout<<name;//name
			gotoxy(53,19);
			cout<<cntnum; //contact no
			gotoxy(50,20);
			cout<<address; //address
			gotoxy(53,21);
			cout<<id; //teacher id
			gotoxy(55,22);
			cout<<qulify; //qualification
			gotoxy(57,23);
			cout<<Class; //class assigned to;
			getch();
	       	//file.close();
		}				
	}
	
	void wrteach()
	{
		fname = "teachinfo.txt";
		filei.open(fname.c_str());
	    if(!filei.is_open() && filei.fail())
	    {
	    	fileo.open(fname.c_str());
	    	fileo<<name<<" teacher"<<endl;
	    	fileo.close();
	        fname = usn+ "teach.txt";
			fileo.open(fname.c_str());//as pointer **uniquely**
			fileo<<usn<<endl<<psd<<endl<<name<<endl<<cntnum<<endl<<address<<endl<<id<<endl<<qulify<<endl<<Class<<endl;//writing in file
			fileo.close();
			system("CLS");
			animSaving();
        	animSucessfull();	
			return;
	    }
	    else
	    {
	    	filei.close();
			LimitExceed();
		}		
	}
	
	void upteach()
	{
		fname=usn + "teach.txt";
		filei.open(fname.c_str());
        getline(filei,usern);
        getline(filei,pw);
        filei.close();
        fileo.open(fname.c_str());
		fileo<<usern<<endl<<pw<<endl<<name<<endl<<cntnum<<endl<<address<<endl<<id<<endl<<qulify<<endl<<Class<<endl;//writing in file
		fileo.close();
		system("CLS");
		animSaving();
        animSucessfull();
	}
	void enstud()
	{
		cin.ignore();
		gotoxy(47,18);
		getline(cin,name);//name
		gotoxy(50,19);
		getid(); //roll
		gotoxy(53,20);
		getCntnum(); //contact
		gotoxy(50,21);
		getline(cin,address); //address
		gotoxy(48,22);
		getclass();//class
		system("CLS");
	}

	void displaystud(string usn)
	{
		
		ifstream file;
	    fname = usn + "std.txt";
	    file.open(fname.c_str());
	    if(!file.is_open() && file.fail())
	    {
	        //file.close();
			system("CLS");
			animDataNotFound();//needs to be changed to record not found!!
			system("CLS");
			return;
	    }
	    else
	    {
	    	system("CLS");
	   		adm.adminDisplayStudent();
	   		getline(file,usern);
			getline(file,pw);
			getline(file,name);
			getline(file,id);
			getline(file,cntnum);
			getline(file,address);
			getline(file,Class);
			gotoxy(47,18);
			cout<<name;//name
			gotoxy(50,19);
			cout<<id; //roll
			gotoxy(53,20);
			cout<<cntnum; //contact
			gotoxy(50,21);
			cout<<address; //address
			gotoxy(48,22);
			cout<<Class; //class
			getch();
			system("CLS");
		}
	}

	void wrstud()
	{
		fname = usn+"std.txt";
		fileo.open(fname.c_str());
        fileo<<usn<<endl<<psd<<endl<<name<<endl<<id<<endl<<cntnum<<endl<<address<<endl<<Class<<endl;//writing in file
        fileo.close();
		psd="\0";
		system("CLS");
		animSaving();
        animSucessfull();	
	}

	void upstud()
	{
		fname=usn + "std.txt";
		filei.open(fname.c_str());
        getline(filei,usern);
        getline(filei,pw);
        filei.close();
        fileo.open(fname.c_str());
        fileo<<usern<<endl<<pw<<endl<<name<<endl<<id<<endl<<cntnum<<endl<<address<<endl<<Class<<endl;//writing in file
        fileo.close();
	}


//update
void update(string str)
{
    string dir,user;
    ifstream file;
    switch(choice)
    {
    	case 1:
    		dir = str+"teach.txt";
    	break;
		
		case 2:
			dir = str+"std.txt";
		break;
	}
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
    	system("CLS");
		NotExist();
		system("CLS");
		return;
    }
    else
    {
        system("CLS");
        switch(choice)
        {
        	case 1:
        		adm.adminUpdateDataTeacher();
        		enteach();
        		upteach();
			break;
			
			case 2:
				adm.adminUpdateDataStudent();
				enstud();
				upstud();
			break;
		}
	}
}

void enterlog()
{
	gotoxy(50,18);
	cin.ignore();
 	cin>>usn;
    tm=0;
    valid(usn);
    if(tm>=3)
    {
        enterlog();
    }
    gotoxy(50,19);
    password();
}

void reset()
{
	
	usern="\0";
	//usn="\0";
	psd="\0";
	//pw="\0";
	name="\0";
	cntnum="\0";
	address="\0";
	id="\0";
	Class="\0";
	gpa="\0";	
}

int main()
{
	int exit = 0;
	animLoading();
    while(exit==0)
    {
        TOP:
        system("CLS");
		welcome();
        gotoxy(55,26);
		cin>>choice;
		system("CLS");
        if(choice==1)
        {
        	fname="admlogin.txt";
        	filei.open(fname.c_str());//as pointer **uniquely/while using string as file name we must use c_str() before passing it to this constructor
            if(!filei.is_open() && filei.fail())//file is not open & gives fail error
            {
                Registration();
                system("CLS");
				CreateAdmin();
                gotoxy(50,17);
            	cin>>usn;
            	gotoxy(50,18);
				password();
                fileo.open(fname.c_str());
                fileo<<usn<<endl<<psd<<endl;
                reset();
                system("CLS");
                animSucessfull();
                fileo.close();
                usn="\0";
				psd="\0";
                continue;
            }
            else
			{
            	adm.adminLogin();
				gotoxy(50,17);
	            cin>>usn;
	            gotoxy(50,18);
				password();
	            getline(filei,usern);
				getline(filei,pw);//reads the (line)name from fname.txt file
				if(usn==usern && psd==pw)
	            {
	            	system("CLS");
                	animSucessfull();
	                usn="\0";
	                psd="\0";
					filei.close();
	                at:
					adm.adminChoice();			
					gotoxy(55,26);
					cin>>choice;
					system("CLS");
					switch(choice)
					{
						case 1:
							at1:
							adm.adminEnterDataChoice();
							gotoxy(55,26);
							cin>>choice;
							switch(choice)
							{
								case 1:
									system("CLS");
									adm.adminEnterDataTeacherLog();
									enterlog();
									system("CLS");
									adm.adminEnterDataTeacherInfo();
									enteach();
									wrteach();
					                reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at1;
								break;
								case 2:
									system("CLS");
									adm.adminEnterDataStudentLog();
									enterlog();
									system("CLS");
									adm.adminEnterDataStudentInfo();
									enstud();
									wrstud();
									reset();
									usn="\0";
									psd="\0";
					                goto at1;
								break;
								default:
									reset();
									usn="\0";
									psd="\0";
					                system("CLS");
					                goto at;
								break;	
							}
							goto at;
							system("CLS");
						break;
								
						case 2: //data search
							at2:
							adm.adminSearchDataChoice();
							gotoxy(55,26);
							cin>>choice;
							system("CLS");
							switch(choice)
							{
								case 1:
									adm.adminSearchTeacher();
									gotoxy(55,20);
									cin.ignore();
									cin>>usn;
									searchUsn(usn);
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at2;
								break;	
								case 2:
									adm.adminSearchStudent();
									gotoxy(55,20);
									cin.ignore();
									cin>>usn;
									searchUsn(usn);
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at2;
								break;
								default:
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at;
								break;
							}
							reset();
							usn="\0";
							psd="\0";
							system("CLS");
							goto at;
						break;	
							
						case 3: //data update
							at3:
							adm.adminUpdateDataChoice();
							gotoxy(55,26);
							cin>>choice;
							system("CLS");
							switch(choice)
							{
								case 1:
									adm.adminUpdateTeacherChoice();
									gotoxy(55,20);
									cin>>usn;
									update(usn);  
									reset();
					                usn="\0";
									psd="\0";
									goto at3;
								break;
								
								case 2:
									adm.adminUpdateStudentChoice();
									gotoxy(55,20);
									cin>>usn;
									update(usn);
									reset();
									usn="\0";
									psd="\0";
									goto at3;
								break;
								
								default:
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at;
	 							break;
							}
							system("CLS");	
							goto at;
						break;	
						
						case 4: //data delete
							at4:
							adm.adminDeleteDataChoice();
							gotoxy(55,26);
							cin>>choice;
							system("CLS");
							switch(choice)	
							{
								case 1:
									adm.adminDeleteTeacher();
									gotoxy(55,20);
									cin.ignore();
									cin>>usn;
									del(usn);
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at4;
								break;
								
								case 2:
									adm.adminDeleteStudent();
									gotoxy(55,20);
									cin.ignore();
									cin>>usn;
									del(usn);
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at4;
								break;
								
								default:
									reset();
					                usn="\0";
									psd="\0";
									system("CLS");
					                goto at;
					            break;
							}
							system("CLS");
							goto at;
						break;
						
						case 5: //data display
							at5:
							adm.adminDisplayChoice();
							gotoxy(55,26);
							cin>>choice;
							system("CLS");
							switch(choice)	
							{
								case 1:
									adm.adminDisplayTeacherChoice();
									gotoxy(55,20);
									cin.ignore();
									cin>>usn;
									displayteach(usn);
									reset();
						            usn="\0";
									psd="\0";
									system("CLS");
						            goto at5;
								break;
								case 2:
									adm.adminDisplayStudentRollChoice();
									gotoxy(55,20);
									cin.ignore();
									cin>>usn;
									displaystud(usn);
									reset();
						            usn="\0";
									psd="\0";
									system("CLS");
						            goto at5;
								break;
								default:
									reset();
									usn="\0";
									psd="\0";
						            system("CLS");
						            goto at;
						        break;
							}
							system("CLS");
							goto at;
						break;		
						
						default:
							reset();
					        usn="\0";
							psd="\0";
							system("CLS");
							goto TOP;
						break;				
					}
            	}
	            else
				{
	                system("CLS");
					InvalidLogin();
	        		getch();
	        		usn="\0";
	        		psd="\0";
	               // reset();
	            }
			}
        }
        else if(choice==2)
        {
			teach.teacherLogin();
	        gotoxy(50,17);
            cin.ignore();
            getline(cin,usn);
            gotoxy(50,18);
			password();
            fname=usn + "teach.txt";
			filei.open(fname.c_str());//as pointer uniquely///while using string as file name we must use c_str() before passing it to this constructor
            if(!filei.is_open() && filei.fail())///file is not open & gives fail error
            {
                system("CLS");
			    reset();
				usn="\0";
				psd="\0";	//cout<<"\nYou are not registered, please register before logging in.\n";//skeleton with delay
				Registration();
                system("CLS");
                continue;
            }
            getline(filei,usern);
			getline(filei,pw);///reads the (line)name from fname.txt file
			if(usn==usern && psd==pw)
            {
				Usn=usn;
				system("CLS");
            	animSucessfull();
				tc:
				filei.close();
            	reset();
            	teach.teacherChoice();
				gotoxy(55,26);
				cin>>choice;
				system("CLS");
				switch(choice)
				{
					
					case 1:
						teach.teacherEnterMarksChoice();
						gotoxy(55,20);
						cin>>usn;
						system("CLS");
						fname = usn+"std.txt";
						filei.open(fname.c_str());
						if(!filei.is_open() && filei.fail())///file is not open & gives fail error
			            {
			                system("CLS");
			                reset();
			                usn="\0";
							psd="\0";
							Registration();
			                continue;
			            }
						system("CLS");
			            getline(filei,usern);
						getline(filei,pw);
						getline(filei,name);
						getline(filei,id);
						getline(filei,cntnum);
						getline(filei,address);
						getline(filei,Class);
						getline(filei,gpa);
						filei.close();
						if(gpa=="\0")
						{
							teach.teacherEnterGPA();
							gotoxy(55,20);
							getgpa();
							fileo.open(fname.c_str());
							fileo<<usern<<endl<<pw<<endl<<name<<endl<<id<<endl<<cntnum<<endl<<address<<endl<<Class<<endl<<gpa<<endl;//writing in file
	        				fileo.close();
							reset();
							system("CLS");
							animSaving();
	                		animSucessfull();
	                		system("CLS");
						}
						else
						{
							system("CLS");
							AlreadyExists();
							getch();
							system("CLS");
						}
						goto tc;	
					break;
									
					case 2:
						teach.teacherUpdateMarksChoice();
						gotoxy(55,20);
						cin>>usn;
						system("CLS");
						fname = usn+"std.txt";
						filei.open(fname.c_str());
						if(!filei.is_open() && filei.fail())///file is not open & gives fail error
			            {
			                system("CLS");
			                reset();
							NotAvailable();
			                continue;
			            }
						system("CLS");
			            getline(filei,usern);
						getline(filei,pw);
						getline(filei,name);
						getline(filei,id);
						getline(filei,cntnum);
						getline(filei,address);
						getline(filei,Class);
						getline(filei,gpa);
						filei.close();
						if(gpa=="\0")
						{
							system("CLS");
							gpaNotExist();
							getch();
							system("CLS");	
						}
						else
						{
							gpa="\0";
							teach.teacherUpdateMarks();
							gotoxy(55,20);
							getgpa();
							fileo.open(fname.c_str());
							fileo<<usern<<endl<<pw<<endl<<name<<endl<<id<<endl<<cntnum<<endl<<address<<endl<<Class<<endl<<gpa<<endl;//writing in file
    	    				fileo.close();
							reset();	
							system("CLS");
							animSaving();
                			animSucessfull();
                			system("CLS");
						}
						goto tc;
					break;
					
					case 3:
						teach.teacherDeleteMarksChoice();
						gotoxy(55,20);
						cin>>usn;//roll no
						fname = usn+"std.txt";	
						filei.open(fname.c_str());
						if(!filei.is_open() && filei.fail())///file is not open & gives fail error
			            {
			                system("CLS");
							NotAvailable();
			            	reset();
							continue;
			            }
			            system("CLS");
			            getline(filei,usn);
						getline(filei,psd);
						getline(filei,name);
						getline(filei,id);
						getline(filei,cntnum);
						getline(filei,address);
						getline(filei,Class);
						getline(filei,gpa);
						filei.close();
						if(gpa!="\0")
						{
							animDeleting();
							animSucessfull();
							wrstud();
							system("CLS");
							reset();
						}
						else
						{
							system("CLS");
							gpaNotExist();
							getch();
							system("CLS");
						}
						goto tc;
					break;
					
					case 4: 
						tc4:
						teach.teacherDisplayInformationChoice();
						gotoxy(55,26);
						cin>>choice;
						system("CLS");
						switch(choice)
						{
							case 1:
								teach.teacherDisplayTeacherInformation();
								displayteach(Usn);
								system("CLS");
								goto tc4;
							break;
							
							case 2:
								top:
								teach.teacherDisplayStudentChoice();
								gotoxy(55,26);
								cin>>choice;
								system("CLS");
								switch(choice)
								{
									case 1:
										teach.teacherDisplayStudentInformationChoice();
										gotoxy(55,20);
							            cin.ignore();
							            getline(cin,usn);
										system("CLS");
										teach.teacherDisplayStudentInformation();
										displaystud(usn);
										usn="\0";
										psd="\0";
										goto top;
									break;
									
									case 2:
										teach.teacherDisplayMarksChoice();
							            cin.ignore();
							            gotoxy(55,20);
										getline(cin,usn);
										system("CLS");
										fname = usn+"std.txt";
										filei.open(fname.c_str());
										if(!filei.is_open() && filei.fail())///file is not open & gives fail error
							            {
							                reset();
											usn="\0";
											psd="\0";
											NotAvailable();
							                continue;
							            }
							            getline(filei,usern);
										getline(filei,pw);
										getline(filei,name);
										getline(filei,id);
										getline(filei,cntnum);
										getline(filei,address);
										getline(filei,Class);
										getline(filei,gpa);
										filei.close();
										system("CLS");
										if(gpa!="\0")
										{
											stu.displayGPA();
											gotoxy(55,18);
											cout<<gpa;
											getch();
											system("CLS");
										}
										else
										{
											system("CLS");
											gpaNotExist();
											getch();
											system("CLS");
										}
										usn="\0";
										psd="\0";
										goto top;
									break;
									
									default:
										reset();
										usn="\0";
										psd="\0";
										goto tc4;
									break;
								}
								reset();
								usn="\0";
								psd="\0";
								goto tc4;
								break;
							default: 
								reset();
								usn="\0";
								psd="\0";
								goto tc;
							break;
						}
						reset();
						usn="\0";
						psd="\0";
						goto tc;
					break;
					default:
						system("CLS");
						reset();
						usn="\0";
						psd="\0";
						goto TOP;
					break;
				}
			}
			else
			{
            	system("CLS");
				InvalidLogin();
				reset();
				usn="\0";
				psd="\0";
                getch();
            }
        }
        else if(choice==3)
        {
        	stu.studentLogin();
            gotoxy(50,17);
            cin.ignore();
            getline(cin,usn);
            gotoxy(50,18);
			password();
            fname=usn + "std.txt";
			const char* ffname=fname.c_str();
			filei.open(fname.c_str());//as pointer "uniquely"//while using string as file name we must use c_str() before passing it to this constructor
            if(!filei.is_open() && filei.fail())//file is not open & gives fail error
            {
                system("CLS");
				Registration();
				reset();
				usn="\0";
				psd="\0";
				continue;
            }
			getline(filei,usern);
			getline(filei,pw);
			getline(filei,name);
			getline(filei,id);
			getline(filei,cntnum);
			getline(filei,address);
			getline(filei,Class);
			getline(filei,gpa);
			filei.close();//reads the (line)name from fname.txt file
			if(usn==usern && psd==pw)
            {
            	
				system("CLS");
				animSucessfull();
				st:
				stu.studentChoice();
				gotoxy(55,26);
				cin>>choice;
				system("CLS");
				switch(choice)
				{
					case 1:
						stu.studentDisplayInformation();
						displaystud(usern);
						system("CLS");
						goto st;
					break;
					
					case 2:
						if(gpa!="\0")
						{
							stu.displayGPA();
							gotoxy(55,18);
							cout<<gpa;
							getch();
							system("CLS");
						}
						else
						{
							system("CLS");
							gpaNotExist();
							getch();
							system("CLS");
						}
						goto st;
					break;
					
					default:
						//reset();
						usn="\0";
						psd="\0";
						goto TOP;
					break;
				}		
            }
            else
			{
            	system("CLS");
				InvalidLogin();
        		getch();
        		reset();
				usn="\0";
				psd="\0";
            }
        }
        else if (choice==4)
        {
            exit=1;
        }
    }
    cout<<"\n----------------------------------------------Thank you for visiting:)----------------------------------------------------\n";
}


