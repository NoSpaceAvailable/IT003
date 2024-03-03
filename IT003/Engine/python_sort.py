from time import time

if __name__ == "__main__":
    print("[Python Sort] Python sorting engine starting ...")
    for i in range(1, 11):
        try:
            with open(f"../TestCase/random_case{i}.txt", "r") as f:
                array = [float(j[:-1]) for j in f.readlines()]
                begin = time()
                array.sort()
                print(f"[Python Sort] Testcase no.{i} took %.2f (ms)" % ((time() - begin) * 1000))
        except Exception as e:
            print(f"[Python sort] Can't' open random_case{i}.txt: {e}. Aborting ...")
    print("[Python Sort] Task completed!")