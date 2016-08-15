#include <iostream>
#include <string>

template<typename T>
void mtxeval(T *mtx, uint raws, uint cols){
	// Input matrix is
	std::cout << "Input matrix is:"	<< std::endl;
	for(uint i=0; i<raws; i++){
		std::cout << i << ": ";
		for(uint j=0; j<cols; j++){
			std::cout << "\t" << mtx[i*cols + j];
		}
		std::cout << std::endl;
	}

	// gamma is quantity of possible variants in input matrix raws
	uint gamma[raws];
	for(uint i=0; i<raws; i++)
		gamma[i] = 0;

	// lambda is possible variants
	uint *lambda[raws];
	for(uint i=0; i<raws; i++){
		lambda[i] = new uint[cols];
		for(uint j=0; j<cols; j++){
			lambda[i][j] = 0;
		}
	}

	for(uint i=0; i<raws; i++){
		uint shift = 0;
		for(uint j=0; j<cols; j++){
			if(mtx[i*cols + j] != 0){
				lambda[i][shift] = j;
				gamma[i]++;
				shift++;
			}
		}
	}

	std::cout << "Allocated gamma"	<< std::endl;
	for(uint i=0; i<raws; i++){
		std::cout << gamma[i] << std::endl;
	}

	std::cout << "Allocated lambda"	<< std::endl;
	for(uint i=0; i<raws; i++){
		std::cout << i << ": ";
		for(uint j=0; j<gamma[i]; j++){
			std::cout << "\t" << lambda[i][j];
		}
		std::cout << std::endl;
	}
	
	// ksi- is matrix of all possible combinations of input raws and possible lambdas
	// All combinations of ksi matrix is maxcom
	uint maxcom = 1;
	for(uint i=0; i<raws; i++)
		maxcom *= gamma[i];

	std::cout <<"Maximum of combinations is: " << maxcom << std::endl;
	uint *ksi[maxcom];
	for(uint i=0; i<maxcom; i++){
		ksi[i] = new uint[raws];
		for(uint j=0; j<raws; j++)
			ksi[i][j] = 0;
	}

	uint C[raws];
	for(uint i=0; i<raws; i++)
		C[i] = 0;

	for(uint i=0; i<maxcom; i++){
		
		for(uint k=0; k<raws; k++)
			ksi[i][k] = lambda[k][C[k]];

		for(uint j=0; j<raws; j++){
			if(C[j] < gamma[j]-1)	{
					C[j]++;
					break;
			}

			if(C[j] == gamma[j]-1)
				C[j] = 0;
			
		}
	}

	std::cout <<"ksi matrix of combinations is: " << std::endl;
	// Show result
	for(uint i=0; i<maxcom; i++){
		std::cout << i << ":";
		for(uint j=0; j<raws; j++)
			std::cout << "\t" << ksi[i][j];
		std::cout << std::endl;
	}
}

int main(int argc, char **argv){
	std::cout << "This is simple matrix evaluator" << std::endl;
	/*if(argc < 3){
		std::cout << "Not enough args to ceate matrix" << std::endl;
		return -1;
	}
	uint x = std::stoi(argv[1]), y = std::stoi(argv[2]);

	std::cout << "x=" << x << ", y=" << y << std::endl;
*/
	uint MTX[4*3];

	MTX[0] = 1;
	MTX[1] = 1;
	MTX[2] = 0;
	MTX[3] = 1;
	MTX[4] = 1;
	MTX[5] = 1;
	MTX[6] = 1;
	MTX[7] = 0;
	MTX[8] = 1;
	MTX[9] = 1;
	MTX[10] = 0;
	MTX[11] = 1;

	std::cout << "Matrix MTX[4x3]" << std::endl;
	mtxeval<uint>(MTX, 4, 3);

	std::cout << "Bye bye!" << std::endl;
	return 0;
}

