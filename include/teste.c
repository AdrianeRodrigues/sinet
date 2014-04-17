#include <stdio.h>
#include "hub.h"

void send_message();

int main()
{
  int result = 0;
  sinet_host_t *host1;
  sinet_host_t *host2;
  
  host1 = sinet_new_host("192.168.0.1", 24, "aa:bb:cc:dd:ee:ff");
  host2 = sinet_new_host("192.168.0.2", 24, "11:22:33:44:55:66");
  sinet_create_device(HUB, 3);
  result = sinet_connect(host1);
  printf("\n%d\n", result);
  result = sinet_connect(host2);
  printf("\n%d\n", result);
  
  return 0;
}
/*
void send_message(void *data) {
  printf("\n%s\n",(char*) data);
	printf("\nola\n");
}*/
