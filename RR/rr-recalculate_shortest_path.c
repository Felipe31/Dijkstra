#include "rr.h"
#include <limits.h>
#define infinity INT_MAX

void rr_recalculate_shortest_path(vertex *graph, heap *queue){
	node *x;
	while(queue){
		x = heap_extract_min(queue);
		(graph+x->key)->pi = x->pi;
		(graph+x->key)->min_cost = x->cost;
		 edge *aux;// = (graph+x->key)->predecessor;
		// while(aux){
		// 	aux->hot_line = 0;
		// 	aux = aux->next_pred;
		// }
		aux = (graph+x->pi)->adjacent;
		while(aux){
			if(aux->head_vertex == x->key){
				aux->hot_line = 1;
				
				break;
			}
			aux = aux->next_adj;
		}
		aux = (graph+x->key)->adjacent;
		while(aux){
			if((graph+aux->head_vertex)->mark)
				relax(aux, queue);
			else{
				if((graph+aux->head_vertex)->min_cost > x->cost + aux->cost){
					(graph+aux->head_vertex)->pi = x->key;
					(graph+aux->head_vertex)->min_cost = x->cost + aux->cost;
					heap_insert((graph+aux->head_vertex)->key, (graph+aux->head_vertex)->pi, queue, (graph+aux->head_vertex)->min_cost);
				}
			}
			aux = aux->next_adj;
		}
	}
}

vertex *rr_mark_affected(vertex *graph, edge *edge_marked, vertex *auxiliary_list, vertex *affected_list){
<<<<<<< HEAD:RR/rr - recalculate_shortest_path().cpp
	auxiliary_list = graph[edge_marked->head_vertex];

	vertex *aux = auxiliary_list;
	while(auxiliary_list){
		while(aux->){}
	}
=======

>>>>>>> 0d5329bbfa5a0aa33c357b1bde947e82aa1ea18d:RR/rr-recalculate_shortest_path.c
}