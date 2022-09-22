#include <iostream>
#include <omp.h>
#include <iomanip>
using namespace std;

#define N 200

int main()
{
    int *v = new int[N];
    int *sum = new int[N];

    int scalar = 10;
    int i;
    for (i = 0; i < N; i++)
        v[i] = 1;

    double stime, etime;
    stime = omp_get_wtime();

    for (i = 0; i < N; i++)
    {
        sum[i] = v[i] + scalar;
        cout << sum[i] << " ";
    }
    etime = omp_get_wtime();

    // for (i = 0; i < N; i++)
    //     printf("%d ", v[i]);
    double time_taken = (etime - stime);
    cout << "\nTime Taken: " << setprecision(10) << time_taken;
    return 0;
}
