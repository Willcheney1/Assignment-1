#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void railfence (char *message, char *cipherText, int length, int A)
{
    int x, y, count = 0, q = 0; // declaring x as column number, y as column rows and code as the specific point
    length = strlen(message); // set the variable length to the length of the string read
    char code[A][length];

    for (y=0; y<A; y++){ // applies for all the rows
        for (x=0; x<length; x++){ // applies for all the column numbers
            code[y][x] = 0; // setting the initial value to 0
        }
    }
    x = 0;
    while (x<length){ // running from 0 to length - 1
        if (count%2 == 0){ // if the count is divisible by 2
            for (y=0; y<A; y++){ // go down the rows from 0 to A-1
                code[y][x] = message[x]; // to set the location of the char in the string in position y,x
                x++; // increase x by 1
            }
        }
        else{
            for (y=A-2; y>0; y--){ // going up the rows as last row has been hit
                code[y][x] = message[x]; // set the specific number to x
                x++; // increase x by 1
            }
        }
        count++;
    }

    printf("\nthis is the encryption:\n");

    for (y=0; y<A; y++){
        for (x=0; x<length; x++){
            if (code[y][x] != 0){
                cipherText[q] = code[y][x];
                q++;
            }
        }
    }

}

void railFence2(char *message, char *cipherText, int length, int A, int B, int dir)
{


    int x, y, i = 0, q = 0;
    char code[100][1000]; // declaring x as column number, y as column rows and code as the specific point

    switch(dir){
    case 0:
        length = strlen(message);
        for (y=0; y<A; y++){ // applies for all the rows
            for (x=0; x<length; x++){ // applies for all the column numbers
                code[y][x] = 0; // setting the initial value to 0
            }
        }
        x = 0;
        while (x < length) {
            switch (i = 0){
                case 0:
                    for (y = 0; y < A; y++){
                        code[y][x] = message[x];
                        x++;
                    }
                    i++;
                case 1:
                    for (y = A - 2; y > A-B; y--){
                        code[y][x] = message[x];
                        x++;

                    }
                    i++;
                case 2:
                    for (y = A-B; y < A; y++){
                        code[y][x] = message[x];
                        x++;
                    }
                    i++;
                case 3:
                    for (y=A-2; y>0; y--){ // going up the rows as last row has been hit
                        code[y][x] = message[x]; // set the specific number to x
                        x++; // increase x by 1
                    }
                i = i - 3;
            }
        }
        printf("\nthis is the Encryption:\n");
        q = 0;
            for (y=0; y<A; y++){
                for (x=0; x<length; x++){
                    if (code[y][x] != 0){
                        cipherText[q] = code[y][x];
                        q++;
                    }

                }
            }

            break;


    case 1:

        length = strlen(cipherText);
            for (y=0; y<A; y++){ // applies for all the rows
                for (x=0; x<length; x++){ // applies for all the column numbers
                    code[y][x] = 0; // setting the initial value to 0
                }
            }
       x = 0;
        while (x < length) {
            switch (i = 0){
                case 0:
                    for (y = 0; y < A; y++){
                        code[y][x] = '1';
                        x++;
                    }
                    i++;
                case 1:
                    for (y = A - 2; y > A-B; y--){
                        code[y][x] = '1';
                        x++;

                    }
                    i++;
                case 2:
                    for (y = A-B; y < A; y++){
                        code[y][x] = '1';
                        x++;
                    }
                    i++;
                case 3:
                    for (y=A-2; y>0; y--){ // going up the rows as last row has been hit
                        code[y][x] = '1'; // set the specific number to x
                        x++; // increase x by 1
                    }
                i = i - 3;
            }
        }
        q = 0;
        while (q < length){
            for(y = 0; y < A; y++){
                for(x = 0; x < length; x++){
                    if (code[y][x] != 0){
                        code[y][x] = cipherText[q];
                        q++;
                    }
                }
            }
        }
        printf("\nthis is the Decryption:\n");
        q = 0;

                for (x=0; x<length; x++){
                    for(y = 0; y < A; y++){
                        if (code[y][x] != 0){
                           message[q] = code[y][x];
                           q++;
                        }
                    }
                }
        break;

    }
}

int main(){
    FILE *fptr;
    int A, B, length, dir, option;
    char message[100000], cipherText[100000];
    //printf("WELCOME TO THE CIPHER STATION\n");
    //printf("Press 1 for Classical Rail Encryption\n");
    //printf("Press 2 for 2-Level Rail Encryption/Decryption\n");
    scanf("%d", &option);
    if(option != 2 && option != 1){
        printf("Incorrect value selected. Restart Program\n");
        return 0;
    }
    else if (option == 1){
        //printf("\nenter number of rails\n"); // display on the screen to instruct the user
        scanf("%d", &A); // assign the users input as A
       // printf("\nenter secret message\n"); // display on the screen to instruct the user
        setbuf(stdin, NULL);
        fgets(message, sizeof(message), stdin); // read all the characters of the users input as a messageing rather than individual characters
        strtok(message, "\n");
        fptr = fopen("message.txt", "w");
        fprintf(fptr, message);
        railfence(message, cipherText, length, A);
        fptr = fopen("cipherText.txt", "w");
        fprintf(fptr, cipherText);
        fptr = fopen("cipherText.txt", "r");
        while(!feof(fptr)){
            fgets(cipherText, sizeof(cipherText), fptr); // read all the characters of the users input as a string rather than individual characters
            puts(cipherText);
        }
        fclose(fptr);
    }
    else if (option == 2){
        printf("\nPress 0 for 2-Level Rail Encryption\n");
        printf("Press 1 for 2-Level Rail Decryption\n");
        scanf("%d", &dir);
        if (dir != 1 && dir != 0){
            printf("Incorrect value selected. Restart Program\n");
            return 0;
        }
        printf("\nenter message\n"); // display on the screen to instruct the user
        setbuf(stdin, NULL);
            if (dir == 1){
                fgets(cipherText, sizeof(cipherText), stdin); // read all the characters of the users input as a string rather than individual characters
                strtok(cipherText, "\n");
                fptr = fopen("cipherText.txt", "w");
                fprintf(fptr, cipherText);
            }
            else if (dir == 0){
                fgets(message, sizeof(message), stdin); // read all the characters of the users input as a string rather than individual characters
                strtok(message, "\n");
                fptr = fopen("message.txt", "w");
                fprintf(fptr, message);
            }
        printf("\nenter number of rails\n"); // display on the screen to instruct the user
        scanf("%d", &A); // assign the users input as A
        printf("\nenter number of peak\n");
        scanf("%d", &B);
        if (A < B){
            printf("ERROR! Inappropriate values entered");
            return 0;
        }
        else{
            railFence2 (message, cipherText, length, A, B, dir);
            if (dir ==1 ){
                fptr = fopen("message.txt", "w");
                fprintf(fptr, message);
                fptr = fopen("message.txt", "r");
                while(!feof(fptr)){
                    fgets(message, sizeof(message), fptr); // read all the characters of the users input as a string rather than individual characters
                    puts(message);
                }
                fclose(fptr);

            }
            else{
                fptr = fopen("cipherText.txt", "w");
                fprintf(fptr, cipherText);
                fptr = fopen("cipherText.txt", "r");
                while(!feof(fptr)){
                    fgets(cipherText, sizeof(cipherText), fptr); // read all the characters of the users input as a string rather than individual characters
                    puts(cipherText);
                }
                fclose(fptr);

            }
        }
    }
    return 0;
}



