#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

void sort(vector<int> arr, int n)
{
    int i, j;
#pragma omp parallel for
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                cout << "i=" << i << " j=" << j << " Thread No: " << omp_get_thread_num() << endl;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sort_des(vector<int> arr, int n)
{
    int i, j;
#pragma omp parallel for
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            cout << "i=" << i << " j=" << j << " Thread No: " << omp_get_thread_num() << endl;
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}
int main()
{
    // fill the code;
    int n;
    scanf("%d", &n);
    vector<int> arr1(n), arr2(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    sort(arr1, n);
    sort_des(arr2, n);
    int sum = 0;
    cout << endl;
    for (i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for (i = 0; i < n; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    printf("%d", sum);
    return 0;
}