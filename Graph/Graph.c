#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int v;

typedef struct aux
{
    int v;
    struct aux *prox;
} NO;

typedef struct
{
    NO *inicio;
} vertice;

void initialize(vertice *g)
{
    int i;
    for (i = 0; i < v; i++)
        g[i].inicio = NULL;
}

bool isEdge(vertice *g, int ver, int value)
{
    if (ver > v || ver < 1)
        return false;

    NO *no = g[ver-1].inicio;
    while (no)
    {
        if (value == no->v)
            return true;
        no = no->prox;
    }

    return false;
}

bool unorderedAdd(vertice *g, int ver, int value)
{
    if (ver > v || ver < 1)
        return false;
    if (isEdge(g, ver, value))
        return false;

    NO *new = (NO *)malloc(sizeof(NO));
    new->v = value;
    new->prox = g[ver-1].inicio;

    g[ver-1].inicio = new;

    return true;
}

void printVertice(vertice *g, int ver)
{
    printf("%d | ", ver);
    NO *no = g[ver-1].inicio;
    while (no)
    {
        printf(" --%d ", no->v);
        no = no->prox;
    }

    printf(" ¬ \n");
}

void printGraph(vertice *g)
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        printVertice(g, i);
    }
}

int main()
{
    v = 5;
    vertice *g = (vertice *)malloc(sizeof(vertice) * (v));
    initialize(g);

    unorderedAdd(g, 2, 5);
    unorderedAdd(g, 2, 5);
    unorderedAdd(g, 0, 5);
    unorderedAdd(g, 5, 1);
    unorderedAdd(g, 5, 2);

    printGraph(g);
    return 0;
}