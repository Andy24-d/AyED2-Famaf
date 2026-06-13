/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


float average(list l) {

    list l_aux = copy_list(l);
    float sum = 0.0;
    
    while(!is_empty(l_aux)){
        sum += head(l_aux);
        l_aux = tail(l_aux);
    }

    return sum / length(l);

}

list daditos (list p1, list p2) {
    //Gana dado mas bajo
    //Gano p1 => add 1
    //Gano p2 => add 2
    //Empate => si ronda par gana 2
    //          si ronda impar gana 1
    //Ronda inicial = 1
    list negro = empty();
int n = length(p1);
    for(int i= 0; i<n;i++){
        if(index(p1, i)<index(p2, i)){
            negro = addr(negro, 1);
        }
        else if(index(p1, i)>index(p2, i)){
            negro = addr(negro, 2);
        }
        else{
            if(i+1%2==0){
                negro = addr(negro, 1);
            }else{
                negro = addr(negro, 2);
            }
        }
    }
    return negro;
}

list array_to_list(int array[], unsigned int length) {
    /* Initialize the list */
    list l = empty();

    for (unsigned int i = length; i > 0; --i) {
        /* Add element to the list  */
        l = addl(array[i - 1], l);
    }
    /* Return list */
    return l;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    array_dump(array, length);

    /* transform from array to our list type */
    list l = array_to_list(array, length);

    /* call the average function */
    printf("The average is: %.2f \n", average(l));

    return (EXIT_SUCCESS);
}
