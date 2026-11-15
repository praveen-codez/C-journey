#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char *str = NULL;
    size_t cap = 0;

    ssize_t n = getline(&str, &cap, stdin);

    if (n > 0 && str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }

    int *count = calloc(256, sizeof(int));
    if (!count) {
        free(str);
        return 1;
    }

    for(int i = 0; i < (int)n; i++){
        count[(unsigned char)str[i]]++;
    }

    int found = 0;
    for(int i = 0; i < n; i++){
        printf("%d %c\n", i, count[i]);
        if (count[(unsigned char)str[i]] == 1) {
            printf("First non repeating character is: %c\n", str[i]);
            found = 1;
            break;
        }  
    }

    if (!found) {
        printf("No non-repeating character found.\n");
    }


    free(str);
    free(count);
    return 0;


}