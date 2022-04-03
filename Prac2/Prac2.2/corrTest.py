# Script to verify that output from Golden Standard matches that from the Kernel

def main():
    Size = input("Enter matrix size you want to verify the output of: ")
    GSFile = "GSOutput/GSOutput_" + Size + "x" + Size + ".txt"
    kernelFile = "kernelOutput/kernelOutput_" + Size + "x" + Size + ".txt"

    GSOutput = ""
    kernelOutput = ""

    flagStart = "Output"
    flagEnd = "Run Time"

    with open(GSFile) as f:
        for line in f:
            if flagStart in line:
                continue
            elif flagEnd in line:
                break
            else:
                GSOutput = GSOutput + line

    with open(kernelFile) as g:
        for line in g:
            if flagStart in line:
                continue
            elif flagEnd in line:
                break
            else:
                kernelOutput = kernelOutput + line
    
    f.close()
    g.close()

    # print(GSOutput)
    # print(kernelOutput)

    if GSOutput == kernelOutput:
        print("Success! Golden Standard Output = Kernel Output!")
    else:
        print("Something went wrong! :(")

if __name__ == "__main__":
    main()
