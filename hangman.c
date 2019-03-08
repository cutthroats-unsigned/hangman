/*
HANGMAN
DESIGNED AND DEVELOPED BY: DAVID BARKO


WAYS TO PLAY: 
	1) AI
 		a) AI GUESSING
		b) PLAYER GUESSING
	2) PLAYER vs PLAYER

DESCRIPTION: THIS PROGRAM UTILIZES LINKNED LISTS AND BINARY SEARCH TREES TO ACHIVE FUN AND SIMPLE GAMEPLAY OF THE OLD 
CLASSIC GAME HANGMAN. ALLOWS FOR 1-2 PLAYER GAMEPLAY.
*/

#include "headers.h"

int main(void)//BEGIN
{
//------------declarations---------------------------------1-----
struct bank phrase;
phrase.strike=0;
int wsc=0;
int seperate=0;
int badput;
int wlen, llen, letinphrase=0;
int flag=1;
char used[27]={0};
struct ll *list = init();//this is where the characters will be held it is a linked list which will be initialized at first
struct ll *temp;
int modeq, lagflag;//lagflag is the game mode
char mode[10]={0};
int wordcheck;
system("clear");
printf("\n ###################################");
printf("\n ##########    HANGMAN    ##########");
printf("\n ###################################");
printf("\n			 @@@@@@@@@@@@@@@@@@@@@");
printf("\n			 @    DAVID BARKO    @");
printf("\n			 @@@@@@@@@@@@@@@@@@@@@");
printf("\n\n");

printf("\n					CHOOSE GAME MODE:		");
printf("\n");
printf("\n PLEASE ENTER THE NUMBER CORRESPONDING TO THE GAME MODE THAT YOU WANT TO PLAY");
printf("\n NOTE: DO NOT ENTER ANY SPACES BEFORE THE INPUT AND JUST ENTER THE NUMBER FOLLOWED BY THE 'ENTER' KEY");
printf("\n");
printf("\n	1) PLAY AGAINST AI");
printf("\n	2) PLAY PLAYER VS PLAYER");
printf("\n");
printf(">");
fflush(stdout);
fgets(mode,10,stdin);
printf("Loading...\n");
sleep(1);
sscanf(mode,"%d",&modeq);
//---------------------------------------------------------end 1-------

//--------------------------user input for game mode-----------2--------
	if(mode[0]=='1')
	{
	 printf("AI GAMEPLAY STARTING\n");
	 lagflag = 1;
	 fflush(stdin);
	}
	if(mode[0]=='2')
	{
	 printf("PvP GAMEPLAY STARTING\n");
	 lagflag = 2;
	 fflush(stdin);
	}
	if(isspace(mode[0]))
	{
	 printf("ERROR: NO SPACES JUST 1 OR 2\n");
	 printf(" > ");
	//mode=getchar();
	fflush(stdin);
        fgets(mode,10,stdin);

                if(mode[0]=='1')
		{
                 printf("AI GAMEPLAY STARTING\n");
                 lagflag = 1;
                }
                if(mode[0]=='2')
                {
                 printf("PvP GAMEPLAY STARTING\n");
                 lagflag = 2;
                }
                else if(!(isdigit(mode[0])))
                {
                 printf("...\n");
                 sleep(2);
                 printf("...\n");
                 sleep(2);
                 printf("ERROR: PROPER INPUTS NOT DETECTED... COME AGAIN AFTER YOU LEARN HOW TO FOLLOW DIRECTIONS\n\n");
                 return 0;
                }
	}
	else if(!isdigit(mode[0]))
	{
	 printf("ERROR: ONLY ENTER THE NUMBER 1 OR 2\n");
	 printf(" > ");
	// mode = getchar();
	 fflush(stdin);
	 fgets(mode,10,stdin);

		if(isdigit(mode[0]) && mode[0]=='1')
        	{
        	 printf("AI GAMEPLAY STARTING\n");
		 lagflag = 1;
        	}
        	if(isdigit(mode[0]) && mode[0]=='2')
        	{
         	 printf("PvP GAMEPLAY STARTING\n");
        	 lagflag = 2;
		}
		else if(!isdigit(mode[0]))
		{
 		 printf("...\n");
		 sleep(2);
		 printf("...\n");
		 sleep(2);
		 printf("ERROR: PROPER INPUTS NOT DETECTED... COME AGAIN AFTER YOU LEARN HOW TO FOLLOW DIRECTIONS\n\n");
		 return 0;
		}
//--------------------------------------------------------------end 2----------------
}

//////////////////////////////////////////////////////////////////////////////////////
//Goal is for one player to input the a word or phrase and the other player will guess
//the word
//####################################################################################
// Game Player vs player
	
//=====================start of PvP gameplay============================================================
	if(lagflag==2)
	{
//-----------------------------input & check-----------------------------------3---------------------------
	 system("clear");
	 printf("\nSince you have chosen to play against another player let the word picker pick their word\n");
	 printf("your word(s) can only be in letters. No numbers and no other characters. the word(s) cant be bigger than 1000 characters total.\n\n");
	 printf("Please input your word that the other person will have to guess:\n");
	 printf(">");
	 fflush(stdin);
	 fflush(stdout);
	 fgets(phrase.word,1000,stdin);
	 int j;
for (int i = 0; i < strlen(phrase.word);i++)
{
 phrase.word[i] = tolower(phrase.word[i]);
    	if((phrase.word[i] >= 'a' && phrase.word[i]<='z')||(phrase.word[i]>='A' && phrase.word[i]<='Z')||(phrase.word[i]=='\0')||(phrase.word[i]==' ')||(phrase.word[i]=='\n'))
        {
  		if (i==0 && (phrase.word[i]=='\n' || phrase.word[i]==EOF))
	 	{
		 printf("ERROR: NO LETTERS DETECTED\n");
		 return 0;
	 	}
	}
	else
	{
 	 printf("ERROR: USE LETTERS ONLY\n");
	 return 0;
	}
}
//---------------------------------------------------------------------------end 3----------------------------


//-------Putting the word/s into the linked list & other mods to the Linked list----------4------
wlen=strlen(phrase.word);
wlen=wlen-1;//gets rid of the \n
putinlist(list, phrase.word);//puts in linked list
llen=orginlist(list, 0);//some initalizations + returns number of spaces
wlen=wlen-llen;//subtracts the number of spaces from the word count
printll(list);//prints the linked list
//-----------------------------------------------------------------------------------end 4-------

//#################################The Game part and calcultions ###################################
system("clear");
	 printf("okay, so now the player who chose the word for you just sits back and watches as you struggle to geuss the word\n");
	 printf("you have to try to guess the word with as fast as possible with less mistakes\n");
	 printf("on your sixth mistake you lose and the poor man dies!\n");
			
       while(flag==1)
	{
	system("clear");    
		if(wlen==0)
		{
		 drawboard(list,77);// if you won
		 printf("nice you found the word!\n");
		 return 0;
		}
		temp=list;
		drawboard(temp,phrase.strike);// draws the corresponding graphics
		printf("\n");
		  
//------------------------Printing of already used letters------------------5--------
	printf("The letters that you already guessed:\n\n");	  
          
		for(int q=0; q<strlen(used);q++)
		{	
		 printf("%c", used[q]);
		
                	if(q==3 || q==7 || q==11 || q==15 || q==19| q==23 || q==25 || q==26)
                	{
                 	 printf("\n");
                	}
			else if(used[q+1]!=0)
			{
	       		 printf(", ");
			}
		}
//----------------------------------------------------------------------end 5-------
 printf("\n"); //UI seperation 2x
 printf("\n");

//--------------------------------Input check of letter guess and status-----------6---- 

  		printf("enter the letter you think might be in the word or phrase\n");
		printf("The number of letters left for you to guess is: %i\n",wlen);
		printf("the number of strikes you have: %i/6\n\n",phrase.strike); 
		while(flag==1) // continues to go until correct input
		 {
		  badput=0;
		  printf("> ");
		  fgets(phrase.letter,27,stdin);
		 	if (isalpha(phrase.letter[0])==0)
		 	{
		 	 printf("please enter a valid single letter, make sure to not put any spaces in front\n");
			 flag = 1;
			}
			
			else
			{
				for(int r=0; r<strlen(used); r++)
				{	
                       	 		if(used[r]==phrase.letter[0])
                        		{
                         		 printf("please enter a letter which you have already not used\n");
                        		 flag=1;
					 badput=2;
                       			 r=strlen(used);
                        		}
				}
				if(badput!=2)
				{	
				 phrase.letter[0]=tolower(phrase.letter[0]);// makes input into lowercase
			 	 used[wsc]=phrase.letter[0]; 
			 	 flag=0;
			 	 wsc++;
				}
		 	}
		}
//--------------------------------------------------------------------------end 6--------        

//---------------------------Checks if letter has been entered/mods LL and changes status of graphics along with gameplay---------------7---------------------
letinphrase=0;
	while (temp->next!=NULL) //checks if entered letter is in word
	{
		if (phrase.letter[0] == temp->data)
		{			
		 letinphrase++;
		 temp->ftl=1;
		 temp->spce=0;
		 flag=1;
		}
	 temp=temp->next;
	}
		
wlen=wlen-letinphrase;
	if(letinphrase==0)
	{
	 phrase.strike++;
		if(phrase.strike==6)
		{
		 printf("you lost!\n");
		}
		else
		{
		flag=1;
		}
		}        
	}

	if(phrase.strike==6)
	{
	 drawboard(temp,phrase.strike);
	 printf("you LOST!!!\n");
	 printf("The word(s) was: %s\n",phrase.word);
	}
}//main lagflag for PvP
//-----------------------------------------------end 7---------------------------------------------------------------

//###################################END PvP calculations and gameplay#########################################
//==================================END OF PvP gameMode========================================================

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//Hardest part
//==========================================AI Mode============================================================
//There wil be two modes with AI mode
//The first is where the player guesses the word the AI gives And the second where AI guesses players word
if(lagflag==1)
{
system("clear");
printf("\nsorry this section is not ready yet please enter 2!\n");



}//main if loop bracket for AI Gamemode lagflag































return 0;
}
