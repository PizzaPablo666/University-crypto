#include <iostream>
#include <cctype>
#include <climits>
#include <string>
#include <fstream>

using namespace std;


int low_upp_not(int val){
	
	int res;

	if (val >= 65 && val <= 90) res = 1;
	else if (val >= 97 && val <= 122) res = 0;
	else res = 2;
	
	return res;
} 


int main(){

int key = 0, ascii_val = 0;
bool valid = false;
string message, encrypted_message = "";

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

// Entering message //
cout << "--> Enter a message in english language or it is not going to work\n--> ";
cin.ignore();
getline(cin, message, '\n');

// Encrypting //
for (int i = 0; i < message.length(); i++){
	ascii_val = int(message[i]);


	if (low_upp_not(ascii_val) == 0){
		if (ascii_val + key > 122) encrypted_message += char(ascii_val + key - 26);
		else encrypted_message += char(ascii_val + key);
	}
	else if (low_upp_not(ascii_val) == 1){
		if (ascii_val + key > 90) encrypted_message += char(ascii_val + key - 26);
		else encrypted_message += char(ascii_val + key);
	}
	else encrypted_message += message[i];
		 
}

// Outputting //
cout << "--> Encrypted message\n--> ";
cout << encrypted_message << endl;


// Writing in a file //
ofstream MyFile;
MyFile.open("encrypted.txt");
MyFile << encrypted_message;
MyFile.close();

return 0;
}




