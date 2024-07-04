#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int heads = 0;
int tails = 0;

void toss() {
  static int round = 1;
  double random = (double)rand() / RAND_MAX;
  if (random > 0.5) {
    printf("Round %d: Heads\n", round);
    heads++;
  } else {
    printf("Round %d: Tails\n", round);
    tails++;
  }
  round++;
}

int main() {
  printf("TOssing a coin...\n");
  
  srand(time(NULL) * getpid());
  
  
  toss();
  toss();
  toss();
  printf("Heads: %d, Tails: %d\n", heads, tails);
  
  if (heads > tails) {
    printf("You won\n");
  } else {
    printf("You lost\n");
  }
  
  return 0; 
}
