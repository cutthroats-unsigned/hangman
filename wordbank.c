#include "headers.h"

char wordbank(char used[27], char letter[27])
{

char c[27]=used;
int j=0;
char b='+';
int len=strlen(c);
len=len-1;
	for(int i = 0; i<=len; i++)
	{
		if(c[i]==letter[0])
		{
		// c[len+1]=letter[0];
		 //j++; 
		 return b;
		}
	}
c[len+1]=letter[0];	
return c;











 
printf("\n");


printf("                                            ##########################            \n");
printf("                                            #%c %c %c %c %c %c %c    #            \n");
printf("                                            #%c %c %c %c %c %c %c    #            \n");
printf("                                            #%c %c %c %c %c %c %c    #            \n");
printf("                                            #%c %c %c %c %c %c %c    #            \n");
printf("                                            #                        #            \n");
printf("                                            ##########################            \n");

}
