#include <iostream>
#include <string>

class CNT{
private:
	uint *p;
	uint size;
	uint *gamma;
public:
	CNT(uint *ptr, uint s, uint *g):
			p(ptr), size(s), gamma(g){};
	void up(){
		for(uint i=0; i<size; i++){
			if(p[i] < gamma[i]-1)	{
					p[i]++;
					break;
			}

			if(p[i] == gamma[i]-1)
				p[i] = 0;
			
		}
	}
};

template<typename T>
void mtxeval(T *mtx[], uint raws, uint cols){
	// Input matrix is
	for(uint i=0; i<raws; i++){
		std::cout << i << ": ";
		for(uint j=0; j<cols; j++){
			std::cout << "\t" << mtx[i][j];
		}
		std::cout << std::endl;
	}
	// gamma is quantity of possible variants in iput matrix raws
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
			if(mtx[i][j] != 0){
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

	std::cout <<"maxcom=" << maxcom << std::endl;
	uint *ksi[maxcom];
	for(uint i=0; i<maxcom; i++){
		ksi[i] = new uint[raws];
		for(uint j=0; j<raws; j++)
			ksi[i][j] = 0;
	}

	uint C[raws];
	for(uint i=0; i<raws; i++)
		C[i] = 0;

	// Special object to up counters of combinations
	CNT cnt(C, raws, gamma);

	for(uint i=0; i<maxcom; i++){
		
		for(uint k=0; k<raws; k++)
			ksi[i][k] = lambda[k][C[k]];

		cnt.up();
	}

	// Show result
	for(uint i=0; i<maxcom; i++){
		std::cout << i << ":";
		for(uint j=0; j<raws; j++)
			std::cout << "\t" << ksi[i][j];
		std::cout << std::endl;
	}
}

int main(int argc, char **argv){
	/*if(argc < 3){
		std::cout << "Not enough args to ceate matrix" << std::endl;
		return -1;
	}
	uint x = std::stoi(argv[1]), y = std::stoi(argv[2]);

	std::cout << "x=" << x << ", y=" << y << std::endl;
*/
	uint *MTX[3];
	for(uint i=0; i<4; i++)
		MTX[i] = new uint[3];
	
	MTX[0][0] = 1;
	MTX[0][1] = 1;
	MTX[0][2] = 0;
	MTX[1][0] = 1;
	MTX[1][1] = 1;
	MTX[1][2] = 1;
	MTX[2][0] = 1;
	MTX[2][1] = 0;
	MTX[2][2] = 1;
	MTX[3][0] = 1;
	MTX[3][1] = 0;
	MTX[3][2] = 1;
	mtxeval<uint>(MTX, 4, 3);

	std::cout << "Simple matrix evaluator" << std::endl;
	return 0;
}

