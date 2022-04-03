script.py and script_GS.py (in the Golden Standard folder) can be run with the following commands respectively:

	python script.py -i <filename>
	python script_GS.py -i <filename>

The above commands will compile their respective .cpp programs and, in the case of the golden standard script, execute the executable generated 11 times (10 timed, 1 primer for the cache).
The OpenCL matrix multiplication program runs the kernel 11 times (10 timed, 1 primer for the cache) within the code.

Both the code for the golden standard and the OpenCL kernel write the output of their multiplication to text files - the golden standards output is perhaps somewhat verbose, but is still useful in data collection.

corrTest.py was run on home PC with numerous text files containing the output of the golden standard and the kernel code stored in separate folders, so some modifications need to made if run on another machine.
