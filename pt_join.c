#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define NUMERO_THREADS 4

int vg;
pthread_mutex_t lock;

void *Print(void *ThreadID)
{

    long k, total_de_pontos;
    float r;
    long thread_id;
    thread_id = (long)ThreadID;

    printf("\nIniciou, thread #%ld!\n", thread_id);

    total_de_pontos = 1000000000 / NUMERO_THREADS;

    for (k = 0; k < total_de_pontos; k++)
    {
        r = sin(1.77) * cos(.99);
    }

    /* Testa o mutex. Se liberado, ativa o mutex e avança. */

    pthread_mutex_lock(&lock);

    printf("Valor vg = %d - Thread #%ld\n", vg, thread_id);

    vg = vg + 1;

    printf("Terminou, thread #%ld!\n", thread_id);

    /* Libera o mutex. */

    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

    pthread_t threads[NUMERO_THREADS];
    int codigo_de_retorno;
    long t;
    void *status;
    pthread_attr_t atributo;
    time_t inicio, fim, reghora;
    struct tm *tmptr;

    printf("\n\nPROGRAMA PRINCIPAL INICIOU\n\n");

    reghora = time(NULL);
    tmptr = localtime(&reghora);
    printf("Horário de Início: %s\n", asctime(tmptr));

    inicio = time(NULL);

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n O pthread_mutex_init() falhou!\n");
        return 1;
    }

    /* Bloqueia o início das threads até que todas sejam criadas. */

    pthread_mutex_lock(&lock);

    /* Cria as threads. */

    vg = 0;

    pthread_attr_init(&atributo);
    pthread_attr_setdetachstate(&atributo, PTHREAD_CREATE_JOINABLE);

    for (t = 0; t < NUMERO_THREADS; t++)
    {
        printf("Main: criando thread %ld\n", t);
        codigo_de_retorno = pthread_create(&threads[t], &atributo, Print, (void *)t);
        if (codigo_de_retorno)
        {
            printf("ERRO; O código de retorno da pthread_create() é %d\n", codigo_de_retorno);
            exit(-1);
        }
    }

    /* Libera as threads para iniciarem. */

    pthread_mutex_unlock(&lock);

    /* Rotina para esperar que todas as threads terminem. */

    pthread_attr_destroy(&atributo);

    for (t = 0; t < NUMERO_THREADS; t++)
    {
        pthread_join(threads[t], &status);
    }

    fim = time(NULL);

    reghora = time(NULL);
    tmptr = localtime(&reghora);
    printf("\nHorário de Término: %s", asctime(tmptr));

    fprintf(stdout, "Tempo Gasto = %f\n\n", difftime(fim, inicio));

    pthread_exit(NULL);
    pthread_mutex_destroy(&lock);
}
