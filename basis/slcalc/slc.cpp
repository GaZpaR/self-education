#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>

enum{
	SUM = '+',
	DIF = '-',
	MUL = '*',
	DIV = '/'
};

// Operation priority
enum{
	MP = 0, // Most priority
	LP	// Least priority
};

// Function to check input expression
bool expcheck(std::string exp){
	for(uint i=0; i<exp.length(); i++){
		char c = exp[i];
		if(c < '(' || c > '9' || c == '\''){
			if(c != ' ') return false;
		}	
	}
	return true;
}


// Template function to evaluate atomic function
template<class T>
T eval(int a, int b, const char op){
	switch(op){
		case '+':{
			return a+b;
		}
		case '-':{
			return a-b;
		}
		case '*':{
			return a*b;
		}
		case '/':{
			return a/b;
		}
		default: throw("atomeval:  Undefined math operation");

	}
};


std::string evals(std::string exp){
	
	// We should divide expression to the blocks if there are any brackets
	std::vector<int> openbrpos, closebrpos;
	for(uint i=0; i<exp.length(); i++){
		char c = exp[i];
		if(c == '(') openbrpos.push_back(i);
		if(c == ')') closebrpos.push_back(i);
	}
	
	uint i = 0, j = exp.length();
	char c = ' ';
	for(i; i < j; i++){
		c = exp[i];
		if(c == '+' || c =='-' || c =='*' || c=='/'){
			std::cout << "Operation is: \"" << c << "\"" << std::endl;
			std::string texp1;
				texp1.assign(exp, 0, i);
			std::cout << texp1 << std::endl;
			std::string texp2;
				texp2.assign(exp, i+1, j-1);
			std::cout << texp2 << std::endl;
			try{
				int sign = 1;

				if(c == '-'){
					sign = -1;
					c = '+';
				}	
				int rexp = eval<int>(std::stoi(evals(texp1), nullptr, 0), std::stoi(evals(texp2), nullptr, 0)*sign, c);
				std::string res = std::to_string(rexp);
				return res;
			}
			catch(char const *er){
				std::cout << er << std::endl;
			}
		}
	}
	//std::cout << exp << std::endl;
	return exp;
}

int main(int argc, char **argv){

	std::string evalexp(argv[1]);
	// Check input expression for unhandling symbols
	if(!expcheck(evalexp)) return -1;

	std::cout << "Evaluating expression is: \"" << evalexp << "\"" << std::endl;

	for(uint i=0 ; i < evalexp.length(); i++){
		if(evalexp[i] == ' '){
			evalexp.erase(evalexp.begin() + i);
			if(i > 0) i--;
		}
	}
	
	std::cout << "Evaluating expression without 'space' is: \"" << evalexp << "\"" << std::endl;
	
	std::cout << "Result is: " << evals(evalexp) << std::endl;
	std::cout<<"Hello, suk!"<<std::endl;
	return 0;
}
