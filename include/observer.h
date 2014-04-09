#ifndef OBSERVER_H
#define OBSERVER_H

	typedef struct {
		void *object;
		void (*notify)(void *data);
	} sinet_observable_t;

	typedef struct {
		void * observer_collection;
	} sinet_observer_t;

	//void sinet_register_object(sinet_observer_t observer, void *object); deprecated
	//void sinet_notify_objects(sinet_observer_t observer); deprecated
	void new_list_observer();
	//void sinet_register_object(); insert_observable(sinet_observable_t data)
	void sinet_notify_objects();

	typedef struct node { //HUB, SWITCH
		sinet_observable_t data;
		struct node * next;
	} list_observable_t;

	void new_list_observable();
	void insert_observable(sinet_observable_t data);
	int size_observable();

	static list_observable_t * list_observable;
	static sinet_observer_t * list_observer;

#endif

