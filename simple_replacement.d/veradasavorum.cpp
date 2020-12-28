#include <iostream>
#include <string>
#include <cstring>
#include <climits>
using namespace std;


void lowercase (string& text)
{
	for (int i = 0; i < text.length(); i++)
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] = tolower(text[i]);
}

void signs(string& text)
{
	for (int i = 0; i < text.length(); i++)
		if (text[i] < 'a' || text[i] > 'z')
			text.erase(i, 1);
}

char gen_rand_letter()
{
    int n = rand() % 26;
    char c = (char)(n + 97);
    return c;
}

int main()
{
	string  option = "";
	string	text = "";
	string	cipher = "";
	int	key;
	bool	valid = false;
	int 	mnacord = 0;
	int	row = 0;

	while (option != "encrypt" && option != "decrypt")
	{
		cout << "\nDo you want to encrypt or decrypt ? \n";
		cin >> option;
	}
	if(option == "encrypt")
	{
		cout << "\nEnter the text you want to encrypt\n";
		
		// Get the text
		cin.ignore();
		getline(cin,text,'\n');

		// Get the key
		cout << "\nEnter the key\n";
		while (valid == false)
		{
			cin >> key;
			if(cin.fail()) 
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Enter a valid number\n";
				continue;
			}
			if (key < 1 || key > text.length())
				cout << "Enter a valid number\n";
			else valid = true;
		}

		// Filtering
		lowercase(text);
		signs(text);

		cout << "Text = " << text << endl;
		cout << "Key = " << key << endl;

		mnacord = key - (text.length() % key);

		// Fill with random letters until mnacord = 0
		while (mnacord != 0)
		{
			text += gen_rand_letter();
			mnacord--;
		}
		row = text.length() / key;

		int i = 0;
		int j = 0;


		for (i = 0; i < key; i++)
			for (j = i; j < text.length(); j+=key)
				cipher += text[j];
		cout << "Cipher =  " << cipher << endl;

		}
	else if(option == "decrypt")
	{
		cout << "\nEnter the text you want to dencrypt\n";
		
		// Get the text
		cin.ignore();
		getline(cin,text,'\n');

		// Get the key
		cout << "\nEnter the key\n";
		while (valid == false)
		{
			cin >> key;
			if(cin.fail()) 
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Enter a valid number\n";
				continue;
			}
			if (key < 1 || key > text.length())
				cout << "Enter a valid number\n";
			else valid = true;
		}
	row = text.length() / key;

		int i = 0;
		int j = 0;


		for (i = 0; i < row; i++)
			for (j = i; j < text.length(); j+=row)
				cipher += text[j];
		cout << "Cipher =  " << cipher << endl;


		
	}
}
