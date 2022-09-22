#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;
#define N 500

int main()
{
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        v[i] = 26;
    int i = 0;
    int scalar = 4;
    double stime = omp_get_wtime();
#pragma omp parallel for
    for (i = 0; i < N; i++)
    {
        v[i] = v[i] + scalar;
    }

    for (i = 0; i < N; i++)
        cout << v[i] << " ";

    double etime = omp_get_wtime();
    double time = etime - stime;
    cout << "\nTime taken : " << time;
    return 0;
}