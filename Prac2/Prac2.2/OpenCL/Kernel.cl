//Author: Matthew January
//Made in conjunction with Ben Connolly for EEE4120F course at UCT
//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

__kernel void matrixMultiplication(__global int* matrixA, __global int* matrixB, __global int* output)
{	
	//TODO: program your kernel here
	
	int workItemNum = get_global_id(0);
	int workGroupNum = get_group_id(0);
	//localGroupID = get_local_id(0);
	int size = get_local_size(0);

	//memory buffers
	int* arg1 = matrixA;
	int* arg2 = matrixB;

	//Multiplying matrixA by matrixB
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arg1[size*workGroupNum+i] * arg2[size*i + workItemNum%size];
	}

	output[workGroupNum*size + workItemNum%size] = sum;
	
	//print("Kernel print output test \n");

	//barrier(CLK_LOCAL_MEM_FENCE);
}




