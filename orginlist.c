#include "headers.h"

int orginlist(struct ll *list, int num)
{
struct ll *temp=list;
struct ll *temp1=list;
int spaceamount=0;
	while(temp->next!=NULL)
	{
		if(isspace(temp->data))
		{
		 spaceamount++;
		 temp->spce=1;
		 temp->ftl=1;
		}

	 temp=temp->next;
	}

	if(isalpha(temp->data))
	{
	 temp1->ftl=num;
	 temp->spce=0;
	}
return spaceamount;
}
