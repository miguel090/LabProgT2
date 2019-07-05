#include <stdlib.h>
#include <stdio.h>
#include "client.h"

Cliente set(int items, int entrada){
  Cliente c = (Cliente) malloc (sizeof(struct cliente));
  c->items=items;
  c->entrada=entrada;
  return c;
}

int getItems(Cliente c){
  return c->items;
}

int getEntrada(Cliente c){
  return c->entrada;
}

void repr(Cliente c){
    printf("[%d:%d] ", getItems(c), getEntrada(c));
}
