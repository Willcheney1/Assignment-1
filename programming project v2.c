#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//William Cheney, student number: c3330779, Programming assignment 1

void railfence (char *message, char *cipherText, int length, int A)
{
    //FILE FORMAT
    //Option 1\n: takes you to classical rail fence encryption. If option is not equal to 1 or 2, error displayed and program returns 0.
    //Rail value\n: enter number of rails wanted
    //Message\n: enter message needing to be encrypted
    int x, y, count = 0, q = 0; // declaring x, y, count, q as integers
    length = strlen(message); // set the variable length to the length of the string read
    char code[A][length]; // stating the variable code as a char and giving it the dimensions of [A] and [length]

    for (y=0; y<A; y++){ // applies for all the rows 0 to A-1
        for (x=0; x<length; x++){ // applies for all the column numbers 0 to length-1
            code[y][x] = 0; // setting the initial value of all values of code[y][x] to 0
        }
    }
    //there is now a grid running along 0-length and down 0-A with every value being zero
    x = 0; //reseting x equal to zero
    while (x<length){ // value of x running from 0 to length-1
        if (count%2 == 0){ // if the count is divisible by 2. count is used to switch between going up and down rows
            for (y=0; y<A; y++){ // running for rows 0 to A-1
                code[y][x] = message[x]; // set the location of the char in the string (message) in position y,x
                x++; // increase x by 1
            }
        }
        else{ // the count is not divisible by 2
            for (y=A-2; y>0; y--){ // going up the rows from A-2 to 0
                code[y][x] = message[x]; // set the location of the char in the string (message) in position y,x
                x++; // increase x by 1 going to the next char in the message
            }
        }
        count++;// increase count by 1 to switch between the if and else functions
    }

    printf("\nthis is the encryption:\n");// print to the screen to show that the output is being displayed

    for (y=0; y<A; y++){ // applies for all rows 0 to A-1
        for (x=0; x<length; x++){ // applies for all columns 0 to length-1
            if (code[y][x] != 0){ // if code[y][x] does not equal zero - where the message chars were put
                cipherText[q] = code[y][x]; // set the location of the char in the string (cipherText) in position y,x
                q++; // increase q by 1. q is a counter setting the char number in the string (cipherText)
            }
        }
    }

}

void railFence2(char *message, char *cipherText, int length, int A, int B, int dir)
{
    //FILE FORMAT
    //Option 2\n: Takes you to 2-level rail fence encryption/decryption. If option is not equal to 1 or 2, error displayed and program returns 0.
    //Rail value\n: enter number of rails wanted
    //Peak value\n: Enter value of peak. Must be less than rail value.
    //dir value\n: Decides between encryption and decryption either 0 or 1
    //if dir equals 0
    //message\n: enter message for encryption
    //if dir equals 1. if value is not equal to 1 or 0, error displayed and program returns 0.
    //cipherText\n: enter ciphertext to be decrypted
    int x, y, i = 0, q = 0; //declaring x, y, i, q as integers
    char code[A][length]; // stating the variable code as a char and giving it the dimensions of [A] and [length+10]

    switch(dir){ // using a switch statement which takes the input of dir from the user
        case 0: // when dir equals 0
            for (y=0; y<A; y++){ // applies for all the rows 0 to A-1
                for (x=0; x<length; x++){ // applies for all the column numbers 0 to length-1
                    code[y][x] = 0; // setting the initial value of all values of code[y][x] to 0
                }
            }
            x = 0; // reseting x equal to 0
            while (x < length) { // value of x running from 0 to length-1
                switch (i = 0){ // i represents the stage of encryption deciding what values of code[y][x] are being altered
                    case 0: // when i equals 0. First stage of encryption
                        for (y = 0; y < A; y++){ // running from rows 0 to A-1. going up the rows
                            code[y][x] = message[x]; // set the location of the char in the string (message) in position y,x
                            x++; // increase x by 1 going to the next char in the message
                        }
                    i++; // increase i by 1
                    case 1: // i = 1, second stage in the encryption
                        for (y = A - 2; y > A-B; y--){ // running from rows A-2 to A-B+1. going down the rows
                            code[y][x] = message[x]; // set the location of the char in the string (message) in position y,x
                            x++; // increase x by 1 going to the next char in the message

                        }
                    i++; //increase i by 1
                    case 2: // i = 2, third stage of encryption
                        for (y = A-B; y < A; y++){ // running from row A-B to A-1. going up the rows
                            code[y][x] = message[x]; // set the location of the char in the string (message) in position y,x
                            x++; // increase x by 1 going to the next char in the message
                        }
                    i++; //increase i by 1
                    case 3: // i = 3, fourth stage of encryption
                        for (y=A-2; y>0; y--){ // running from row A-2 to 1. going down the rows
                            code[y][x] = message[x]; // set the location of the char in the string (message) in position y,x
                            x++; // increase x by 1 going to the next char in the message
                        }
                    i = i - 3; // set i back to 0 to restart the cycle in multiple cycles are needed
                }
            }
        printf("this is the encryption:\n"); // print to the screen to show the output is being displayed
        q = 0; // reset q to 0
        for (y=0; y<A; y++){ // applies for all rows 0 to A-1
            for (x=0; x<length; x++){ // applies for all columns 0 to length-1
                if (code[y][x] != 0){ // if code[y][x] does not equal zero - where the message chars were put
                    cipherText[q] = code[y][x]; // set the location of the char in the string (cipherText) in position y,x
                    q++; // increase q by 1. q is a counter setting the char number in the string (cipherText)
                }
            }
        }


            break; // break the switch statement meaning the following cases won't run


    case 1:

            for (y=0; y<A; y++){ // applies for all the rows 0 to A-1
            for (x=0; x<length; x++){ // applies for all the column numbers 0 to length-1
                code[y][x] = 0; // setting the initial value of all values of code[y][x] to 0
            }
        }
   x = 0; // reset x equal to 0
        while (x < length) { // value of x running from 0 to length-1
            switch (i = 0){ // i represents the stage of encryption deciding what values of code[y][x] are being altered
                case 0: // when i equals 0. First stage of encryption
                for (y = 0; y < A; y++){ // running from rows 0 to A-1. going up the rows
                    code[y][x] = '1'; // set the location of the char to a 1 in position y,x
                    x++; // increase x by 1 going to the next column
                }
            i++; // increase i by 1
                case 1: // i = 1, second stage in the encryption
                for (y = A - 2; y > A-B; y--){ // running from rows A-2 to A-B+1. going down the rows
                    code[y][x] = '1'; // set the location of the char to a 1 in position y,x
                    x++;  // increase x by 1 going to the next column

                }
            i++; // increase i by 1
                case 2: // i = 2, third stage of encryption
                for (y = A-B; y < A; y++){
                    code[y][x] = '1'; // set the location of the char to a 1 in position y,x
                    x++; // increase x by 1 going to the next column
                }
            i++;  // increase i by 1
                case 3: // i = 3, fourth stage of encryption
                for (y=A-2; y>0; y--){ // going up the rows as last row has been hit
                    code[y][x] = '1'; // set the location of the char to a 1 in position y,x
                    x++; // increase x by 1 going to the next column
                }
            i = i - 3; // set i back to 0 to restart the cycle in multiple cycles are needed
        }
    }
    q = 0;
        for(y = 0; y < A; y++){
            for(x = 0; x < length; x++){
                if (code[y][x] != 0){
                    code[y][x] = cipherText[q];
                    q++;
                }
            }
        }

    printf("\nthis is the decryption:\n");
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
    FILE *fptr, *fp;
    int A, B, length, dir, option;
    char message[1000000], cipherText[1000000];
    //printf("WELCOME TO THE CIPHER STATION\n");
    //printf("Press 1 for Classical Rail Encryption\n");
    //printf("Press 2 for 2-Level Rail Encryption/Decryption\n");
    scanf("%d\n", &option);
    if(option == 1){
        //printf("\nenter number of rails\n"); // display on the screen to instruct the user
        scanf("%d\n", &A); // assign the users input as A
        //printf("\nenter secret message\n"); // display on the screen to instruct the user
        //setbuf(stdin, NULL);
        fgets(message, sizeof(message), stdin);
        strtok(message, "\n");
        length = strlen(message); // set the variable length to the length of the string read
        fptr = fopen("message.txt", "w");
        fprintf(fptr, message);
        fclose(fptr);
        railfence(message, cipherText, length, A);
        fptr = fopen("cipherText.txt", "w");
        fprintf(fptr, cipherText);
        fptr = fopen("cipherText.txt", "r");
        while(!feof(fptr)){
            fgets(cipherText, sizeof(cipherText), fptr); // read all the characters of the users input as a string rather than individual characters
            puts(cipherText);
        }
        fclose(fptr);
        fptr = fopen("input.txt", "w");
        fprintf(fptr, "option:%d\nrails:%d\nmessage:%s\nlength:%d\nciphertext:%s", option, A, message, length, cipherText);
        fclose(fptr);
    }
    else if(option == 2){
       scanf("%d\n%d\n", &A, &B);
        if(A < B){
            printf("ERROR. A must be bigger than B");
            return 0;
        }
        else{
            scanf("%d\n", &dir);
            if(dir == 0){
                fgets(message, sizeof(message), stdin);
                strtok(message, "\n");
                length = strlen(message);
                fptr = fopen("message.txt", "w");
                fprintf(fptr, message);
                fclose(fptr);
                railFence2(message, cipherText, length, A, B, dir);
                fptr = fopen("cipherText.txt", "w");
                fprintf(fptr, cipherText);
                fptr = fopen("cipherText.txt", "r");
                while(!feof(fptr)){
                    fgets(cipherText, sizeof(cipherText), fptr);
                    puts(cipherText);
                }
                fclose(fptr);
                fptr = fopen("input.txt", "w");
                fprintf(fptr, "option:%d\nrails:%d\npeak:%d\nmessage:%s\nlength:%d\ncipherText:%s", option, A, B, message, length, cipherText);
                fclose(fptr);
            }
            else if(dir == 1){
                fgets(cipherText, sizeof(cipherText), stdin);
                strtok(cipherText, "\n");
                length = strlen(cipherText);
                fptr = fopen("cipherText.txt", "w");
                fprintf(fptr, cipherText);
                fclose(fptr);
                railFence2(message, cipherText, length, A, B, dir);
                fptr = fopen("message.txt", "w");
                fprintf(fptr, message);
                fptr = fopen("message.txt", "r");
                while(!feof(fptr)){
                    fgets(message, sizeof(message), fptr);
                    puts(message);
                }
                fclose(fptr);
                fptr = fopen("input.txt", "w");
                fprintf(fptr, "option:%d\nrails:%d\npeak:%d\ncipherText:%s\nlength:%d\nmessage:%s", option, A, B, cipherText, length, message);
                fclose(fptr);
            }
            else{
                printf("ERROR. Incorrect input. Restart");
                return 0;
            }

        }
    }
    else{
        printf("Incorrect value selected. Restart Program\n");
        return 0;
    }

    return 0;
}
