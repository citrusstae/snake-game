#include <conio.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

 

int i, j,k, Length = 28, width = 28;

int game_over, Score;

int X,Y, foodx, food_y, flag;

 

// Function to generate the food

// within the boundary

void setup()

{

game_over = 0;

 

// Stores Length and width

X = Length / 2;

Y = width / 2;

state1:

foodx = rand() % 20;

if (foodx == 0)

     goto state1;

state2:

food_y = rand() % 20;

if (food_y == 0)

     goto state2;

     

Score = 0;

}

 

// Function to make the boundaries

void Boundary()

{

    system("cls");

for (k = 0; k < Length; k++) {

     for (j = 0; j < width; j++) {

         if (k == 0 || k == width - 1

             || j == 0

             || j == Length - 1) {

                printf("*");

         }

         else {

             if (k==X && k==Y)

                    printf("0");

                else if (k == foodx

                         && j == food_y)

                    printf("#");

                else

                    printf(" ");

         }

     }

        printf("\n");

}

 

// Print the score after the ending of game.

    printf("Score = %d", Score);

    printf("\n");

    printf("Press Q to end the game");

}

 

// Function to take the input

void input()

{

if (kbhit()) {

     switch (getch()) {

     case 'h':

         flag = 1;

         break;

     case 'j':

         flag = 2;

         break;

     case 'k':

         flag = 3;

         break;

     case 'u':

         flag = 4;

         break;

     case 'q':

            game_over = 1;

         break;

     }

}

}

 

// Function for the logic behind

// each and every movement of the snake

void Algorithm()

{

sleep(0.01);

switch (flag) {

case 1:

     Y--;

     break;

    case 2:

     X++;

     break;

case 3:

     Y++;

     break;

case 4:

     X--;

     break;

default:

     break;

}

 

// If the game is over

if (Y < 0 || Y > width || X < 0 || X> Length)

     game_over = 1;

 

// If snake reaches the food

// then update the score

if ((X == foodx) && (Y == food_y)) {

state3:

     foodx = rand() % 20;

     if (foodx == 0)

         goto state3;

 

// After eating the above food

// generate new food

state4:

     food_y = rand() % 20;

     if (food_y == 0)

         goto state4;

         

     Score += 10;

}

}

 

// Driver Code

void main()

{ 

 // Generate boundary

setup();

 

// Until the game is over

while (!game_over) {

 

     // Function Call

     Boundary();

     input();

        Algorithm();

}

}
