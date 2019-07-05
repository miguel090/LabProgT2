#ifndef CLIENTE_H
#define CLIENTE_H
typedef struct cliente{
  int items;
  int entrada;
}*Cliente;

Cliente set(int items, int entrada);
int getItems(Cliente c);
int getEntrada(Cliente c);
void repr(Cliente c);
#endif
