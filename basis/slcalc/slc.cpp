#include <iostream>
#include <string>
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

int ieval(int a, int b, const char op){
	int res;
	switch(op){
		case '+':{
			res =  a+b;
			break;
		}
		case '-':{
			res =  a-b;
			break;
		}
		case '*':{
			res = a*b;
			break;
		}
		case '/':{
			res = a/b;
			break;
		}
		default: throw("atomeval:  Undefined math operation");

	}
	
	std::cout << "a" << op << "b" << "="<< a << op << b << "=" << res << std::endl;
	return res;
};


std::string eval(std::string exp){
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
			char buf[32];
			int rexp;
			try{
				rexp = ieval(std::stoi(eval(texp1), nullptr, 0), std::stoi(eval(texp2), nullptr, 0), c);
				snprintf(buf, sizeof(buf), "%d", rexp);
			}
			catch(char const *er){
				std::cout << er << std::endl;
			}
			std::string res(buf);
			return res;
		}
	}
	//std::cout << exp << std::endl;
	return exp;
}

int main(int argc, char **argv){
	std::string evalexp(argv[1]);
	
	std::cout << "Evaluating expression is: \"" << evalexp << "\"" << std::endl;

	for(uint i=0 ; i < evalexp.length()-1; i++){
		if(evalexp[i] == ' '){
			evalexp.erase(evalexp.begin() + i);
			if(i > 0) i--;
		}
	}
	
	std::cout << "Evaluating expression without 'space' is: \"" << evalexp << "\"" << std::endl;
	
	std::cout << "Result is: " << eval(evalexp) << std::endl;
	std::cout<<"Hello, suk!"<<std::endl;
	return 0;
}
