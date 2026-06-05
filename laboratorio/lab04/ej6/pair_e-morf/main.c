#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

//El tipo de elem del TAD se decide en pair.h. Solo te queda cambiar el show_pair, el resto no
//El show depende del tipo de elem del TAD
//Si queres que se muestre bien (editar %d del printf)
static 
void show_pair(pair_t p) {
    printf("(%c, %c)\n", pair_first(p), pair_second(p));
}

int main(void) { 
    pair_t p, q;

    // Nuevo par p
    p = pair_new('a', 'b');

    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);

    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);

    // Se vuelve a mostrar p
    printf("p = ");
    show_pair(p);

    // Se muestra q
    printf("q = ");
    show_pair(q);

    // Se destruyen p y q
    pair_destroy(p);
    pair_destroy(q);

    return EXIT_SUCCESS;
}
