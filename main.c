#include <gb/gb.h>
#include <gb/sgb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include <gbdk/console.h>
#include <rand.h>

// joypad scan code:   joypads.joy0 & J_
joypads_t joypads; 

int playerX = 9;
int playerY = 9;
int playerspeed = 1;
int score = 0;
int printed = 0;
int printedscore = 0;
int direction = 1;
int fruitX;
int fruitY;
int fruitspawned = 0;


int randomgetX() {
    fruitX = rand() % 19;
    return(fruitX);
} 
int randomgetY() {
    fruitY = rand() % 19;
    return(fruitY);
}




void main(void)
{
 
    
    
    joypad_init(1, &joypads);
    while(1) {


        joypad_ex(&joypads);
        //printf("%d", r);
        
        //edge collision
        if (playerY >= 20) {
            playerY = 0;
        }
        if (playerY <= -1) {
            playerY = 19;
        }
        if (playerX >= 19) {
            playerX = 0;
        }
        if (playerX <= -1) {
            playerX = 19;
        }

        //direction movement
        if (direction == 1) {
            playerY += 1;
            cls();
            printed = 0;
        }
        if (direction == 2) {
            playerY -= 1;
            cls();
            printed = 0;
        }
        if (direction == 3) {
            playerX += 1;
            cls();
            printed = 0;
        }
        if (direction == 4) {
            playerX -= 1;
            cls();
            printed = 0;
        }
        printf("%d", score);
        //print
        if (printed == 0) {
            gotoxy(playerX, playerY);
            printf("@");
            printed = 1;
        }

        if (fruitspawned == 0) {
            fruitX = randomgetX();
            fruitY = randomgetY();
            gotoxy(fruitX, fruitY);
            printf("A");
            fruitspawned = 1;
            
        }
        gotoxy(fruitX, fruitY);
        printf("A");

        //check if player is touching fruit
        if (playerX == fruitX && playerY == fruitY) {
            score += 1;
            fruitX = randomgetX();
            fruitY = randomgetY();
        }

        //controls
        if (joypads.joy0 & J_DOWN) {
            direction = 1;

        }
        if (joypads.joy0 & J_UP) {
            direction = 2;

        }
        if (joypads.joy0 & J_LEFT) {
            direction = 4;

        }
        if (joypads.joy0 & J_RIGHT) {
            direction = 3;
        }
        
 




        
        wait_vbl_done();
    }
}
