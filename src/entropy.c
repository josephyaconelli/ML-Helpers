#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int outOf;


double calcPercent(int count) {
  double percent;
  
  percent = (double) count / outOf;
   
  return percent;  
}

double calcEntropy(double** likelihoods, int count) {

  int i;
  double temp, temp2, _log, _log2;
  double entropy = 0;
  double likelihood;
  double likelihood2;
  double percentOfTotal;
  double percentOfMatch;
  double total;
  for(i = 0; i < count; i+=2) {
    likelihood = (*likelihoods)[i];
    likelihood2 = (*likelihoods)[i+1];
    percentOfTotal = likelihood + likelihood2;
    total = (outOf*percentOfTotal);
    _log = likelihood != 0 ? log2((double) (likelihood*outOf)/total) : .5;
    _log2 = likelihood2 != 0 ? log2((double) (likelihood2*outOf)/total) : .5;
    temp = -((likelihood*outOf)/total * _log);
    temp2 = -((likelihood2*outOf)/total * _log2);
    

    entropy += percentOfTotal*(temp + temp2);
    
  }


  return entropy;

}

int main(int argc, char** argv) {

  int i;
  double* likelihoods = (double*) malloc((argc-2)*sizeof(double));

  outOf = atoi(argv[1]);
  

  for(i = 2; i < argc; i++) {
    likelihoods[i - 2] = calcPercent(atoi(argv[i]));
  }

  printf("%f\n", calcEntropy(&likelihoods, argc-2));

 

  return 0;

}




