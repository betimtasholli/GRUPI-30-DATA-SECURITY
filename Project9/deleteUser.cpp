#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void deleteUser() {

	string name;
	cout << endl << "$ds delete user ";
	getline(cin, name);

	string deletepath = "C:\\Users\\ACER\\Desktop\\keys\\" + name + ".pem";
	int i;
	char array[60];
	for (i = 0; i < deletepath.size(); i++) {
		array[i] = deletepath[i];
	}
	array[i] = '\0';

	string deletepathpub = "C:\\Users\\ACER\\Desktop\\keys\\" + name + ".pub.pem";
	int j;
	char arraypub[60];
	for (j = 0; j < deletepathpub.size(); j++) {
		arraypub[j] = deletepathpub[j];
	}
	arraypub[j] = '\0';


	int status;   // Fshirja e Celsave privat.
	status = remove(array);
	if (status == 0)
	{
		cout << "Eshte larguar celesi privat 'keys/" << name << ".pem'\n";
	}
	else
	{
		cout << "Gabim: Celesi privat '" << name << "' nuk ekziston.\n";
	}


	int statuspub;   // Fshirja e Celsave publik.
	statuspub = remove(arraypub);
	if (statuspub == 0)
	{
		cout << "Eshte larguar celesi publik 'keys/" << name << ".pub.pem'\n";
	}
	else
	{
		cout << "Gabim: Celesi publik '" << name << "' nuk ekziston.\n";
	}

}