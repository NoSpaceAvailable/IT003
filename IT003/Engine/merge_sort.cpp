#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace std::chrono;

void merge(double arr[], size_t left, size_t mid, size_t right){
    size_t numbLeft = mid - left + 1, numbRight = right - mid;
    double* leftArr = new double[numbLeft]; 
    double* rightArr = new double[numbRight]; 
    for (size_t i = 0; i < numbLeft; i++){
        leftArr[i] = arr[left + i]; 
    }
    for (size_t i = 0; i < numbRight; i++){
        rightArr[i] = arr[mid + 1 + i]; 
    }

    size_t i = 0, j = 0, k = left;
    while (i < numbLeft && j < numbRight){
        (leftArr[i] < rightArr[j]) ? (arr[k] = leftArr[i], i++) : (arr[k] = rightArr[j], j++);
        k++;
    }
    while (i < numbLeft)
    {
        arr[k] = leftArr[i];
        i++, k++;
    }
    while (j < numbRight){
        arr[k] = rightArr[j];
        j++, k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(double arr[], size_t left, size_t right){
    if(left < right){
        size_t mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

string get_file_name(int fd){
    string filename = (string)"../TestCase/random_case" + to_string(fd) + (string)".txt";
    return filename;
}

int main(){

    cout << "[Mergesort] Mergesort engine starting ...\n";
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
            merge_sort(array, 0, 999999);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - begin);
            cout << "[Mergesort] Testcase no." << fd << " took " << duration.count() << " ms\n";
        }

        else{
            cout << "[Mergesort] Error occured! Can't open random_case" << fd << ".txt" << ". Aborting ...\n";
            return 0;
        }

    }

    cout << "[Mergesort] Task completed!\n";
    delete[] array;
    return 1;
}