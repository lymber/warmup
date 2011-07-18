#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define vecsize 1000000

int main()
{
  int i=0;
  int v[vecsize];

  srand(time(NULL));

  for (i=0; i<=vecsize-1; ++i){
	  v[i]=rand();
  }
  for (i=0; i<=vecsize-1; ++i){
  	  printf("%d\n",v[i]);
  }
  return 0;
}
