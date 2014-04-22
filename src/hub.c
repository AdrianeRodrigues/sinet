#include "../include/hub.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cria novo host
sinet_host_t *sinet_new_host(const char *ip, unsigned char mask, const char *mac){
  sinet_host_t * new = malloc(sizeof(sinet_host_t));
  new->ip = sinet_new_IP(ip);
  new->mask = mask;
  new->mac = sinet_new_MAC(mac);
  return new;
}

sinet_IP_t *sinet_new_IP(const char *ip){
  char* str;
  sinet_IP_t aux[4];
  char * saved;
  int i = 0;
  str =  malloc(sizeof(char) *(strlen(ip) + 1));
  strcpy(str, ip);
  
  while(i < 4){
    
    if(i == 0){
      aux[i] = atoi(strtok_r(str, ".", &saved));
      printf("passei %d %d!\n", i, aux[i]);
    }else{
      aux[i] = atoi(strtok_r(NULL, ".", &saved));
      printf("passei %d %d!\n", i, aux[i]);
    }
    i++;
  }
  return aux;
}

sinet_MAC_t *sinet_new_MAC(const char *mac){
  char* str;
  sinet_MAC_t aux[4];
  char * saved;
  int i = 0;
  str =  malloc(sizeof(char) *(strlen(mac) + 1));
  strcpy(str, mac);
  
  while(i < 4){
    
    if(i == 0){
      aux[i] = atoi(strtok_r(str, ".", &saved));
      printf("passei %d %d!\n", i, aux[i]);
    }else{
      aux[i] = atoi(strtok_r(NULL, ".", &saved));
      printf("passei %d %d!\n", i, aux[i]);
    }
    i++;
  }
  return aux;
}

//cria um device hub
void sinet_create_device(sinet_device_type_t device, unsigned char max_ports){
  sinet_device_t* new = malloc(sizeof(sinet_device_t));
  new->device = (void*) device;
  new->max_ports = max_ports;
  new->list = NULL;
  hub = new;
  free(new);
}

void sinet_set_max_ports(sinet_device_t *device, unsigned char max_ports) {
//void sinet_set_max_ports(unsigned char max_ports){
  hub->max_ports = max_ports;
}

int sinet_connect(sinet_host_t *host){
  
  if(hub->list == NULL){
    sinet_list_host* new = malloc(sizeof(sinet_list_host));
    new->host = host;
    new->next = NULL;
    hub->list = new;
    return 1;
  }else if(hub->list != NULL){
  
 //   if(sinet_nro_portas() <  hub->max_ports){
      sinet_list_host* aux = hub->list;
      
      while(aux->next != NULL)
        aux = aux->next;

      sinet_list_host* new = malloc(sizeof(sinet_list_host));
      new->host = host;
      new->next = NULL;
      aux->next = new;
      return 1;
 //   }
  }
  return 0;
}

void sinet_set_run(sinet_host_t *host, void (*run)(void)){
  host->run = run;
}

void sinet_set_gateway(sinet_host_t *host, sinet_IP_t gateway){
  host->gateway = gateway;
}

int sinet_nro_portas(){
  int i = 0;
  sinet_list_host* aux = hub->list;

  while(aux->next != NULL){
    aux = aux->next;
    i++;
  }
  return i;
}



