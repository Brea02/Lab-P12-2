#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<iomanip>

using namespace std;

//function prototypes
void pressEnterToContinue();
bool readFromFile(string filename);
//new functions
bool isNotWhiteSpace(char c);
bool isNotPunctuation(char c);

int main() {
	string datafile;
	cout << "P12-2 program!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);
	bool status = readFromFile(datafile);
	if (status) cout << "Success!\n";
	else cout << "failure. :-( \n";
	pressEnterToContinue();
}

//functions

bool readFromFile(string filename) {
	ifstream inFile;		//input filestream for reading in our data
	int countCharacter = 0;
	int countWord = 0;
	inFile.open(filename);	//attempt to open the specified text file

	if (inFile.fail()) {	//error when problem occurs
		cout << "read error - sorry\n";
		return false;
	}
	//from in class stuff
	if (inFile.is_open()) {

		string word, wordAtPosn;
		char ch;

		while (!inFile.eof()) {
			inFile >> word;
			if (word != "-") {
				countWord++;
			}
			//countWord++;

			//cout << setw(2) << countWord << ". " << left << setw(20) << word << right;

			int i = 0;
			//int countCharacter;
			while (i < word.length()) {
				ch = tolower(word.at(i));
				if (isNotWhiteSpace(ch) == true && isNotPunctuation(ch) == true) {
					countCharacter++;
				}
				/*if (ch != ' ') { //maybe change this condition to using the 2 new functions?
					//countAllVowels++;
					countCharacter++;
				}*/
				i++;
			}
		}
		cout << "Words: " << countWord << endl;
		cout << "Characters: " << countCharacter << endl;
	}

	//close the file and return
	inFile.close();
	return true;
}


//
void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

//new functions
bool isNotWhiteSpace(char c) {
	if (c == ' ' || c == '\n' || c == '\t') {
		return false;
	}
	return true;
}


bool isNotPunctuation(char c) {
	if (c == '.' || c == ',' || c == ';' || c == '-' || c == '?' || c == '!' || c == '"' || c == '\'') {
		return false;
	}
	return true;
}
