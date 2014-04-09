#include <stdio.h>
#include "observer.h"

void send_message();

int main()
{
	sinet_observable_t data;
	data.object = "data";
	data.notify = send_message;

	sinet_observable_t data_2;
	data_2.object = "data_2";
	data_2.notify = send_message;

	int size;

	new_list_observer();
	new_list_observable();
	insert_observable(data);
	insert_observable(data_2);
	size = size_observable();

	printf("\n%d\n", size);

	sinet_notify_objects();

	return 0;
}

void send_message(void *data) {
	printf("\nola\n");
}