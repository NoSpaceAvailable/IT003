import os

if __name__ == "__main__":
    print("[__core__] Core running")
    
    cpp_engines = ["quick_sort", "merge_sort", "heap_sort"]
    py_engines = ["numpy_sort", "python_sort"]
    exec_path = os.path.abspath(os.path.dirname(__file__))
    
    for engine in cpp_engines:
        print(f"[__core__] Starting {engine} engine ...")
        os.system(f"g++ ./../Engine/{engine}.cpp -o ./../executable/{engine}.exe")
        if (os.name == 'nt'):
            os.system(f'"{exec_path}/../executable/{engine}.exe"')
        else:
            os.system(f"./../executable/{engine}.exe")
        print('\n')
        
    for engine in py_engines:
        print(f"[__core__] Starting {engine} engine ...")
        os.system(f"python3 ./../Engine/{engine}.py")
        print('\n')