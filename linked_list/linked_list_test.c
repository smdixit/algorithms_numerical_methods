#include <stdio.h>
#include "linked_list.h"

static LIST_T l_list_1;
static LISTELE_T *item_1[5];
static int temp[MAX_LIST_SIZE];

void destroy(void *data);
static int destroyCall_cnt;
static int result = 0;


int main(void)
{
	if(result == 0)
		printf("All tests of singly linked list passed.\n");
	else
		printf("Singly linked list test number: %d failed.\n", result);

	return 0;
}

void test_n(void)
{
	void *data;
	int i;
	LIST_T *list_1 = &l_list_1;

	for(i=0; i<MAX_LIST_SIZE; i++)
		temp[i] = i+1;

	init_list(list_1, destroy);

	list_ins_next(list_1, item_1[0], (void *)&temp);
	list_ins_next(list_1, item_1[1], (void *)&temp);
	list_ins_next(list_1, item_1[2], (void *)&temp);
	list_ins_next(list_1, item_1[3], (void *)&temp);
	list_ins_next(list_1, item_1[4], (void *)&temp);

	list_del_next(list_1, item_1[0], &data);
	list_del_next(list_1, NULL, &data);
}

void destroy(void *data)
{
	destroyCall_cnt++;
}
