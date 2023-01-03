#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define LENGTH 4


int pos = 0;
int nothing = 0;
int correct = 0;
int tries = 0;
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int max_guesses;

int a[LENGTH];
int b[LENGTH];
int input_num[LENGTH];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void generate();
void player_guess();
void game();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void game()
{
  tries= 0;
  char name[30];
  printf("Enter Name to Begin Game : ");
  scanf("%s",name);
  printf("\n\n");
  printf("=========================================================================================================================\n");
  printf("\n                                        Hi %s",name);
  printf(", Welcome to Mastermind\n");
  printf("\n=========================================================================================================================\n");
  printf("\n                                                                                                                       \n");
  printf("\n   * Enter name to begin game                                                                                          \n");
 // printf("   * Enter 0000 to stop playing the game                                                                                 \n");
  printf("   * Each digt input has to be between 1 and 9 for a valid input                                                         \n");
  printf("\n                                           Attempt no.            Guess           Result                               \n");
  printf("-------------------------------------------------------------------------------------------------------------------------\n");

  generate();

   while (tries < max_guesses)
   {
    correct = 0;
    pos = 0;
    while (tries < max_guesses) {
    correct = 0;
    pos = 0;
    int result[4] = {0};

    player_guess();

    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
      printf("Congratulations!!! You have won the game\n");
      tries = max_guesses;
    } else if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
        {
            tries = max_guesses;
        }
        else {
        tries++;

      // Check how many digits are correct and how many are in the correct position
      for (int i = 0; i < 4; i++)
      {
        if (a[i] == b[i])
        {
          correct++;
        }
        else if (b[i] == a[0] || b[i] == a[1] || b[i] == a[2] || b[i] == a[3])
        {
          pos++;
        }
      }
      for (int i = 0; i < correct; i++) {
        result[i] = 1;
      }

      // Append the number of digits in the correct position to the result array
      for (int i = correct; i < correct + pos; i++) {
        result[i] = 2;
      }

      // Print the attempt number, player's guess, and result array
      printf("                                            %d                     ", tries);
      for (int n = 0;n <4 ; n++)
      {
        printf("%d",b[n]);
      }
      printf("            ");
      for (int i = 0; i < 4; i++) {
        if (result[i] == 1) {
          printf("1");
        } else if (result[i] == 2) {
          printf("0");
        } else {
          printf(".");
        }
      }
      printf("            ");
      printf("\n");
    }
  }
  return ;
}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void player_guess() {
  while (1) {
    printf("Guess a 4 digit number: ");
    scanf("%i", input_num);
    b[0] = *input_num / 1000;
    b[1] = *input_num / 100 % 10;
    b[2] = *input_num / 10 % 10;
    b[3] = *input_num % 10;

    // Validates the player's input
    if (*input_num < 0 || *input_num > 9999) {
      printf("\nInvalid input, please enter a valid guess\n\n");
      continue;
    }
    break;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void generate() {
  n1 = rand() % 9 + 1;
  n2 = rand() % 9 + 1;
  n3 = rand() % 9 + 1;
  n4 = rand() % 9 + 1;
  a[0] = n1;
  a[1] = n2;
  a[2] = n3;
  a[3] = n4;
  //printf("%d%d%d%d",n1,n2,n3,n4);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    int result = 0;


  // check if the user provided the maximum number of guesses as a command line argument
  if (argc < 2) {
    printf("Error: missing argument for maximum number of guesses. Usage : ./project {number of attempts}\n");
    return 1;
  }

  // parse the maximum number of guesses from the command line argument
  max_guesses = atoi(argv[1]);

  game();

  if (tries == max_guesses) {
    printf("\nNice try the number was : ");
    for (int m = 0; m < 4 ; m++)
    {
      printf("%d",a[m]);
    }
  }

  while (1) {
    char again[4];

    printf("\nDo you want to play another game (yes/no) ");
    scanf("%s", again);

    if (strcmp(again, "y") == 0 || strcmp(again, "yes") == 0) {
      printf("=========================================================================================================================\n");
      printf("\n                                                     New Game                                                        \n");
      printf("=========================================================================================================================\n");
      game();
      if (tries == max_guesses) {
        printf("\n\n                                  Nice try the number was : ");
        for (int m = 0; m < 4 ; m++)
    {
      printf("%d",a[m]);
    }
      }
      continue;
    } else if (strcmp(again, "n") == 0 || strcmp(again, "no") == 0) {
      printf("=========================================================================================================================\n");
      printf("\n                                                     Goodbye                                                         \n");
      printf("=========================================================================================================================\n");
      break;
    } else {
      printf("\nInvalid Input\n");
      continue;
    }
  }


}