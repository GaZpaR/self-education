#include <iostream>            
#include <algorithm>           
#include <fstream>
#include <string>
#include <vector>

class word{
	std::string w;
	size_t freq = 0;
public:
	word(){};
	word(std::string wr): w(wr){};
	~word(){};

	size_t getFreq(void){
		return freq;
	}

	std::string getWord(void){
		return w;
	}

	void operator++(int){
		 freq++;
	};
};

bool upperCase(char c){
	if(c >= 'A' && c <= 'Z')
		return true;
	else return false;
}

bool lowerCase(char c){
	if(c >= 'a' && c<= 'z')
		return true;
	else return false;
}

bool isLetter(char c){
	if(lowerCase(c) || upperCase(c))
		return true;
	else
		return false;
}

bool isSeparator(char c){
	if(c == '-' || c == '_')
		return true;
	else
		return false;
}

bool isWord(std::string wrd){
	size_t len = wrd.length();
	if(len <= 0) return false;
	for(size_t i=0; i<len; i++)
		if(!isLetter(wrd[i]) && !isSeparator(wrd[i]))
			return false;
	return true;
}

class vocabular{
public:
	vocabular(){};
	~vocabular(){};
	
	std::vector<word> vocab;

	void tryAddWord(std::string wrd){
		for(size_t i=0; i<vocab.size(); i++){
			std::string tWord(vocab[i].getWord());
			if(wrd.compare(tWord) == 0){
				vocab[i]++;
				return;
			}
		}
		word nw(wrd);
		nw++;
		vocab.push_back(nw);
	}

	void sortVocabular(void){
    std::sort(vocab.begin(), vocab.end(), [](word a, word b) {
        return b.getFreq() < a.getFreq();
    });

		std::vector<word>::iterator it = vocab.begin();
		for(size_t i=0; i < vocab.size(); ++i){
			if(vocab[i].getFreq() == 1){
				break;
			}
			it++;
		}

    std::sort(it, vocab.end(), [](word a, word b) {
				std::string sa(a.getWord()), sb(b.getWord());
				char ca = sa[0], cb = sb[0];
				if(lowerCase(ca))
					ca -= 32;
				if(lowerCase(cb))
					cb -= 32;
        return cb > ca;
    });
	}

};

std::string readFile(std::string file){
  std::ifstream inf(file, std::ios::in|std::ios::binary|std::ios::ate);
  std::string out;
  if(inf.is_open()) {
    std::streampos size;
    char * memblock;
    size = inf.tellg();
    memblock = new char [size];
    inf.seekg (0, std::ios::beg);
    inf.read (memblock, size);
    out.append(memblock);
    delete[] memblock;
    inf.close();
  }
  else{
    std::cout << "Unable to open file" << std::endl;
  }
  return out;
}

void writeFile(std::string filename, vocabular &voc){
	std::ofstream file(filename);
	if(file.is_open()){
		for(size_t i=0; i< voc.vocab.size(); i++)
			file<< voc.vocab[i].getWord() << ": " << voc.vocab[i].getFreq() << std::endl;
		file.close();
	}
	else{
		std::cout << "Can't create or open file" << std::endl;
	}
}

void parseText(std::string input, vocabular &voc){
	bool wordStart=false;
	size_t wordStartPos = 0;
	for(size_t i=0; i < input.length(); i++){
		if((isLetter(input[i]) || isSeparator(input[i])) 
				&& i != input.length()-1){
			if(!wordStart){
				wordStart = true;
				wordStartPos = i;
			}
		}
		else{
			if(wordStart){
				wordStart = false;
				std::string atomWord;
				if(i == input.length()-1 && isLetter(input[i+1])) i++; //For last char
				atomWord.assign(input, wordStartPos, i - wordStartPos);
				voc.tryAddWord(atomWord);
			}
		}
	}
}

int main(int argc, char **argv){
	if(argc < 3){
		std::cout << "Not enough args" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "shell>:./fvocab input.txt result.txt" << std::endl;
		return -1;
	}
	else{
		std::string infile(argv[1]), outfile(argv[2]);
		std::cout << infile << " : " << outfile << std::endl;

		std::string text = readFile(argv[1]);

		vocabular test;
		parseText(text, test);
		test.sortVocabular();
		writeFile(argv[2], test);
		return 0;
	}
}


