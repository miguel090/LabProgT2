#ifndef CAIXA_H
#define CAIXA_H
#include"queue.c"
typedef enum {FALSEE,TRUEE} BOOLL;
typedef struct caixa{
  QUEUE* filaCl;
  int prontaEm;
  int ctsAtend;
  int prodProcessados;
  int totalEspera;
  int nrC;
  int prodsUT;
}*Caixa;
BOOLL vazia(Caixa c);
Caixa init(int nrC);
Caixa mudaInfoCaixa(Caixa c, int inst);
void aumentaClientesAtendidos(Caixa c);
void mudaInfoProdutos(Caixa c, int produtos);
void mudaInfoTEspera(Caixa c, int t);
void setProntaEm(Caixa c, int inst);
QUEUE* getFilaCl(Caixa c);
int getNrC(Caixa c);
int getProntaEm(Caixa c);
int getCtsAtend(Caixa c);
int getProdProcessados(Caixa c);
int getTotalEspera(Caixa c);
int getProdsUT(Caixa c);
void printCaixa(Caixa c);
#endif
