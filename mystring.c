#include <stdio.h>
#include <string.h>

int str_wc(char *s) {//function that takes pointer the char type string and counts number of words
    int length = 0;//declaring a counter that increments when a word is counter
    int i=0;//declaring counter that tracks array element number

    if(s[i] != '\0') {//if string at i is not null character
        if(s[0] != ' ') {//this if statement deals with the first word. if first element is not a space character
            if ((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z')) {//and if first element is a letter character
                length++;//increments length counter to indicate a word
            }
        }
            for (i = 1; s[i] != '\0'; i++) {//loop that runs from second string element until the null character
                if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {//checks if string at i is a letter character
                    if (s[i-1] == ' ') {//if string at i is a letter character and character before i is a space there is a word
                        length++;//increments length counter to indicate a word
                    }
                }
            }
    }
    return length;//returns int counter value for length
}

int str_lower(char *s) {//function that changes all string s letters to lower case
    int i=0;//declares int type counter i
    while(s[i] != '\0') {//loop runs until null character is encountered
        if(s[i] >= 'A' && s[i] <= 'Z') {//if character is uppercase
            s[i]=s[i]+32;//changes uppercase letter at i to lower case by adding 32
        }
        i++;//increments counter
    }
    return 0;//returns nothing as the function is void
}

void str_trim(char *s) {//void type function that takes a pointer to string s and trims it of unnecessary spaces
    int i = 0, j = 0;//declares counter variables

    while (s[i] == ' ') {//while loop for when the first element is a space ' '
        i++;//increments counter to remove leading space
    }

    while (s[i] != '\0') {//checks that string at element i is not the null character
        if (s[i] != ' ' || (j > 0 && s[j - 1] != ' ')) {//loop for if string at i is not a space, or if it is a space and the previous character is not a space
            s[j++] = s[i];//shifts elements from j+1 into the space of i (shifts left where spaces are encountered)
        }
        i++;//increments counter
    }


    if (j > 0 && s[j - 1] == ' ') {//if last character is a space
        j--;//decrement to remove trailing space
    }
    s[j] = '\0';//null terminates the string at decremented j
}
