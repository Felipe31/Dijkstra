#ifndef _RR_
#define _RR_

#define HEAP_SIZE 1000


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef struct node{
    int cost, pi, key;                  // pi = pai no caminho minimo | cost = custo mínimo no caminho mínimo | key = nome do vértice
} node;                                 // primeiramente usar um vetor

typedef struct heap{
    node ** node_vector;
    int control;
} heap;

typedef struct edge {
    int head_vertex, cost, tail_vertex; // tail -> head
    char hot_line;                      // hot_line = aresta faz parte do caminho mínimo
    struct edge *next_pred;             // prox na lista de predecessores
    struct edge *next_adj;              // prox na lista de adjacentes
} edge;

typedef struct vertex {
    node heap_node;
    int pi;
    char mark;
    edge *adjacent;                     // lista de adjacentes
    edge *predecessor;                  // lista de predecessores
} vertex;


/************************************************************************************************
*************************************************************************************************
****************************** ALGORITMOS DE RAMALINGAM E REPS *******************************
*************************************************************************************************
************************************************************************************************/
void rr_recalculate_shortest_path(vertex *graph, heap *queue);
void rr_add_edge(vertex *graph, int tail, int head, int cost);
void rr_remove_edge(vertex *graph, edge *edge_removed);
vertex *rr_mark_affected(vertex *graph, edge *edge_marked);
void rr_estimate_new_pi(vertex *graph, vertex *affected_list, heap *queue, edge vertex);

edge * find_edge_pred(vertex * head, int key);
edge * find_edge_adj(vertex * tail, int key);
edge ** find_pointer_edge_pred(vertex *head, edge *edge_ref);
edge ** find_pointer_edge_adj(vertex *tail, edge *edge_ref);



/************************************************************************************************
*************************************************************************************************
****************************** ALGORITMOS DE MANIPULAÇÃO DO GRAFO *******************************
*************************************************************************************************
************************************************************************************************/
void g_free_graph(vertex *graph, int size);

vertex *g_create_graph(int size);

void g_print_graph(vertex *graph, int size);

edge * g_insert_edge(vertex *graph, int tail, int head, int cost);


/************************************************************************************************
*************************************************************************************************
****************************** ALGORITMOS DE MANIPULAÇÃO DO HEAP *******************************
*************************************************************************************************
************************************************************************************************/


heap * heap_new();

node * heap_extract(heap * queue);

int heap_checks_presence(node * heap_node, heap * queue);  // Retorna 0 se o nó não pertence ao heap e 1 caso contrário

void heap_update(node * heap_node, int new_pi, int new_cost, heap * queue, int pos);

int heap_insert(node * node_to_insert, heap * queue);       // Retorna 0 se o nó foi inserido com sucesso no heap e 1 caso contrário

void heapfy(heap * queue);  

#endif