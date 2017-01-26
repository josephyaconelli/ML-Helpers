#include <stdio.h>
#include <stdlib.h>







int main(int argc, char** argv) {

  int i;
  double temp;
  double infoGain;
  double oldEntropy;
  sscanf(argv[1], "%lf", &oldEntropy);
  infoGain = oldEntropy;
  for(i = 2; i < argc; i++) {
    sscanf(argv[i], "%lf", &temp);
    infoGain -= temp;
  }

  printf("%f\n", infoGain);

  return 0;
}
