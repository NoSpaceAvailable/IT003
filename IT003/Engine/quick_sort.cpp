#include <iostream>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <fstream>
#define MAX_LEVELS 48
using namespace std;
using namespace std::chrono;

int quick_sort(double *arr, size_t elements) {
    size_t beg[MAX_LEVELS], end[MAX_LEVELS], L, R;
    int i = 0;

    beg[0] = 0;
    end[0] = elements;
    while (i >= 0) {
        L = beg[i];
        R = end[i];
        if (R - L > 1) {
            size_t M = L + ((R - L) >> 1);
            double piv = arr[M];
            arr[M] = arr[L];

            if (i == MAX_LEVELS - 1)
                return -1;
            R--;
            while (L < R) {
                while (arr[R] >= piv && L < R)
                    R--;
                if (L < R)
                    arr[L++] = arr[R];
                while (arr[L] <= piv && L < R)
                    L++;
                if (L < R)
                    arr[R--] = arr[L];
            }
            arr[L] = piv;
            M = L + 1;
            while (L > beg[i] && arr[L - 1] == piv)
                L--;
            while (M < end[i] && arr[M] == piv)
                M++;
            if (L - beg[i] > end[i] - M) {
                beg[i + 1] = M;
                end[i + 1] = end[i];
                end[i++] = L;
            } else {
                beg[i + 1] = beg[i];
                end[i + 1] = L;
                beg[i++] = M;
            }
        } else {
            i--;
        }
    }
    return 0;
}

string get_file_name(int fd){
    string filename = (string)"../TestCase/random_case" + to_string(fd) + (string)".txt";
    return filename;
}

int main(){

    cout << "[Quicksort] Quicksort engine starting ...\n";
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
            quick_sort(array, 1000000);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - begin);
            cout << "[Quicksort] Testcase no." << fd << " took " << duration.count() << " ms\n";
        }

        else{
            cout << "[Quicksort] Error occured! Can't open random_case" << fd << ".txt" << ". Aborting ...\n";
            return 0;
        }

    }

    cout << "[Quicksort] Task completed!\n";
    delete[] array;
    return 1;
}