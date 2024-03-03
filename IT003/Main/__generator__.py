from random import uniform
from os import getcwd

if __name__ == "__main__":
    cwd = getcwd()
    print(f"[__generator__] Your current working directory: {cwd}")
    with open(f"./../TestCase/random_case1.txt", "w+") as bc:  # best case
        print("[__generator__] Generating random_case1.txt ...", end='\r')
        for i in range(-500000, 500000):
            bc.write(str(uniform(i, i + 1)) + '\n')

    with open(f"./../TestCase/random_case2.txt", "w+") as wc:  # worst case
        print("[__generator__] Generating random_case2.txt ...", end='\r')
        for i in range(-500000, 500000)[::-1]:
            wc.write(str(uniform(i, i + 1)) + '\n')

    for i in range(3, 11):
        with open(f"./../TestCase/random_case{i}.txt", "w+") as f:
            print(f"[__generator__] Generating random_case{i}.txt ...", end='\r')
            for j in range(1, 1000001):
                f.write(str(uniform(-1000000, 1000000)) + '\n')
                
    print("\n[__generator__] Testcases generated succesfully!")