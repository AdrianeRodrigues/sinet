#include "../include/observer.h"
#include <stdio.h>
#include <stdlib.h>

void new_list_observer()
{
	list_observer = NULL;
}

void sinet_register_object()
{
	if(list_observer != NULL) {
		sinet_observer_t * new = malloc(sizeof(sinet_observer_t));
		new->observer_collection = list_observable;
		list_observer = new;
	}
}

//void sinet_notify_objects(sinet_observer_t observer) deprecated
void sinet_notify_objects() //TODO
{
	list_observable_t * aux = list_observable;

	while(aux != NULL)
	{
		aux->data.notify(NULL);
		aux = aux->next;
	}
}

void new_list_observable()
{
	list_observable = NULL;
}

void insert_observable(sinet_observable_t data)
{
	if(list_observable == NULL)
	{
		list_observable_t * new = malloc(sizeof(sinet_observable_t));
		new->data = data;
		new->next = NULL;
		list_observable = new;
	}
	else
	{
		list_observable_t * atual = list_observable;
		while(atual->next != NULL)
			atual = atual->next;

		list_observable_t * new = malloc(sizeof(sinet_observable_t));
		new->data = data;
		new->next = NULL;
		atual->next = new;
	}
}

int size_observable()
{
	int i = 0;
	
	list_observable_t * aux = list_observable;

	while(aux != NULL)
	{
		++i;
		aux = aux->next;
	}
	return i;
}
