#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(0));

    int highScore = 0;

    FILE *hf = fopen("score.txt", "r");
    if (hf) {
        if (fscanf(hf, "%d", &highScore) != 1) highScore = 0;
        fclose(hf);
    }

    char play = 'R';

    while (play == 'R' || play == 'r') {

        int basket = 1;          // 0 = left, 1 = mid, 2 = right
        int fruit = rand() % 3;  // random lane
        int step = 0;
        int score = 0;
        int misses = 0;

        int running = 1;

        while (running == 1) {

            // INPUT (Only arrow keys now)
            if (_kbhit()) {
                int ch = _getch();

                if (ch == 0 || ch == 224) {        // arrow key prefix
                    int key = _getch();
                    if (key == 75 && basket > 0) basket--;   // left arrow
                    if (key == 77 && basket < 2) basket++;   // right arrow
                } 
                else if (ch == 'q' || ch == 'Q') {
                    running = 0;  // quit
                }
            }

            // DRAW SCREEN
            system("cls");
            printf("Fruit Catcher   Score: %d   High: %d   Misses left: %d\n",
                   score, highScore, 3 - misses);
            printf("|--- --- ---|\n");

            for (int i = 0; i < 10; i++) {
                if (i == step) {
                    if (fruit == 0) printf("| F        |\n");
                    else if (fruit == 1) printf("|    F     |\n");
                    else printf("|        F |\n");
                } else {
                    printf("|          |\n");
                }
            }

            // Basket
            if (basket == 0) printf("| [ ]      |\n");
            else if (basket == 1) printf("|    [ ]   |\n");
            else printf("|      [ ] |\n");

            // GAME LOGIC
            if (step == 9) {
                if (fruit == basket) {
                    score++;
                    fruit = rand() % 3;
                    step = 0;
                } else {
                    misses++;

                    if (misses >= 3) {
                        printf("\nGAME OVER! Final Score: %d\n", score);

                        if (score > highScore) {
                            highScore = score;
                            FILE *wf = fopen("score.txt", "w");
                            if (wf) {
                                fprintf(wf, "%d", highScore);
                                fclose(wf);
                            }
                            printf("New High Score: %d\n", highScore);
                        }
                        running = 0;
                    } else {
                        printf("\nMissed! Misses left: %d\n", 3 - misses);
                        Sleep(600);
                        fruit = rand() % 3;
                        step = 0;
                    }
                }
            } else {
                step++;
            }

            Sleep(150);
        }

        // Restart or Quit
        printf("\nPress R to Restart or Q to Quit\n");
        while (1) {
            int c = _getch();
            if (c == 'R' || c == 'r') { play = 'R'; break; }
            if (c == 'Q' || c == 'q') { play = 'Q'; break; }
        }
    }

    return 0;
}
