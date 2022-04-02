# Compiles and runs multiplication.cpp OR multiplicationGoldenStandard.cpp
# To execute script, run command: python script.py -i <filename>
# Help writing script from "tutorialspoint.com/Python"

import sys, os, getopt, time

def main (argv):
    cppFile = ""
    exeFile = ""

    try:
        opts, args = getopt.getopt(argv, "hi:", ["help", "ifile="])
    except getopt.GetoptError as err:
        # print help information and exit
        sys.exit(2)
    for o, a in opts:
        if o in ("-i", "--ifile"):
            cppFile = a + '.cpp'
            exeFile = a
            os.system("rm ./*.txt")
            for i in range (10):
                run(cppFile, exeFile)
                time.sleep(1.1)
        else:
            sys.exit()

def run(cppFile, exeFile):
    os.system("echo Compiling " + cppFile)
    if os.system("gcc " + " -o " + exeFile  + " " + cppFile + " -lOpenCL " + " -lstdc++") == 0:
        os.system("echo Running " + exeFile)
        os.system("echo -------------------")
        os.system("./" + exeFile)
    else:
        print("Compilation Failed - Check <filename> is correct")

if __name__=='__main__':
    main(sys.argv[1:])