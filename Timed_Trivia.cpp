//Author: Taniya S. Kulkarni


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>
/*Structures used */
struct Level{
			  char questions[200];
			  char option1[50];
			  char option2[50];
			  char option3[50];
			  char ans;
			};
Level l1[]={
			{"1.Which of these organs helps in maintaining the sense  of balance or equilibrium of our body ?","a.Nose","b.Ears","c.Lungs",'b'},
			{"2.Which of the following animals do not have external ears ?","a.Snake","b.Rat","c.Bat",'a'},
			{"3.Which of these national parks, reserved for tigers, is named after a river ?","a.Sunderbans","b.Indrawati","c.Kanha",'b'},
			{"4.Who was the Chairman of the Drafting committee of the Constituent of India ?","a.Motilal Nehru","b.Mahatma Gandhi","c.B. R. Ambedkar",'c'},
			{"5.Which of these sports events is named after a person ?","a.Marathon","b.Polo","c.Tennis",'a'}
		   };
Level l2[]={
			{"1.In the context of space exploration, what does the P in PSLV stand for ?","a.Planet","b.Polar","c.Power",'b'},
			{"2.In which city will you find Michelangelo famous 17-feet-tall marble sculpture \nDavid ?","a.Florence","b.Venice","c.Turin",'b'},
			{"3.Which of these ships was not part of Christopher Columbus's first voyage in 1492 ?","a.Nina","b.La Gorda","c.Pinta",'b'},
			{"4.With which religion would you associate the practice of Santhara fasting unto \ndeath ?","a.Jainism","b.Sikhism","c.Shintoism",'a'},
			{"5.In which edition of Olympics did women participate for the first time ?","a.Paris-1900","b.London-1908","c.Antwerp-1920",'a'},
			{"6.Which of these Vice President of India was earlier chief minister of his state ?","a.Zakir Hussain","b.V.V.Giri","c.Bhairon Singh Shekhawat",'c'},
			{"7.Which of the following are Cirrus, Stratus and Cumulus all types of ?","a.Clouds","b.Ocean Currents","c.Winds",'a'}
		   };
Level l3[]={
			{"1.In 2012, Joyce Banda was sworn in as which African country's first \nfemale president ?","a.Zambia","b.Malawi","c.Mozambique",'b'},
			{"2.Which Indian won his third super series in badminton in the year 2017, \nby winning the Denmark Open ?","a.B Sai Praneeth","b.Chetan Anand","c.Kidambi Srikanth",'c'},
			{"3.In which sport was Yani Tseng of Taiwan ranked world No. 1 for 109 consecutive \nweeks from 2011 to 2013 ?","a.Table Tennis","b.Golf","c.Badminton",'b'},
			{"4.Which of these politicians was an IAS officer before joining politics ?","a.Arvind Kejriwal","b.Piyush Goyal","c.Yashwanth Singh",'c'},
			{"5.Which of these is not an Ivy League College ?","a.Stanford University","b.University of Princeton","c.Cornell University",'a'},
			{"6.The Centre for Cellular and Molecular Biology is situated at: ","a.Hyderabad","b.Bengaluru","c.Mumbai",'a'},
			{"7.Which of these inventions is the most recent and came to be adopted in \nthe start of the 21st Century ?","a.Internet","b.Bluetooth","c.Blu-ray",'b'},
			{"8.Who was Henry VIII's wife at the time of his death ?","a.Catherine Parr","b.Anne Boleyn","c.Catherine of Aragon",'a'},
			{"9.First human heart transplant operation conducted by Dr. Christiaan Barnard \non Louis Washkansky, was conducted in: ","a.1971","b.1954","c.1967",'c'},
			{"10.For the Olympics and World Tournaments, the dimensions of basketball court are: ","a.28m x 15m","b.27m x 16m","c.23m x 14m",'a'},
			{"11.Composed of two main islands and with its capital at Basseterre, which is the \nsmallest nation in the Americas(North and South) ?","a.The Bahamas","b.Turks and Caicos Islands","c.St Kitts and Nevis",'c'},
			{"12.Where is the 2024 olympics going to be held ?","a.Beijing","b.Paris","c.Los Angeles",'b'},
			{"13.What is England's largest landlocked county ?","a.Shropshire","b.Oxfordshire","c.Derbyshire",'a'},
			{"14.In AD828 the relics of St Mark were taken from which city to Venice and placed in \nthe new basilica?","a.Canterbury","b.Alexandria","c.Rome",'b'},
			{"15.Which manufacturer makes the car models Qashqai, Juke, and Note?","a.Nissan","b.Toyota","c.Subaru",'a'}
		   };

struct players{
				char name[30];
				int level;
				int score;
				int position;
				char pl_ans;
	       }genius[100];

/* Function prototype */
int players();
int levelcheck(int n);
int continue1();
void timer();


/* Main() */
int main()
{
  clrscr();
  int gd=DETECT,gm;
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"c:/tc/bgi");
  settextstyle(BOLD_FONT,HORIZ_DIR,5);
  outtextxy(5,5,"SMART OR NOT");
  cout<<"\n\n\n\n\n\n\n\n";
  setbkcolor(RED);
  setcolor(WHITE);
  int number_of_players=players(),flag,i,cont;
  char ch,ch1;
  for(int j=0;j<number_of_players;j++)
  {
   genius[j].score=0;
   cout<<"\nEnter Player's NAME: ";
   gets(genius[j].name);
   cout<<"\nRules: \n1. Give the correct answers."
       <<"\n2. Every right answer gives you 10 points \n3.You will get 20 SECONDS to enter your answer.If answer isn\'t entered you will be EXITED out of the game."<<endl;
   cout<<"\nSo how smart are you?\n CHOOSE YOUR LEVEL(1,2,3):\n";
   cin>>genius[j].level;
   switch(genius[j].level)
   {
	 case 1:      cout<<"\nLevel 1:\n";
				  for(i=0;i<5;i++)
				  {
					cout<<"---------------------------------------------------------------------\n";
					cout<<"\n"<<l1[i].questions<<endl;
					cout<<"\t\t"<<l1[i].option1<<endl;
					cout<<"\t\t"<<l1[i].option2<<endl;
					cout<<"\t\t"<<l1[i].option3<<endl;
					cout<<"Enter answer: ";
					timer();
						cin>>genius[i].pl_ans;

					if(genius[i].pl_ans==l1[i].ans)
					{
						    cout<<"Correct answer!\n";
						    genius[j].score+=10;
					}
					else
					{
					       cout<<"\nWrong answer \n";
					       cout<<"\nCorrect answer: "<<l1[i].ans<<endl;
					}
				  }
				  cout<<"\nYour Score: "<<genius[j].score<<" out of 50";
				  cont=continue1();
				  if(cont!=0)
				  {
					  break;
				  }
				  flag=levelcheck(1);
				  if(flag!=0)
					{
						break;
					}

	 case 2:                	 genius[j].score=0;
				  cout<<"\nLevel 2: \n";
				  for(i=0;i<7;i++)
				  {
					cout<<"---------------------------------------------------------------------\n";
					cout<<"\n"<<l2[i].questions<<endl;
					cout<<"\t\t"<<l2[i].option1<<endl;
					cout<<"\t\t"<<l2[i].option2<<endl;
					cout<<"\t\t"<<l2[i].option3<<endl;
					cout<<"Enter answer: ";
					timer();
						cin>>genius[i].pl_ans;
					if(genius[i].pl_ans==l2[i].ans)
						{
							cout<<"\nCorrect answer!\n";
							genius[j].score+=10;
						}
					else
						{
							cout<<"\nWrong answer\n";
							cout<<"\nCorrect answer: "<<l2[i].ans<<endl;
						}
				  }
				  cout<<"\nYour Score: "<<genius[j].score<<" out of 70";
				  cont=continue1();
				  if(cont!=0)
				  {
					  break;
				  }
				  flag=levelcheck(2);
				  if(flag!=0)
				    {
						break;
					}

	 case 3:                  	genius[j].score=0;
				  cout<<"\nLevel 3:\n";
				  for( i=0;i<15;i++)
				  {
					cout<<"---------------------------------------------------------------------\n";
					cout<<"\n"<<l3[i].questions<<endl;
					cout<<"\t\t"<<l3[i].option1<<endl;
					cout<<"\t\t"<<l3[i].option2<<endl;
					cout<<"\t\t"<<l3[i].option3<<endl;
					cout<<"Enter answer: ";
					timer();
						cin>>genius[i].pl_ans;

					if(genius[i].pl_ans==l3[i].ans)
						{
							cout<<"\nCorrect answer!\n";
							genius[j].score+=10;
						}
					else
						{
							cout<<"\nWrong answer\n";
							cout<<"\nCorrect answer: "<<l3[i].ans<<endl;
						}
				  }
				  cout<<"\nYour Total Score: "<<genius[j].score<<" out of 150";
				  cout<<"\t\t\t GAME OVER";
				  break;

	 default:	  cout<<"\nChoose a valid level!";
	}

 }
getch();
return 0;
}

/*Defining of Functions */
int players()
{
	int no_of_players;
	cout<<"Enter number of player:";
	cin>>no_of_players;
	return no_of_players;
}
int levelcheck(int n)
{
	if(n==1)
	{  int x;
	   cout<<"\nGREAT! You have crossed this level. Let us test your vocabulary now.";
	   cout<<"\nWhat is the longest word you can you make from this word"
	       <<"\n(enter the NUMBER of letters in word):"<<endl;
	   cout<<"JNMWUFBEL"<<endl;
	   cin>>x;
	   if (x==6)
		{
			cout<<"\nCONGRATS! You have guessed the max length possible.\nYou can progress into the NEXT LEVEL now"<<endl;
			return 0;
		}

	   else
		{
			cout<<"\nYou did not get it right again."<<endl;
			return 1;
		}
	}

    else if(n==2)
	{
		char x[100];
		cout<<"\nGREAT you have crossed this level.";
		cout<<"\nUNSCRAMBLE the word (Enter the word):"<<endl;
		cout<<"\nJENRVTEUAE"<<endl;
		gets(x);
		if((strcmpi(x,"rejuvenate"))==0)
			{
				cout<<"\nCONGRATS! You have guessed the word. You can progress into the NEXT LEVEL now"<<endl;
				return 0;
			}

		else
			{
				cout<<"\nGAME OVER";
				return -1;
			}
    }

return 0;
}

int continue1()
{
	char ch;
	cout<<"\nDo you wish to continue(y/n)?:";
	cin>>ch;
	if(ch=='y'||ch=='Y')
		return 0;
	else
		return 1;
}
void timer()
{       int val=0;
	for(long int i=0;i<=9000000;i++)
	{
		if(kbhit())
		{
			val=1;
			break;
		}
	}
	if(val==0)
	 {
		 cout<<"Answer not entered. \n                                    \t GAME OVER!  ";
		 sleep(3);
		 exit(0);
		 getch();
	 }

}
