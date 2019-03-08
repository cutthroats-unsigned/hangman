#include "headers.h"

void printll(struct ll *list)
{
struct ll *temp;

temp=list;
while(temp->next!=NULL)
{
	if(temp->spce==0 && temp->ftl == 0)
	{
	printf("%c ",temp->underscore);
	}

	else if(temp->spce==0 && temp->ftl==1)
	{
	printf("%c ",temp->data);
	}
	else if(temp->spce==1 && temp->ftl == 1)
	{
	printf(" %c ",temp->data);
	}
	else
	{
	printf("sucks\n");
	}
temp=temp->next;
}
printf("\n");


}
