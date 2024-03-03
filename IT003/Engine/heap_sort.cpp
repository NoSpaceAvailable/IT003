#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace std::chrono;

void heapify(double arr[], int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
    // left = 2*i + 1
    int l = 2 * i + 1;
    // right = 2*i + 2
    int r = 2 * i + 2;
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}
 
void heap_sort(double arr[], int N)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    // One by one extract an element from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

string get_file_name(int fd){
    string filename = (string)"../TestCase/random_case" + to_string(fd) + (string)".txt";
    return filename;
}

int main(){

    cout << "[Heapsort] Heapsort engine starting ...\n";
    double *array = new double[sizeof(double) * 1000000];
    cout << fixed << setprecision(15);

    for (int fd = 1; fd < 11; ++fd){
        string filename = get_file_name(fd);
        ifstream testcase(filename); //read

        if (testcase.is_open()){

            for (int j = 0; j < 1000000; ++j){
                testcase >> array[j];
            }

            auto begin = high_resolution_clock::now();
            heap_sort(array, 1000000);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - begin);
            cout << "[Heapsort] Testcase no." << fd << " took " << duration.count() << " ms\n";
        }

        else{
            cout << "[Heapsort] Error occured! Can't open random_case" << fd << ".txt" << ". Aborting ...\n";
            return 0;
        }

    }

    cout << "[Heapsort] Task completed!\n";
    delete[] array;
    return 1;
}