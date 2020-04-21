#include <stdio.h>
#define MAX_CHAR 70

void getSong(char songTitle[], char songArtist[]);
void displayTitles(char songTitle1[], char songArtist1[], char songTitle2[], char songArtist2[]);
void getstr(char tempString[], int sizeString);
int strlength();
int strcompare(char songArtist1[],char songArtist2[]);
void strconcat(char songTitle1[], char songTitle2[]);

int main()  {
    int strLength;
    char songTitle[MAX_CHAR], songArtist[MAX_CHAR], songTitle1[MAX_CHAR], songArtist1[MAX_CHAR], songTitle2[MAX_CHAR], songArtist2[MAX_CHAR];

    printf("SONG 1\n");
    getSong(songTitle, songArtist);
    for (int count = 0; count != MAX_CHAR; count++)
    {
        songTitle1[count] = songTitle[count]; 
    }
    for (int count = 0; count != MAX_CHAR; count++)
    {
        songArtist1[count] = songArtist[count]; 
    }

    printf("SONG 2\n");
    getSong(songTitle, songArtist);
    for (int count = 0; count != MAX_CHAR; count++)
    {
        songTitle2[count] = songTitle[count]; 
    }
    for (int count = 0; count != MAX_CHAR; count++)
    {
        songArtist2[count] = songArtist[count]; 
    }

    displayTitles(songTitle1, songArtist1, songTitle2, songArtist2);

    return 0;
}

void getSong(char songTitle[], char songArtist[])  {
    int sizeString;
    char tempString[MAX_CHAR]; 
    printf("Please enter your song: ");
    getstr(tempString, sizeString);
    
    for (int count = 0; count != MAX_CHAR; count++)
    {
        songTitle[count] = tempString[count]; 
    }
    printf("Please enter the artist name: ");
    getstr(tempString, sizeString);

    for (int count = 0; count != MAX_CHAR; count++)
    {
        songArtist[count] = tempString[count]; 
    }
    
}

void displayTitles(char songTitle1[], char songArtist1[], char songTitle2[], char songArtist2[])    {
    int order = strcompare(songArtist1, songArtist2);
    char newSong[MAX_CHAR];

    printf("\nPLAYLIST BY ARTIST\n");
    switch (order)
    {
        case 0:
                printf("%s", songTitle1);
                printf("%s\n", songTitle2);
            break;
        case 1:
                printf("%s", songTitle1);
                printf("%s\n", songTitle2);
            break;
        case -1:
                printf("%s", songTitle2);
                printf("%s\n", songTitle1);
            break;
    }

    printf("NEW SONG SUGGESTION\n");
    strconcat(songTitle1, songTitle2);
    printf("%s", songTitle1);
}

void getstr(char tempString[], int sizeString)  {
    char userInput = 0;
    sizeString = 0;
    
    while (userInput != '\n')
    {
        scanf("%c", &userInput);
        tempString[sizeString] = userInput;
        sizeString++;
    }
    tempString[sizeString] = '\0';
    
}

int strlength(char songTitle1[]) {
    int count = 0;
    for (char c; c != '\0'; count++)
    {
        c = songTitle1[count];
    }
    
    return count;
}

int strcompare(char songArtist1[],char songArtist2[])   {
    if (songArtist1[0] > songArtist2[0])
    {
        return -1;
    }
    else if (songArtist1[0] < songArtist2[0])
    {
        return 1;
    }
    else if (songArtist1[0] == songArtist2[0])
    {
        return 0;
    }
    
}

void strconcat(char songTitle1[], char songTitle2[])    {
    int strLength = strlength(songTitle1), count = 0;

    for (strLength -= 2; songTitle2[count] != '\0'; strLength++)
    {
        songTitle1[strLength] = songTitle2[count];
        count++; 
    }
    songTitle1[strLength] = '\0';
}