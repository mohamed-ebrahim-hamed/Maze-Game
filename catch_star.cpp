#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int basketX = 300, basketY = 400;
    int starX, starY = 0;
    int score = 0;
    char key;

    srand(time(0));
    starX = rand() % 640; // Random horizontal position

    while (1) {
        cleardevice();

        // Draw basket
        setfillstyle(SOLID_FILL, BLUE);
        bar(basketX, basketY, basketX + 80, basketY + 20);

        // Draw star
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(starX, starY, 10, 10);

        // Display score
        setcolor(WHITE);
        outtextxy(10, 10, "Score:");
        char sc[10];
        sprintf(sc, "%d", score);
        outtextxy(60, 10, sc);

        delay(30);
        starY += 5; // Star falls

        // Check key press
        if (kbhit()) {
            key = getch();
            if (key == 27) break; // ESC to exit
            if (key == 'a' && basketX > 0) basketX -= 20;
            if (key == 'd' && basketX < 560) basketX += 20;
        }

        // Check if star caught
        if (starY >= basketY && starY <= basketY + 20 && starX >= basketX && starX <= basketX + 80) {
            score++;
            starY = 0;
            starX = rand() % 640;
        }

        // Reset star if it falls off screen
        if (starY > getmaxy()) {
            starY = 0;
            starX = rand() % 640;
        }
    }

    closegraph();
    return 0;
}
