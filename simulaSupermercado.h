#ifndef SUPER_H
#define SUPER_H

#include "caixa.c"

void simuladorSuperMercado(int afluencia, int apetencia, int n_caixas, int ciclos);
void mostrarCaixas(Caixa* AllCaixas, int size);
void trataClientes(int passo, Caixa* lista_caixas, int nr_caixas);
int caixasCheias(Caixa* lista, int nr_caixas);
void trataPrimeiro(int passo, Caixa caixa_actual);
void processa_resultados(Caixa* caixas, int nr_caixas);
#endif
