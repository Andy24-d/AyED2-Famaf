#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    while (s[i] != '\0'){
        i++;
    }

    return i;
    // return largo_sizeof;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool string_eq = true;
    
    
    /* IDEA 1
    unsigned int largo1 = fstring_length(s1);
    unsigned int largo2 = fstring_length(s2);

    if(largo1 != largo2) return false;
    //if(largo1 != largo2) string_eq = false;

    for(unsigned int i=0; i < largo1 && string_eq; i++){
        string_eq = s1[i] == s2[i];
    }

    */

    //IDEA 2
    unsigned int i = 0;
    while(
        (s1[i] != '\0' || 
         s2[i] != '\0') && 
        string_eq
        )
    {
        string_eq = s1[i] == s2[i];
        i++;
    }

    return string_eq;
}

char lowercase(char letter){

    if (letter >= 'A' && letter <= 'Z') {
        letter += ('a' - 'A');
    }
    
    return letter;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {

    /*
    bool is_less = s1[0] < s2[0];
  
    unsigned int i = 1;
    while(s1[i-1] == s2[i-1] && s2[i] != '\0' && !is_less){

        is_less = s1[i] < s2[i];
        i++;
    }
    */

    /*
    bool is_less = s1[0] < s2[0];
  
    unsigned int i = 1;
    while(s1[i-1] == s2[i-1] && s2[i] != '\0' && !is_less){

        is_less = s1[i] < s2[i];
        i++;
    }
    */
    bool is_less;
    bool compare = s1[0] == s2[0];

    if(s1[0] < s2[0]) is_less = true;
    if(s1[0] > s2[0]) is_less = false;

    int i = 1;
    while(compare){
        if(s1[i] < s2[i]) {
            is_less = true;
            compare = false;
        }
        if(s1[i] > s2[i]) {
            is_less = false;
            compare = false;
        }
        if(s1[i] == '\0' && s2[i] == '\0'){
            is_less = true;
            compare = false;
        }

        i++;
    }
    

    return is_less;
    
}

