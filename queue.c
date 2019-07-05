#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
static void queue_exit_error(char *msg);

static void queue_exit_error(char *msg)
{
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}

// criar fila com capacidade para n inteiros
QUEUE *mk_empty_queue(int n)
{
  QUEUE *q = (QUEUE *) malloc(sizeof(struct fila));
  if (q == NULL)
    queue_exit_error("sem memoria");

  q -> queue =  (Cliente) calloc(sizeof(struct cliente),n);
  if (q -> queue == NULL)
    queue_exit_error("sem memoria");

  q -> nmax = n;
  q -> inicio = -1;
  q -> fim = 0;
  return q;
}
// libertar fila
void free_queue(QUEUE *q)
{
  if (q != NULL) {
    free(q -> queue);
    free(q);
  } else
    queue_exit_error("fila mal construida");
}


// colocar valor na fila
void enqueue(Cliente v,QUEUE *q)
{
  if (queue_is_full(q) == TRUE)
    queue_exit_error("fila sem lugar");

  if (q -> queue == NULL)
    queue_exit_error("fila mal construida");

  if (queue_is_empty(q)==TRUE)
    q -> inicio = q -> fim; // fila fica com um elemento
  q -> queue[q->fim] = *v;
  q -> fim = (q -> fim+1)%(q->nmax);
}

// retirar valor na fila
Cliente dequeue(QUEUE *q)
{
  Cliente aux;
  if (queue_is_empty(q) == TRUE)
    return NULL;

  if (q -> queue == NULL)
    queue_exit_error("fila mal construida");

  aux = &q->queue[q ->inicio];
  q -> inicio = (q -> inicio+1)%(q -> nmax);
  if (q -> inicio ==  q -> fim) {  // se só tinha um elemento
    q -> inicio = -1; q -> fim = 0;
  }
  return aux;
}
Cliente peek(QUEUE *q) {
  Cliente aux;

  if(queue_is_empty(q) == TRUE) {
    queue_exit_error("Queue is Empty");
  }

  if(q->queue == NULL) {
    queue_exit_error("Queue error");
  }

  aux = &q->queue[q->inicio];

  return aux;
}
// verificar se a fila está vazia
BOOL queue_is_empty(QUEUE *q)
{
  if (q == NULL)
    queue_exit_error("fila mal construida");

  if (q -> inicio == -1) return TRUE;
  return FALSE;
}

// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *q)
{
  if (q == NULL)
    queue_exit_error("fila mal construida");

  if (q -> fim == q -> inicio) return TRUE;
  return FALSE;
}

void printQueue(QUEUE *q){
  Cliente first = dequeue(q);
  Cliente cur = set(0, -1);
  if(first==NULL) return;
  repr(first);
  enqueue(first, q);
  while(1){

      cur=dequeue(q);
      if(getEntrada(cur)==getEntrada(first)) break;
      repr(cur);
      enqueue(cur, q);
  }
  enqueue(cur, q);
}
