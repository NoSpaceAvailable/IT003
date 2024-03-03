from time import time
import os

try:
    from numpy import sort as np_sort
except Exception as e:
    print("[NumPy sort] numpy module not installed. Installing ...")
    os.system("pip3 install numpy")
    from numpy import sort as np_sort

if __name__ == "__main__":
    print("[NumPy Sort] Numpy sorting engine starting ...")
    for i in range(1, 11):
        try:
            with open(f"../TestCase/random_case{i}.txt", "r") as f:
                array = [float(j[:-1]) for j in f.readlines()]
                begin = time()
                np_sort(array)
                print(f"[NumPy Sort] Testcase no.{i} took %.2f (ms)" % ((time() - begin) * 1000))
        except Exception as e:
            print(f"[NumPy sort] Can't' open random_case{i}.txt: {e}. Aborting ...")
    
    print("[NumPy Sort] Task completed!")