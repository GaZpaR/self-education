#include <iostream>
#include <string>
#include <vector>


// Function to check input expression
bool checkExpression(std::string exp){
	for(uint i=0; i<exp.length(); i++){
		char c = exp[i];
		if(c < '(' || c > '9' || c == '\''){
			if(c != ' ') return false;
		}
	}
	return true;
}


// Template function to evaluate atomic expression
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
		default: throw("atomEval:  Undefined math operation");

	}
};

// Function to evaluate expression without brackets
template<class T>
std::string evalExpWithoutBrackets(std::string exp){

	std::vector<T> operands;
	std::vector<char> operations;

	const uint explen = exp.length();

	// Allocating arguments and operations without ordering
	for(uint i=0, ps = 0; i<explen; i++){

		// This check need for situation when we didn't allocate last argument
		if(i == explen-1){
			std::string expWithoutBrackets;
			expWithoutBrackets.assign(exp, ps, explen - ps + 1);
			operands.push_back((T) std::stod(expWithoutBrackets));
		}

		if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
			std::string expWithoutBrackets1;
			expWithoutBrackets1.assign(exp, ps, i-ps);
			operands.push_back((T) std::stod(expWithoutBrackets1));

			operations.push_back(exp[i]);

			std::string expWithoutBrackets2;
			ps = i+1;
			for(i++; i<explen; i++){
					if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ){
						expWithoutBrackets2.assign(exp, ps, i-ps);
						operations.push_back(exp[i]);
						break;
					}
					if(i == explen-1){
						expWithoutBrackets2.assign(exp, ps, explen - ps);
					}
			}
			operands.push_back((T)std::stod(expWithoutBrackets2));
			ps = i+1;
		}
	}

	// Calculator

	std::vector<uint> evalOrder; // Order of operations
	uint highPriority = 0, lowPriority = 0;

	// Ordering operations

	// First of all we need operations with high priority
	for(uint i=0; i < operations.size(); i++){
		if(operations[i] == '*' || operations[i] == '/'){
			evalOrder.push_back(i);
			highPriority++;
		}
	}

	// Now we need to order low priority operations
	for(uint i=0; i < operations.size(); i++){
		if(operations[i] == '-' || operations[i] == '+'){
			evalOrder.push_back(i);
			lowPriority++;
		}
	}

	// Evaluating epression by order
	for(uint i=0; i < evalOrder.size(); i++){
		T rexp = (T)NULL;

		try{
			rexp = eval<T>(operands[evalOrder[i]], operands[evalOrder[i]+1], operations[evalOrder[i]]);
		}
		catch(char const *er){
				std::cout << er << std::endl;
		}

		// Erasing operations and operands, because operands[evalOrder[i]] and operands[evalOrder[i]+1]
		// became single argument after completing operations[evalOrder[i]] operation
		if(evalOrder[i] < operands.size()-1){
			operands.erase(operands.begin()+evalOrder[i]+1);
			operations.erase(operations.begin()+evalOrder[i]);
		}
		// Recallculating order
		for(uint j = i; j < evalOrder.size(); j++){
			if(evalOrder[j] > evalOrder[i]) evalOrder[j]--;
		}
		// Storing result of eval<T>
		operands[evalOrder[i]] = rexp;
	}

	return std::to_string(operands[0]);
}

template<class T>
std::string evalExpression(std::string exp){
	uint open = 0, close = 0;
	for(uint i=0; i<exp.length(); i++){
		if(exp[i] == '(') open++;
		else if(exp[i] == ')') close++;
	}
	if(open != close)
		return (std::string)"error: Expression have uncoupled brackets";
	
	// Divide expression to the blocks if there are any brackets
	for(uint closeBracketPosition=0; closeBracketPosition<exp.length(); closeBracketPosition++){
		if(exp[closeBracketPosition] == ')'){
			uint openBracketPosition = closeBracketPosition;
			while(openBracketPosition--){
				if(exp[openBracketPosition] == '('){
					std::string expWithoutBrackets;                
					expWithoutBrackets.assign(exp, openBracketPosition + 1, closeBracketPosition - openBracketPosition - 1);

					std::string atomExpResult = evalExpression<T>(expWithoutBrackets);
					
					std::string leftPartExp, rightPartExp;

					leftPartExp.assign(exp, 0, openBracketPosition);
					rightPartExp.assign(exp, closeBracketPosition + 1, exp.length() - closeBracketPosition);
					
					return evalExpression<T>( leftPartExp + atomExpResult + rightPartExp);
				}
			}
		}
	}
	return evalExpWithoutBrackets<T>(exp);;
}

int main(int argc, char **argv){
	std::string evalexp(argv[1]);
	
	// Check input expression for unhandling symbols
	if(!checkExpression(evalexp)) return -1;

	// Clear expression from spaces
	for(uint i=0 ; i < evalexp.length(); i++){
		if(evalexp[i] == ' '){
			evalexp.erase(evalexp.begin() + i);
			if(i > 0) i--;
		}
	}
	std::cout << "Evaluating expression is: \"" << evalexp << "\"" << std::endl;

	std::cout << "Result is: " << evalExpression<int>(evalexp) << std::endl;
	return 0;
}
