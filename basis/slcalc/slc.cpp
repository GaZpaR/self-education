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

// Function to evaluate expression without brackets
std::string evalexpwb(std::string exp){

	std::vector<int> args;
	std::vector<char> ops;

	std::cout << exp << std::endl;
	const uint explen = exp.length();
	for(uint i=0, ps = 0; i<explen; i++){
		if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){

			std::string temps1;
				temps1.assign(exp, ps, i-ps);

			args.push_back(std::stoi(temps1));

			ops.push_back(exp[i]);

			std::string temps2;

			i++;
			ps = i;
			for(; i<explen; i++){
				if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ){
					temps2.assign(exp, ps, i-ps);

					ops.push_back(exp[i]);
					break;
				}
				if(i == explen-1){
					temps2.assign(exp, ps, i-explen-1);
				}
		}
			args.push_back(std::stoi(temps2));
			ps = i+1;
		}

	}

	std::cout << "Arguments are: " << std::endl;
	for(uint i=0; i<args.size(); i++)
		std::cout << args[i] << ' ';
	std::cout << std::endl;

	std::cout << "Operations are: " << std::endl;
	for(uint i=0; i<ops.size(); i++)
		std::cout << ops[i] << ' ';
	std::cout << std::endl;

	return exp;
}


std::string evals(std::string exp){

	// We should divide expression to the blocks if there are any brackets
	std::vector<int> obp, cbp; // obp- "open bracket position", cbp- "close bracket position"
	for(uint i=0; i<exp.length(); i++){
		char c = exp[i];
		if(c == '(') obp.push_back(i);
		if(c == ')') cbp.push_back(i);
	}
	if(obp.size() != cbp.size()) return (std::string)"Expression have uncoupled brackets";

	if(obp.size() > 0 ){
		return exp;
	}
	else{
		std::cout << "There is no brackets" << std::endl;
		return evalexpwb(exp);
		// int rexp = eval<int>(std::stoi(evals(texp1), nullptr, 0), std::stoi(evals(texp2), nullptr, 0)*sign, c);
	}
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
