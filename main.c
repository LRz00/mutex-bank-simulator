#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int saldo = 20000;
int saquesTotal = 0;
int depositosTotal = 0;

#define qte_threads 10

void *saque(int i);
void *deposito(int i);
pthread_mutex_t semMut;

int main(void) {
  pthread_t thread[qte_threads];

  srand(time(NULL));
  pthread_mutex_init(&semMut, NULL);

  for (int i = 0; i < qte_threads; i++) {
    pthread_create(&thread[i], NULL, (void *)saque, i);
    pthread_create(&thread[i], NULL, (void *)deposito, i);
  }

  for (int i = 0; i < qte_threads; i++) {
    pthread_join(thread[i], NULL);
  }
  pthread_mutex_destroy(&semMut);

  printf("\nTOTAL DE SAQUES: %d\n", saquesTotal);
  printf("TOTAL DE DEPOSITOS: %d\n", depositosTotal);
  printf("SALDO FINAL: %d\n", saldo);
}

void *saque(int i) {

  pthread_mutex_lock(&semMut);
  int saque = rand() % 20000;
  
  if (saque < saldo) {
    saldo = saldo - saque;
    printf("Thread %d sacou %d\n", i, saque);
    printf("Saldo atual: %d\n", saldo);
    saquesTotal = saquesTotal + saque;
    printf("Thread %d finalizou o saque\n\n", i);
  } else {
    printf("Saldo insuficiente para saque\n");
  }
  pthread_mutex_unlock(&semMut);
}

void *deposito(int i) {
  pthread_mutex_lock(&semMut);
  int deposito = rand() % 100;
  saldo = saldo + deposito;
  printf("Thread %d depositou %d\n", i, deposito);
  printf("Saldo atual: %d\n", saldo);
  depositosTotal = depositosTotal + deposito;
  pthread_mutex_unlock(&semMut);
  printf("Thread %d finalizou o deposito\n\n", i);
}
