#include <bits/stdc++.h>
using namespace std;

/*Function to get gcd of a and b*/
int gcd(int a, int b) // gcd(a,b) number of blocks are formed
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

/*Function to left rotate array by n - number of rotations*/
void array_left_rotate(int arr[], int d, int n)
{
    int i, j, k, temp;
    for (i = 0; i < gcd(d, n); i++) // gcd(d,n) times the loop will iterate
    {

        /* move i-th values of blocks */
        temp = arr[i];
        j = i;
        while (1)
        {
            k = j + d;
            if (k >= n) // The element has to be shifted to its rotated position
                k = k - n;
            if (k == i) // The element is already in its rotated position
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]); // Finding the size of the array
    cout << "\nArray elements before rotating : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t"; // Printing the array elements
    }
    int no_of_rotations = 2; // Number of rotations to take place
    array_left_rotate(arr, no_of_rotations, n);
    cout << "\n\nArray elements after rotating : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t"; // Printing the array elements after rotation of elements
    }
    cout << "\n";
    return 0;
}