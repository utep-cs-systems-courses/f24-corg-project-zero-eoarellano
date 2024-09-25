#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Arrow = t, Square = s, 5x7 Chars = c, 8x12 Chars = e) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected Arrow:");
      print_arrow(4, 7);
      
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected 5x7 chars:");
      for (char c = 'a'; c < 'd'; c++)
	print_char_5x7(c);
      break;
    case 'e' :
      puts("You Selected 8x12 chars:");
      for(char c = 'b'; c < 'e'; c++)
	print_char_8x12(c);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
