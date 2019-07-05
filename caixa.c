#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "caixa.h"


Caixa init(int nrC){
  Caixa c = (Caixa) malloc(sizeof(struct caixa));
  c->filaCl=mk_empty_queue(30);
  c->prontaEm=0;
  c->ctsAtend=0;
  c->prodProcessados=0;
  c->totalEspera=0;
  c->nrC = nrC;
  c->prodsUT= (int)((rand() % 5) + 1); //produtos por unidade de tempo
  return c;
}
void setProntaEm(Caixa c, int inst){
  c->prontaEm = inst;

}
void aumentaClientesAtendidos(Caixa c){
  c->ctsAtend++;

}
void mudaInfoProdutos(Caixa c, int produtos){
  c->prodProcessados = c->prodProcessados + produtos;
}

void mudaInfoTEspera(Caixa c, int t){
  c->totalEspera = c->totalEspera + t;

}
QUEUE* getFilaCl(Caixa c){
  return  c->filaCl;
}
int getNrC(Caixa c){
  return c->nrC;
}
int getProntaEm(Caixa c){
  return c->prontaEm;
}
int getCtsAtend(Caixa c){
  return c->ctsAtend;
}
int getProdProcessados(Caixa c){
  return c->prodProcessados;
}
int getTotalEspera(Caixa c){
  return c->totalEspera;
}
int getProdsUT(Caixa c){
  return c->prodsUT;
}
BOOLL vazia(Caixa c){
  if(queue_is_empty(getFilaCl(c))==FALSEE){
    return FALSEE;
  }
  else return TRUEE;
}
void printCaixa(Caixa c){
  printf("Caixa %d pronta Em %d  ",c->nrC, c->prontaEm);
  printQueue(c->filaCl);
  printf("\n");
}
