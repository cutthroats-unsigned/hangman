#include "headers.h"

struct ll *init()
{
struct ll *list;
list = malloc(sizeof(struct ll));// allocating memory for list;
list -> data = 'k';//random number
list -> next = NULL;
list -> spce = 0;
list -> underscore = '_';
return list;
}
