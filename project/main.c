// Miguel Carlo Kua, Angelo Yanto Quinones S11

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 1073741824 // 2^30

extern double dotProduct86(double* A, double* B, int n);

clock_t start, end;

void popuArr(float vectorA[], float vectorB[]) {

    // Fill vectorA and vectorB with numbers from 0 to 2^30
    for (int i = 0; i < ARRAY_SIZE; i++) {
        vectorA[i] = (float)(i);
        vectorB[i] = (float)(i);
    }
}

float dotProduct(int n, float A[], float B[]) {
    //start time
    start = clock();

    //temporarily hold the product each iteration
    float holder0 = 0;
    float holder1 = 0;
    for (int x = 0; x < n; x++) {
        holder0 = A[x] * B[x];
        holder1 = holder1 + holder0;
    }

    //end time
    end = clock();
    //return the answer for the computation
    return holder1;
}

static void tellTime(double time) {
    //calculate the time taken
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    //print the time taken
    printf("Time Taken By the Kernel: %f seconds\n", time);
}

static void printCdisplay() {
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("Dot Product Using C Kernel\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
}

static void print86display() {
    printf("\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("Dot Product Using x86_64 Assembly Kernel\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
}

int main(int argc, char* argv[]) {
    double time = 0;
    float* vectorA = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* vectorB = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float sdot = 0;
    int n = 0;
    //create the values
    popuArr(vectorA, vectorB);

    int nPow = 0;
    printf("Enter a number: ");
    scanf_s("%d", &nPow);

    printCdisplay();
    //Compute dot product set at n=2^20 using C kernel
    n = pow(2, nPow);
    sdot = dotProduct(n, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=2^24 using C kernel
    n = pow(2, nPow + 4);
    sdot = dotProduct(n, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=2^30 using C kernel
    n = pow(2, nPow + 10);
    sdot = dotProduct(n, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    print86display();
    //Compute dot product set at n=2^20 using x86_64 Assembly kernel
    n = pow(2, nPow);
    start = clock();
    sdot = dotProduct86(vectorA, vectorB, n);
    end = clock();
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=2^24 using x86_64 Assembly kernel
    n = pow(2, nPow + 4);
    start = clock();
    sdot = dotProduct86(vectorA, vectorB, n);
    end = clock();
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=2^30 using x86_64 Assembly kernel
    n = pow(2, nPow + 10);
    start = clock();
    sdot = dotProduct86(vectorA, vectorB, n);
    end = clock();
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    return 0;

}