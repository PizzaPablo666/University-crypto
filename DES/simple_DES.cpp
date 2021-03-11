#include <iostream>
using namespace std;

void k_rearrenge1(string &k)
{
	string kk = k;

	k[0] = kk[2];
	k[1] = kk[4];
	k[2] = kk[1];
	k[3] = kk[6];
	k[4] = kk[3];
	k[5] = kk[9];
	k[6] = kk[0];
	k[7] = kk[8];
	k[8] = kk[7];
	k[9] = kk[5];
}

void shifting_by_n(string &k, int n)
{
	string kk = k;

	if (k.length() == 10) {
		while (n--)
		{
			k[0] = kk[1];
			k[1] = kk[2];
			k[2] = kk[3];
			k[3] = kk[4];
			k[4] = kk[0];
	
			k[5] = kk[6];
			k[6] = kk[7];
			k[7] = kk[8];
			k[8] = kk[9];
			k[9] = kk[5];
	
			kk = k;
		}
	}
	else  {
		while (n--)
		{
			k[0] = kk[1];
			k[1] = kk[2];
			k[2] = kk[3];
			k[3] = kk[0];
	
			kk = k;
		}
	}

}

void compression(string &k)
{
	string kk = k;
	
	k[0] = kk[5];
	k[1] = kk[2];
	k[2] = kk[6];
	k[3] = kk[3];
	k[4] = kk[7];
	k[5] = kk[4];
	k[6] = kk[9];
	k[7] = kk[8];
	k[8] = '\0';
	k[9] = '\0';
}

void start_rearrenge(string &m)
{
	string mm = m;
	
	m[0] = mm[1];	
	m[1] = mm[5];	
	m[2] = mm[2];	
	m[3] = mm[0];	
	m[4] = mm[3];	
	m[5] = mm[7];	
	m[6] = mm[4];	
	m[7] = mm[6];	
}

void extract(string &r0)
{
	string rr = r0;
	
	r0 = "";
	r0 += rr[3];
	r0 += rr[0];
	r0 += rr[1];
	r0 += rr[2];
	r0 += rr[1];
	r0 += rr[2];
	r0 += rr[3];
	r0 += rr[0];
}

void f1(string r0, string k1, string &r1)
{
	int i = 0, ind1, ind2 ;
	char arr1[4][4] = {{'1', '0', '3', '2'},
			{'3', '2', '1', '0'},
			{'0', '2', '1', '3'},
			{'3', '1', '3', '2'}};

	char arr2[4][4] = {{'0', '1', '2', '3'},
			{'2', '0', '1', '3'},
			{'3', '0', '1', '0'},
			{'2', '1', '0', '3'}};
	
	// Doing XOR R0 extracted and key	
	while (i < 8)
	{
		r1 += ((r0[i] - '0') ^ (k1[i] - '0')) + '0';
		i++;
	}

	if (r1[0] == '0' && r1[3] == '0') ind1 = 0;
	else if (r1[0] == '0' && r1[3] == '1') ind1 = 1;
	else if (r1[0] == '1' && r1[3] == '0') ind1 = 2;
	else if(r1[0] == '1' && r1[3] == '1') ind1 = 3;

	if (r1[1] == '0' && r1[2] == '0') ind2 = 0;
	else if (r1[1] == '0' && r1[2] == '1') ind2 = 1;
	else if (r1[1] == '1' && r1[2] == '0') ind2 = 2;
	else if(r1[1] == '1' && r1[2] == '1') ind2 = 3;

	ind1 = arr1[ind1][ind2] - '0';
	if(ind1 == 0) { r1[0] = '0'; r1[1] = '0'; }
	else if(ind1 == 1) { r1[0] = '0'; r1[1] = '1'; }
	else if(ind1 == 2) { r1[0] = '1'; r1[1] = '0'; }
	else if(ind1 == 3) { r1[0] = '1'; r1[1] = '1'; }

	if (r1[4] == '0' && r1[7] == '0') ind1 = 0;
	else if (r1[4] == '0' && r1[7] == '1') ind1 = 1;
	else if (r1[4] == '1' && r1[7] == '0') ind1 = 2;
	else if(r1[4] == '1' && r1[7] == '1') ind1 = 3;

	if (r1[5] == '0' && r1[6] == '0') ind2 = 0;
	else if (r1[5] == '0' && r1[6] == '1') ind2 = 1;
	else if (r1[5] == '1' && r1[6] == '0') ind2 = 2;
	else if(r1[5] == '1' && r1[6] == '1') ind2 = 3;

	ind1 = arr2[ind1][ind2] - '0';
	if(ind1 == 0) { r1[2] = '0'; r1[3] = '0'; }
	if(ind1 == 1) { r1[2] = '0'; r1[3] = '1'; }
	if(ind1 == 2) { r1[2] = '1'; r1[3] = '0'; }
	if(ind1 == 3) { r1[2] = '1'; r1[3] = '1'; }

	ind1 = 4; 
	while (ind1 <= 8)
	{
		r1[ind1] = '\0';
		ind1++;
	}
	shifting_by_n(r1, 1);
}

void rearrenge_last(string r2, string l2, string &encrypted)
{
	string enc = encrypted;

	encrypted += l2[3];
	encrypted += l2[0];
	encrypted += l2[2];
	encrypted += r2[0];
	encrypted += r2[2];
	encrypted += l2[1];
	encrypted += r2[3];
	encrypted += r2[1];
}
int main()
{
	string m, k, k1, k2;


// ----------- GETTING TWO 8 BIT KEYS FROM 10 BIT KEY ---------------- //	
	// Input the key and message you want to encrypt
	cout << "message = ";
	cin >> m;
	cout << "key = ";
	cin >> k;

	// Rearrengement 3 5 2 7 4 10 1 9 8 6
	k_rearrenge1(k);
	
	// Shifting by 1
	shifting_by_n(k, 1);

	// Compression and creating first key
	k1 = k;
	compression(k1);
	cout << "key 1 = " << k1 << endl;	

	// Shifting by 2
	shifting_by_n(k, 2);
	
	// Compressing and creating second key
	k2 = k;
	compression(k2);
	cout << "key 2 = " << k2 << endl;

// -------- ENCRYPTING THE MESSAGE -------------- //
	
	// --------- ROUND 1 ------------ //
	
	string r1 = "", l1 = "", l0 = "", l2 = "", r2 = "", encrypted = "";
	int i = 0;

	// Starting rearrengment
	start_rearrenge(m); 	

	while (i < 4)
	{
		l0 += m[i];
		i++;
	}
	while (i < 9 )
	{
		l1 += m[i];
		i++;
	}

	// Extracting
	extract(l1);

	// Function
	f1(l1, k1, r1);

	//XOR L0 and R1
	i = 0;
	while (i < 4)
	{

		r1[i] = ((r1[i] - '0') ^ (l0[i] - '0')) + '0'; 
		l1[i + 4] = '\0';
		i++;
	}
	cout << "r1 = " << r1 << endl;
	cout << "l1 = " << l1 << endl;

	// --------- ROUND 2 ------------ //
	
	// Extracting
	r2 = r1;
	extract(r1);

	//Function 
	f1(r1, k2, l2);	

	// L1 XOR L2
	i = 0;
	while (i < 4)
	{

		l2[i] = ((l2[i] - '0') ^ (l1[i] - '0')) + '0'; 
		r2[i + 4] = '\0';
		i++;
	}
	cout << "r2 = " << r2 << endl;
	cout << "l2 = " << l2 << endl;
	
	//Rearrenging Last one
	rearrenge_last(r2, l2, encrypted);
	cout << "encrypted message = " << encrypted << endl;
}
