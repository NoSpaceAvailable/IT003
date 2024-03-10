import os

if __name__ == "__main__":
    
    print("[__main__] Starting program ...\n")
    
    if ("Main" not in os.getcwd()):
        print("[__main__] Please change your working directory to /IT003/Main then run this script again!")
        exit(1)
        
    while True:
        choice = int(input("""[__main__] Do you want to generate new testcases?
                    1. Yes, generate new
                    2. No, run the program
                    3. Exit program
                    ---> """))
        if choice == 1:
            try:
                os.system("python3 __generator__.py")
                print("[__main__] Testcases generated!")
            except Exception as e:
                print(f"[__main__] Error: {e}")
        elif choice == 2:
            print("[__main__] Switching to core ...\n")
            os.system("python3 __core__.py")
        elif choice == 3:
            print("[__main__] Bye!")
            exit(1)
        else:
            print("[__main__] Invalid choice!!!")
    
