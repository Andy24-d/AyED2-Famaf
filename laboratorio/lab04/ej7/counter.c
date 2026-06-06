#include <stdbool.h>
#include <stdlib.h>
//#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    //assert(c != NULL);
    
    c->count = 0;
        
    

    return c;
    
}

void counter_inc(counter c) {
    //assert(c != NULL);
    c->count++;
    
}

bool counter_is_init(counter c) {
    bool is_init = false;

    if (c != NULL){
        is_init = c->count == 0;
    }

    return is_init;
}

void counter_dec(counter c) {

    //assert( !counter_is_init(c) );
    
    if (c != NULL){
        c->count--;
    } 
}

counter counter_copy(counter c) {

    counter c_new = malloc(sizeof(struct _counter));
    
    if (c_new != NULL){
        c_new->count = c->count;
    }

    return c;
}

void counter_destroy(counter c) {
    free(c);
    c = NULL;
}
