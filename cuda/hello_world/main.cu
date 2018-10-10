#include <cstdlib>
#include <cstdio>
#include <cuda.h>

using namespace std;

const int N = 16;
const int blockSize = 16;

__global__ 
void mykernel(char *a, int *b) {
	a[threadIdx.x] += b[threadIdx.x];
}


int main(void) {
  char a[N] = "Hello \0\0\0\0\0\0";
  int b[N] = {15, 10, 6, 0, -11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   
  char *ad;
  int *bd;

  const int csize = N * sizeof(char);
  const int isize = N * sizeof(char);

  printf("%s", a);

  cudaMalloc( (void**)&ad, csize );
  cudaMalloc( (void**)&bd, isize);

  cudaMemcpy(ad, a, csize, cudaMemcpyHostToDevice);
  cudaMemcpy(bd, b, isize, cudaMemcpyHostToDevice);

  dim3 dimBlock( blockSize, 1 );
  dim3 dimGrid( 1, 1 );
  mykernel<<<dimGrid, dimBlock>>>(ad, bd);
  cudaMemcpy( a, ad, csize, cudaMemcpyDeviceToHost ); 
  cudaFree( ad );
  cudaFree( bd );

  printf("%s\n", a);
  return 0;
} 
