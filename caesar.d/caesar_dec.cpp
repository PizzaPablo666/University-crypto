#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int low_upp_not(int val){
	
	int res;

	if (val >= 65 && val <= 90) res = 1;
	else if (val >= 97 && val <= 122) res = 0;
	else res = 2;
	
	return res;
} 

int main(int argc, char* argv[]){

bool valid = false;
string encrypted_msg, bf_msg;
int i = 0,j, ascii_val, key;

// Checking argument count //
if (argc > 2) cout << "--> I am going to process only the first file <--\n";

// Reading from a file //
ifstream MyReadFile(argv[1]);
getline(MyReadFile, encrypted_msg);
MyReadFile.close();

// Entering key //
while (valid == false) {
	cout << "--> Enter a the key number" << endl;
	cout << "--> ";
	cin >> key;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout << "!!!*** You can only enter a number [1..24] ***!!!";
		continue;
	}
	if (key > 24 || key < 1) 
		cout << "!!!*** Invalid key. Key should be between[1..24] ***!!!\n";
	else valid = true;
}


cout << "--> The encrypted message <--\n--> ";
cout << encrypted_msg << endl;

// Decrypting //
	for (int i = 0; i < encrypted_msg.length(); i++){

		ascii_val = int(encrypted_msg[i]);

		if (low_upp_not(ascii_val) == 0){
			if (ascii_val - key < 97) bf_msg += char(ascii_val - key + 26);
			else bf_msg += char(ascii_val - key);
		}
		else if (low_upp_not(ascii_val) == 1){
			if (ascii_val - key < 65 ) bf_msg += char(ascii_val - key + 26);
			else bf_msg += char(ascii_val - key);
		}
		else bf_msg += encrypted_msg[i];
	}

	cout << "--> key = " << key << endl;
	cout << "--> decrypted msg = " << bf_msg << "\n\n";
	bf_msg = "";

return 0;
}
