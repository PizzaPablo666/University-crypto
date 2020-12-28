#include <iostream>
#include <fstream>
using namespace std;

int low_upp_not(int val){
	
	int res;

	if (val >= 65 && val <= 90) res = 1;
	else if (val >= 97 && val <= 122) res = 0;
	else res = 2;
	
	return res;
} 

int main(int argc, char* argv[]){

string encrypted_msg, bf_msg;
int i = 0,j, ascii_val;

// Checking argument count //
if (argc > 2) cout << "--> I am going to process only the first file <--\n";

// Reading from a file //
ifstream MyReadFile(argv[1]);
getline(MyReadFile, encrypted_msg);
MyReadFile.close();

cout << "--> The message we are going to brute force attack <--\n--> ";
cout << encrypted_msg << endl;

// Brute Force //
for (j = 0; j <= 25; j++){
	for (int i = 0; i < encrypted_msg.length(); i++){
		ascii_val = int(encrypted_msg[i]);

		if (low_upp_not(ascii_val) == 0){
			if (ascii_val + j > 122) bf_msg += char(ascii_val + j - 26);
			else bf_msg += char(ascii_val + j);
		}
		else if (low_upp_not(ascii_val) == 1){
			if (ascii_val + j > 90) bf_msg += char(ascii_val + j - 26);
			else bf_msg += char(ascii_val + j);
		}
		else bf_msg += encrypted_msg[i];
		 
	}
	cout << "--> key = " << 26 - j << endl;
	cout << "--> msg = " << bf_msg << "\n\n";
	bf_msg = "";
}

return 0;
}
