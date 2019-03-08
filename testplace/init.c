#include "headers.h"

struct ll *init()
{
struct ll *list;
list = malloc(sizeof(struct ll));// allocating memory for list;
list -> data = " ";//random number
list -> next = NULL;
return list;
}
