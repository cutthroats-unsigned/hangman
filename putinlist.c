#include "headers.h"

void putinlist(struct ll *list, char word[1000])
{
struct ll *temp;
int i =0;
temp=list;
int len = strlen(word);

for(i; i<len; i++)
{
if(word[i]=='\n')
{
return;
}
struct ll *add = malloc(sizeof(struct ll));
add->next = temp->next;
temp->next= add;
temp->data=word[i];
temp->underscore='_';
temp=temp->next; 
}

}
