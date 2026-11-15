#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    /* FILE osoitin */
    FILE *fp = stdin;



    /*tarkistetaan tiedoston avaamisen onnistumisen*/
    if (argc >= 2) {
        fp = fopen(argv[1], "r");    /*Avataan tiedosto*/

        if (fp == NULL) {
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    }


    char *line = NULL;
    size_t cap = 0;
    ssize_t read;

    /* Luetaan tiedoston rivi kerrallaan*/
    while ((read = getline(&line, &cap, fp)) != -1) {
        fprintf(stdout,"%s", line);
    }


    free(line);
    fclose(fp);
    return 0;
}

