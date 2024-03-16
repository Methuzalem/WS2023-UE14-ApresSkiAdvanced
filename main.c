/* DO NOT TOUCH */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 5

void printTitle(int);

typedef struct Song {
    int id;
    int duration;
    int play_count;
} Song;

/* YOUR CODE STARTS HERE */
void printSong(Song song){

    int minuten = 0;

        printf("ID: %d", song.id);
        printf("\nTitle: ");
        printTitle(song.id);

            while(song.duration >= 60){
                song.duration = song.duration - 60;
                minuten++;
            }

        printf("\nDuration: %02d:%02d", minuten, song.duration);

        printf("\nPlayed today: %d\n\n", song.play_count);


}

void printTopFive(Song songs[MAX_LENGTH]){

    for(int i = 1; i < 6; i++){
        printf("### %d ###\n", i);

        printSong(songs[i-1]);
    }

}

void playSong(Song songs[MAX_LENGTH], int position){

        if(songs[position-1].play_count < 5){
            printTitle(position);
            printf(" will be played next.\n");
            songs[position-1].play_count++;
        }else{
            printTitle(position);
            printf(" was played too often today...\n");
            printf("Play another song!\n");
        }
}

void printUnplayedSongs(Song songs[MAX_LENGTH]){

    int minuten[5] = {0, 0, 0, 0, 0};
    int sekunden[5] = {0, 0, 0, 0, 0};
    int duration = 0;



    for(int i = 0; i < 5; i++){
        if(songs[i].play_count == 0){
                printf("ID: %d", songs[i].id);
                printf("\nTitle: ");
                printTitle(songs[i].id);

                    if(songs[i].duration >= 60){
                        duration = songs[i].duration;
                            while(duration > 60){
                                duration = duration - 60;
                                minuten[i]++;
                                sekunden[i] = duration;
                            }
                    }

        printf("\nDuration: %02d:%02d", minuten[i], sekunden[i]);

        printf("\nPlayed today: %d\n\n", songs[i].play_count);
        }

}
}
void addNewSongToTopFive(Song songs[MAX_LENGTH], Song song, int position){

    songs[position-1].id = song.id;

    songs[position-1].duration = song.duration;

    songs[position-1].play_count = 0;
}

void exchangePosition(Song songs[MAX_LENGTH], int positionSong1, int positionSong2){

int tempID = 0;
int tempDUR = 0;
int tempCOU = 0;

    tempID = songs[positionSong1-1].id;

    tempDUR = songs[positionSong1-1].duration;

    tempCOU = songs[positionSong1-1].play_count;

    songs[positionSong1-1].id = songs[positionSong2-1].id;

    songs[positionSong1-1].duration = songs[positionSong2-1].duration;

    songs[positionSong1-1].play_count = songs[positionSong2-1].play_count;

    songs[positionSong2-1].id = tempID;

    songs[positionSong2-1].duration = tempDUR;

    songs[positionSong2-1].play_count = tempCOU;


}



/* DO NOT TOUCH */
int main(void) {
    Song songs[5] = {
        {1, 220, 0},
        {2, 216, 0},
        {3, 194, 0},
        {4, 180, 5},
        {5, 211, 0}
    };
    Song song;

    int option = 0;
    int position1 = 0;
    int position2 = 0;

    do {
        printf("------------\n");
        printf("1 = Display song\n");
        printf("2 = Display current Top 5 hits\n");
        printf("3 = Play song\n");
        printf("4 = Display songs, that haven't been played\n");
        printf("5 = Add new song\n");
        printf("6 = Swap position of 2 songs\n");
        printf("-1 = Exit program\n");
        printf("------------\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Position: ");
                scanf("%d", &position1);
                if (position1 > 0 && position1 <= MAX_LENGTH) {
                    printSong(songs[position1-1]);
                }
                break;
            case 2:
                printTopFive(songs);
                break;
            case 3:
                printf("Position: ");
                scanf("%d", &position1);
                if (position1 > 0 && position1 <= MAX_LENGTH) {
                    playSong(songs, position1);
                }
                break;
            case 4:
                printUnplayedSongs(songs);
                break;
            case 5:
                printf("Position: ");
                scanf("%d", &position1);
                printf("ID: ");
                scanf("%d", &song.id);
                printf("Duration (in seconds): ");
                scanf("%d", &song.duration);
                song.play_count = 0;

                if (position1 > 0 && position1 <= MAX_LENGTH) {
                    addNewSongToTopFive(songs, song, position1);
                }
                break;
            case 6:
                printf("Position Song 1: ");
                scanf("%d", &position1);
                printf("Position Song 2: ");
                scanf("%d", &position2);
                if (position1 > 0 && position1 <= MAX_LENGTH && position2 > 0 && position2 <= MAX_LENGTH) {
                    exchangePosition(songs, position1, position2);
                }
                break;
        }
    } while (option != -1);

    return 0;
}

void printTitle(int id)
{
    printf("\"");
    switch (id) {
        case 1:
            printf("Atemlos durch die Nacht");
            break;
        case 2:
            printf("Mama Laudaaa");
            break;
        case 3:
            printf("Das rote Pferd");
            break;
        case 4:
            printf("Hulapalu");
            break;
        case 5:
            printf("Die immer lacht");
            break;
        default:
            printf("(New release)");
            break;
    }
    printf("\"");
}
