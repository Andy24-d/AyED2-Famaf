#include <stdlib.h>
#include <assert.h>

#include "list.h"


struct _list {
    elem value;
    struct _list* next;
};




//
// Constructors
//

/**
 * @brief Creates a new empty list.
 */
list empty(){
    return NULL;
}

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l){

    list new_list = malloc(sizeof(struct _list));
    new_list->value = e;
    new_list->next = l;

    return new_list;
}

//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l){
    return l == NULL;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l){
    return l->value;
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l){
    assert( !is_empty(l) );

    list new_head = l->next;
    free(l);
    
    return new_head;
}

/**
 * @brief Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e){
    list new_node = malloc( sizeof(struct _list) );
    new_node->value = e;
    list p = l;

    if (l == NULL){
        l = new_node;
    } else {
        //Es mejor poner list p = l; aca?
        while(p->next != NULL) p = p->next;
        p->next = new_node;
    }
    

    return l;
}

/**     OTRA FORMA:
 * @brief Adds in-place element `e` to the right of list `l`.
 */
list addr2(list l, elem e){
    list p = l;

    if (l == NULL){
        l = addl(e, l);
    } else {
        while(p->next != NULL) p = p->next;
        p->next = addl(e, empty());
    }

    return l;
}

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l){
    int count = 0;
    list p = l;

    while (p != NULL){
        count++;
        p = p->next;
    }

    return count;
}

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0){
    if (l == NULL){
        l = l0;
    } else {
        list p = l;
        while(p->next != NULL) p = p->next;
        //p points to the last element of l
        p->next = l0;
    }

    return l;
}

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n){
    assert( n < length(l) );

    list p = l;
    for (int i=0; i != n; i++){
        p = p->next;
    }

    return p->value;
}

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n){
// testea: take([8, 1, -2], 0) == []

    list aux_p = l; //Starts pointing to the first element of l

    if(n == 0){
        destroy_list(l);
        return empty();
    }

    int i = 0;
    while(i != n-1 && aux_p != NULL){
        aux_p = aux_p->next;
        i++;
    }
    //aux_p points to the nth element of l or NULL (if length(l)<n)

    if(aux_p != NULL){
        destroy_list(aux_p->next); //Deletes the rest of the list.
        aux_p->next = NULL; 
    }
    
    return l;
}

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n){
    for(int i=0; i != n; i++){
        l = tail(l);
    }

    return l;
}

/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l){
    list new_list=NULL;
    //Pointers to keep track of the next node to copy and the last node added to new_list
    list next_node = l;          
    list last_added = NULL;

    //Initialize new_list with the first element of l (if it exists)
    if (l != NULL){
        new_list = addl(next_node->value, new_list);
        next_node = next_node->next;
        last_added = new_list;
    }

    while(next_node != NULL){

        last_added->next = addl(next_node->value, empty());

        next_node = next_node->next;
        last_added = last_added->next;
    }

    return new_list;
}

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l){
    list p = l;
    while(p != NULL){
        p = p->next;
        free(l);
        l = p;
    }
    //Both end up pointing to NULL
}

/**         OTRA FORMA:
 * @brief Frees memory for `l`.
 */
void destroy_list2(list l){
    list p = l;
    while (p != NULL){
        list aux = p->next;
        free(p);
        p = aux;
    }
}