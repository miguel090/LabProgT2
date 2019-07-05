#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulaSupermercado.h"

int main() {
int afluencia, apetencia, nCaixas, nCiclos;
scanf("%d %d %d %d", &afluencia, &apetencia, &nCaixas, &nCiclos);
simuladorSuperMercado(afluencia,apetencia,nCaixas,nCiclos);
}
void simuladorSuperMercado(int afluencia, int apetencia, int n_caixas, int ciclos){
  int i = 0;
  srand(time(0));
  Caixa caixas[n_caixas];
  for(i = 0; i < n_caixas; i++){
    caixas[i] = init(i);
  }

  for (i = 0; i < ciclos; i++) {
    printf("Ciclo %d\n", i);
    trataClientes(i,caixas, n_caixas);

    int random = rand()%100;
    if(random <= afluencia){
      int produtos = rand()%apetencia + 1;
      Cliente novo = set(produtos, i);
      printf("Criado cliente com %d produtos\n", produtos);
      int caixa = rand()%n_caixas+1;
      enqueue(novo,getFilaCl(caixas[caixa-1]));
    }

    mostrarCaixas(caixas, n_caixas);

  }

  printf("== FECHO DE CAIXAS ==\n");
  i = ciclos;

  while(caixasCheias(caixas, n_caixas)==1){
    printf("Ciclo %d\n", i);
  	 trataClientes(i,caixas, n_caixas);
  	 mostrarCaixas(caixas, n_caixas);
     i++;
  }

  processa_resultados(caixas, n_caixas);
}

void mostrarCaixas(Caixa* AllCaixas, int size){
  int i;
  for(i=0; i<size; i++){
    printCaixa(AllCaixas[i]);
  }
}

void trataClientes(int passo, Caixa* lista_caixas, int nr_caixas){
	int i = 0;
	for(i = 0; i < nr_caixas; i++){
		if(vazia(lista_caixas[i])==TRUEE){
			setProntaEm(lista_caixas[i], passo);
		}
    else{
			trataPrimeiro(passo, lista_caixas[i]);
    }
	}
}

int caixasCheias(Caixa lista[], int nr_caixas){
    int j = 0;
    for(j = 0; j < nr_caixas; j++){
      if(vazia(lista[j])==FALSEE){
        return 1;
      }
    }
    return 0;
  }

void trataPrimeiro(int passo, Caixa caixa_actual){
    Cliente cliente = peek(getFilaCl(caixa_actual));
    int espera  = passo - getProntaEm(caixa_actual);
    int processados = espera * getProdsUT(caixa_actual);

          if (processados >= getItems(cliente)){
          setProntaEm(caixa_actual, passo + 1);
          aumentaClientesAtendidos(caixa_actual);
          mudaInfoProdutos(caixa_actual,getItems(cliente));
          mudaInfoTEspera(caixa_actual, passo - getEntrada(cliente));
          dequeue(getFilaCl(caixa_actual));

          printf("cliente servido na caixa %d\n", getNrC(caixa_actual));

      }
  }
void processa_resultados(Caixa* caixas, int nr_caixas){
    int i = 0;
    for(i = 0; i < nr_caixas; i++){
          printf("Caixa %d (%d produtos por ciclo) ",getNrC(caixas[i]), getProdsUT(caixas[i]));

          if (getCtsAtend(caixas[i]) != 0){
              printf("%d clientes atendidos ", getCtsAtend(caixas[i]));
              printf("media %.1f produtos/cliente ", (float) getProdProcessados(caixas[i])/getCtsAtend(caixas[i]));
          }
          else
              printf("%d clientes atendidos ", getCtsAtend(caixas[i]));
          printf("\n");
    }
  }
