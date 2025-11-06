#include <iostream>
using namespace std;

// 1 a) Selection sort
void selectionSort(int arr[], int n)
{
        for (int i = 0; i < n - 1; i++)
        {
                int minIndex = i;
                for (int j = i + 1; j < n; j++)
                        if (arr[j] < arr[minIndex])
                                minIndex = j;
                swap(arr[i], arr[minIndex]);
        }
}

//  1 b) Insertion sort
void insertionSort(int arr[], int n)
{
        for (int i = 1; i < n; i++)
        {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                        arr[j + 1] = arr[j];
                        j--;
                }
                arr[j + 1] = key;
        }
}

// 1 c) Bubble sort
void bubbleSort(int arr[], int n)
{
        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                {
                        if (arr[j] > arr[j + 1])
                                swap(arr[j], arr[j + 1]);
                }
        }
}

// 1 d) Merge sort
void merge(int arr[], int left, int mid, int right)
{
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)
                L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
                if (L[i] <= R[j])
                        arr[k++] = L[i++];
                else
                        arr[k++] = R[j++];
        }

        while (i < n1)
                arr[k++] = L[i++];
        while (j < n2)
                arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
        if (left < right)
        {
                int mid = left + (right - left) / 2;
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);
                merge(arr, left, mid, right);
        }
}

// 1e) Quick sort
int partition(int arr[], int low, int high)
{
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++)
        {
                if (arr[j] < pivot)
                {
                        i++;
                        swap(arr[i], arr[j]);
                }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
        if (low < high)
        {
                int pi = partition(arr, low, high);
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
        }
}

// Print array
void printArray(int arr[], int n)
{
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        cout << endl;
}

// Main
int main()
{
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        int arr[n];

        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++)
                cin >> arr[i];

        cout << "\nChoose Sorting Algorithm:\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
                selectionSort(arr, n);
                cout << "\nArray after Selection Sort: ";
                break;
        case 2:
                insertionSort(arr, n);
                cout << "\nArray after Insertion Sort: ";
                break;
        case 3:
                bubbleSort(arr, n);
                cout << "\nArray after Bubble Sort: ";
                break;
        case 4:
                mergeSort(arr, 0, n - 1);
                cout << "\nArray after Merge Sort: ";
                break;
        case 5:
                quickSort(arr, 0, n - 1);
                cout << "\nArray after Quick Sort: ";
                break;
        default:
                cout << "\nInvalid choice!";
                return 0;
        }

        printArray(arr, n);
        return 0;
}
