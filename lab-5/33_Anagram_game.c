// 33. Design anagram game using array.
// - Allow a user to enter N words and store it in an array.
// - Generate a random number between 0 to N-1.
// - Based on the random number generated display the word stored at that index of an array and allow user to enter its anagram.
// - Check whether the word entered by the user is an anagram of displayed number or not and display an appropriate message.
// - Given a word A and word B. B is said to be an anagram of A if and only if the characters present in B is same as characters present in A, irrespective of their sequence. For ex: “LISTEN” == “SILENT”


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sortstr(char str[]){
    int length = strlen(str);
    char temp;

    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void main(){
    int n;
    printf("enter n :");
    scanf("%d",&n);

    char word[n][100];

    for (int i = 0; i < n; i++)
    {
        printf("enter word %d : ",i);
        scanf("%s",word[i]);
    }

    srand(time(NULL));
    int index = rand()%n;
    char user[100];

    printf("\nWord : %s",word[index]);

    printf("\nenter any word : ");
    scanf("%s",user);

    sortstr(word[index]);
    sortstr(user);

    if (strcmp(word[index],user)==0)
        printf("\nIt's anagram word");
    else
        printf("\nIt's not anagram word");
}