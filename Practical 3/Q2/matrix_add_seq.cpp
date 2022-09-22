#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip>
using namespace std;
#define M 1000
#define N 1000
int main()
{
    int **m1 = new int *[M];
    int **m2 = new int *[M];
    int **sum = new int *[M];

    for (int i = 0; i < M; i++)
    {
        m1[i] = new int[N];
        m2[i] = new int[N];
        sum[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m1[i][j] = 10;
            m2[i][j] = 20;
        }
    }

    int i, j;
    double stime = omp_get_wtime();
    // cout << setprecision(20) << stime << endl;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }
    double etime = omp_get_wtime();
    double time = etime - stime;
    // cout << setprecision(20) << etime << endl;
    cout << "\nTime taken: " << setprecision(10) << time;
    return 0;
}