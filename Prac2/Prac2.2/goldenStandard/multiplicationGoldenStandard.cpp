
//Author: Christopher Hill For the EEE4120F course at UCT

#include<stdio.h>
#include<iostream>
#include<fstream>
#include <cstdlib>

using namespace std;

//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = j + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}


//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	srand(time(0));
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = rand() % 100 + 1; //srand(time(0)) used in place of rand() to generate
								   //different value each time the program is run.
								   //time(0) as the seed int is std practice.
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}




int main(void){



	//New code for prac 2.2
	bool displayMatrices = true;
	int Size = 100;
	string Size_string = to_string(Size);
	int countA = Size*Size;
	int matrixA[countA];
	createKnownSquareMatrix(Size,matrixA, displayMatrices);
	cout<<"Number of elements in matrix 1: "<<countA<<"\n";
	cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 1 pointer: "<<matrixA<<"\n";
	

	
	
	int countB = Size*Size;
	int matrixB[countB];
	//createRandomSquareMatrix(Size, matrixB, displayMatrices);
	createKnownSquareMatrix(Size, matrixB, displayMatrices);
	cout<<"Number of elements in matrix 2: "<<countB<<"\n";
	cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 2 pointer: "<<matrixB<<"\n";
	
	
	
	int output[countA];
	
	//TODO: code your golden standard matrix multiplication here
	clock_t start, end;
	//int NUM_RUNS = 10;
	start = clock();
	// Running computation code 10 times for accurate timing data
	//for (int i = 0; i < NUM_RUNS; i++)
	//{
		int sum; //Variable to store the sums of Rows*Cols of matrixA and matrixB respectively
		int count = 0; //Counter to track iterations through output matrix for accurate assignment of output matrix elements
		int count2 = 0; //Counter to track iterations through matrixA - goes from 0 to matrix_size then resets to 0
		int a = 0; //Special counter to track iteration through Column elements of matrixB
		while(count < countA)
		{
			sum = 0;
			for(int k = 0; k<Size; k++)
			{
				sum += matrixA[count2]*matrixB[(count-Size*a)+k*Size];  //Sum for each element of output matrix
				count2 += 1;						//Formula for matrixB tricky due to matrices populated in 1D arrays instead of 2D
			}

			output[count] = sum;
			count += 1;
			if (count%Size == 0){
				a += 1;
			}
			if (count2 == Size*Size){
				count2 = 0;
			}
		}
//	}
	end = clock();
	float duration;
	duration = ((float) end - start)/CLOCKS_PER_SEC;

	string filename("GSOutput_" + Size_string + "x" + Size_string +".txt");
	ofstream myfile;

	myfile.open(filename, std::ios_base::app);

	//This if statement will display the matrix in output	
	if(displayMatrices){
		printf("\nOutput in the output_buffer \n");
		myfile << "\nOutput in the output_buffer \n";
		for(int j=0; j<countA; j++) {
			printf("%i \t " ,output[j]);
			myfile << output[j] << " \t";
			if(j%Size == (Size-1)){
				printf("\n");
				myfile << "\n";
			}
		}
	}

	printf("Run Time: %0.8f sec \n", duration);
	myfile << "Run Time: " << duration << "sec \n";
	myfile.close();
	return 0;
}
