// 56. Write a program to simulate music player application using suitable data structure.
// There is no estimation about number of music files to be managed by the music player.
// Your program should support all the basic music player operations to play and manage the playlist.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char song[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void addSong()
{
    struct Node *newNode;
    char name[100];

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter song name: ");
    scanf(" %[^\n]", name);

    strcpy(newNode->song, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        current = head;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteSong()
{
    char name[100];
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("Enter song name to delete: ");
    scanf(" %[^\n]", name);

    while (temp != NULL && strcmp(temp->song, name) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Song not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    free(temp);
}

void displayPlaylist()
{
    struct Node *temp = head;
    int i = 1;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n----- PLAYLIST -----\n");

    while (temp != NULL)
    {
        if (temp == current)
            printf("%d. %s  <-- Currently Playing\n", i, temp->song);
        else
            printf("%d. %s\n", i, temp->song);

        temp = temp->next;
        i++;
    }
}

void playSong()
{
    if (current == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("Now Playing: %s\n", current->song);
}

void nextSong()
{
    if (current == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    if (current->next != NULL)
    {
        current = current->next;
        printf("Now Playing: %s\n", current->song);
    }
    else
    {
        printf("This is the last song.\n");
    }
}

void previousSong()
{
    if (current == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    if (current->prev != NULL)
    {
        current = current->prev;
        printf("Now Playing: %s\n", current->song);
    }
    else
    {
        printf("This is the first song.\n");
    }
}

void searchSong()
{
    char name[100];
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("Enter song name to search: ");
    scanf(" %[^\n]", name);

    while (temp != NULL)
    {
        if (strcmp(temp->song, name) == 0)
        {
            printf("Song found: %s\n", temp->song);
            return;
        }

        temp = temp->next;
    }

    printf("Song not found.\n");
}

void main()
{
    int choice;

    do
    {
        printf("\n---------- MUSIC PLAYER ----------\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Current Song\n");
        printf("5. Play Next Song\n");
        printf("6. Play Previous Song\n");
        printf("7. Search Song\n");
        printf("8. Exit\n");
        printf("----------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSong();
            break;
        case 2:
            deleteSong();
            break;
        case 3:
            displayPlaylist();
            break;
        case 4:
            playSong();
            break;
        case 5:
            nextSong();
            break;
        case 6:
            previousSong();
            break;
        case 7:
            searchSong();
            break;
        case 8:
            printf("Exiting Music Player...\n");
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);
}