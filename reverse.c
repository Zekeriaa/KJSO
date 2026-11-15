
#include <stdio.h>
#include <stdlib.h>


int main() {

    /* FILE osoitin */
    FILE *fp;
    /* avataan tiedosto*/
    fp = fopen("input.txt", "r");

    /*tarkistetaan tiedoston avaamisen onnistumisen*/
    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file 'input.txt'\n");
        return 1;
    }

    char *line = NULL;
    size_t cap = 0;
    ssize_t read;

    /* Luetaan tiedoston rivi kerrallaan*/
    while ((read = getline(&line, &cap, fp)) != -1) {
        printf("%s", line);
    }


    free(line);
    fclose(fp);
    return 0;
}
