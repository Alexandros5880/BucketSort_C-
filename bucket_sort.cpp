#include <vector>
#include <algorithm>
#include <math.h> 
#include <iostream>
using namespace std;

void min_max(int arr[], int &n, int * min, int * max)
{
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}
 

void bucketSort(int arr[], int n)
{
    // 1). Find Min and Max values
    int min_val;
    int max_val;
    min_max(arr, n, &min_val, &max_val);
    // 2). Get The value increase of every bucket (max_value / array_length)
    int value_increase = max_val/n;
    // 3). Grab the values (start/stop value of every bucket)
    int values[n*2];
    int value = min_val;
    for (int i = 0; i < (n*2); i++) {
        if(i > 0) {
            if (i%2 == 0) {
                value++;
            } else {
                value += value_increase;
            }
            values[i] = value;
        } else {
            values[i] = min_val;
        }
    }
    // 4). Create n empty buckets wigth lwngth of the list
    vector<int> bucket[n];
    // 5). Put array elements in the right buckets
    for (int i = 0; i < n; i++) {  // values[i]

        for (int j=0; j<n*2; j++) {
            if(j%2 != 0) {
                if( arr[i] >= values[j-1] && arr[i] <= values[j]) {
                    bucket[j/2].push_back(arr[i]);
                }
            }
        }
    }
    // 6). Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    // 7). Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }
}
 


int main() {
    //float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.345, 0.222, 0.111, 0.234 };
    int arr[] = { 11, 77, 7, 3, 33, 17, 90, 100, 1, 50, 32, 31, 57, 77, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}