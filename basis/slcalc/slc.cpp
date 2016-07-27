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

	const uint explen = exp.length();

	// Allocating arguments and operations without ordering
	for(uint i=0, ps = 0; i<explen; i++){

		if(i == explen-1){
			std::string temps;
			temps.assign(exp, ps, explen - ps);
			args.push_back(std::stoi(temps));
		}

		if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
			std::string temps1;
			temps1.assign(exp, ps, i-ps);
			args.push_back(std::stoi(temps1));

			ops.push_back(exp[i]);

			std::string temps2;
			ps = i+1;
			for(i++; i<explen; i++){
					if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ){
						temps2.assign(exp, ps, i-ps);
						ops.push_back(exp[i]);
						break;
					}
					if(i == explen-1){
						temps2.assign(exp, ps, explen - ps);
					}
			}
			args.push_back(std::stoi(temps2));
			i++;
			ps = i;

			if(i == explen-1){
				std::string temps3;
				temps3.assign(exp, ps, explen - ps);
				args.push_back(std::stoi(temps3));
			}
		}
	}
/* This show args and operations
	std::cout << "Arguments are: " << std::endl;
	for(uint i=0; i<args.size(); i++)
		std::cout << args[i] << ' ';
	std::cout << std::endl;

	std::cout << "Operations are: " << std::endl;
	for(uint i=0; i<ops.size(); i++)
		std::cout << ops[i] << ' ';
	std::cout << std::endl;
*/

	// Calculator

	std::vector<uint> evalorder; // Order of operations
	uint hp = 0, lp = 0;

	// Ordering operations

	// First of all we need operations with high priority
	for(uint i=0; i < ops.size(); i++){
		if(ops[i] == '*' || ops[i] == '/'){
			evalorder.push_back(i);
			hp++;
		}
	}

	// Now we need to order low priority operations
	for(uint i=0; i < ops.size(); i++){
		if(ops[i] == '-' || ops[i] == '+'){
			evalorder.push_back(i);
			lp++;
		}
	}

/* This show order of operations
	std::cout << "Evaluating order is: " << std::endl;
	for(uint i=0; i<ops.size(); i++)
		std::cout << evalorder[i] <<"="<< ops[evalorder[i]] << ' ';
	std::cout << std::endl;
*/

	// Evaluating epression by order
	for(uint i=0; i < evalorder.size(); i++){

		int rexp = eval<int>(args[evalorder[i]], args[evalorder[i]+1], ops[evalorder[i]]);

		/* Debuging information
		std::cout << "arg1=" << args[evalorder[i]] <<", arg2="<<args[evalorder[i]+1]<<
			", operation="<<ops[evalorder[i]]<<", result="<<rexp<<std::endl;
		std::cout << "Size of args is: " << args.size() << std::endl;
		*/

		// Shift operations, because args[evalorder[i]] and args[evalorder[i]+1]
		// became single argument after ops[evalorder[i]] operation
		if(evalorder[i] < args.size()){
			args.erase(args.begin()+evalorder[i]+1);
			ops.erase(ops.begin()+evalorder[i]);
		}
		// Recallculating order
		for(uint j = i; j < evalorder.size(); j++){
			if(evalorder[j] > evalorder[i]) evalorder[j]--;
		}
		// Storing result of eval<T>
		args[evalorder[i]] = rexp;
	}

	std::cout << exp << '=' << args[0] << std::endl;
	return std::to_string(args[0]);
}


std::string evals(std::string exp){

	// We should divide expression to the blocks if there are any brackets
	std::vector<int> obp, cbp; // obp- "open bracket position", cbp- "close bracket position"
	for(uint i=0; i<exp.length(); i++){
		char c = exp[i];
		if(c == '(') obp.push_back(i);
		if(c == ')') cbp.push_back(i);
	}
	if(obp.size() != cbp.size()) return (std::string)"error: Expression have uncoupled brackets";

	if(obp.size() > 0 ){
		std::cout << "There is no brackets" << std::endl;
		return exp;
	}
	else{
		std::cout << "There is no brackets" << std::endl;
		return evalexpwb(exp);
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
