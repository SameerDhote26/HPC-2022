#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;
#define N 500

int main()
{
    int A[N];
    for (int i = 0; i < N; i++)
        A[i] = 10;

    int B[N];
    for (int i = 0; i < N; i++)
        B[i] = 20;

    int C[N] = {0};
    double stime = omp_get_wtime();
    int i;
#pragma omp parallel for
    for (i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
        printf("Index: %d Thread: %d\n", i, omp_get_thread_num());
    }
    cout << endl;
    for (i = 0; i < N; i++)
    {
        printf(" %d ", C[i]);
    }
    double etime = omp_get_wtime();
    double time = etime - stime;
    cout << "\nTime taken: " << time;
    return 0;
}