/**
 * @file pair.h
 * @brief Interface for a dynamically allocated pair of integers.
 */

#include <stdlib.h>  /* malloc(), free()... */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    int fst;
    int snd;
};

/**
 * @brief Creates a new pair with components (x, y).
 *
 *
 * @param x First component value.
 * @param y Second component value.
 * @return A newly allocated pair containing (x, y).
 */
pair_t pair_new(int x, int y){
    pair_t p = malloc(sizeof(struct s_pair_t)); 
    p->fst = x;
    p->snd = y;
    return p;
}
 
/**
 * @brief Returns the first component of p.
 *
 *
 *
 * @param p Pair to inspect.
 * @return The first component (fst) of p.
 */
int pair_first(pair_t p){
    return p->fst;
}
 
/**
 * @brief Returns the second component of p.
 *
 * 
 * @param p Pair to inspect.
 * @return The second component (snd) of p.
 */
int pair_second(pair_t p){
    return p->snd;
}


/**
 * @brief Returns a NEW pair with the components of p reversed.
 * 
 *
 * @param p Original pair.
 * @return A newly allocated pair containing (pair_second(p), pair_first(p)).
 */
pair_t pair_swapped(pair_t p){
    return pair_new(pair_second(p), pair_first(p));
    //O es mejor:
    /*
    
    pair_t q = malloc(sizeof(struct s_pair_t));
    q->fst = pair_second(p);
    q->snd = pair_first(p);
    return q;

    Me parece mezcla rara de implementacion y abstaccion. 
    Hay que elegir completamente una o la otra? Siempre es mejor una?
    
    */
}
 
/**
 * @brief Frees memory if necessary.
 *
 *
 * @param p Pair to destroy.
 */
void pair_destroy(pair_t p){
    free(p);
}