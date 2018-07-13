/*****************mystring.h*************************
 * 	typedef string
 * 	2018.06.30
 * 	by flyk
 ****************************************************/

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

typedef struct node {
	char* data;
	char* next;
	char (*p)();
	int(*getLength)();
	struct node(*ass)(const struct node p);
	struct node(*add)(const struct node p);
	
}	


#endif
