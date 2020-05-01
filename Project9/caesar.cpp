#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void caesarEncrypt() {
	char message[100], ch;
	int i, key;

	cout << "Shenoni mesazhin qe deshironi te enkriptoni: ";
	cin.getline(message, 100);
	cout << "Shenoni numrin e zhvendosjes: ";
	cin >> key;

	for (i = 0; message[i] != '\0'; ++i) {
		ch = message[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;

			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}

			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;

			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}

			message[i] = ch;
		}
	}

	cout << "Mesazhi i enkriptuar: " << message;

}

void caesarDecrypt() {
	char message[100], ch;
	int i, key;

	cout << "Shenoni mesazhin qe deshironi ta dekriptoni: ";
	cin.getline(message, 100);
	cout << "Shenoni numrin e zhvendosjes: ";
	cin >> key;

	for (i = 0; message[i] != '\0'; ++i) {
		ch = message[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;

			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}

			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;

			if (ch > 'a') {
				ch = ch + 'Z' - 'A' + 1;
			}

			message[i] = ch;
		}
	}

	cout << "Mesazhi i dekriptuar: " << message;


}
void caesarText() {
	string po;
	string x1 = "Shtypni 1 nese deshironi te enkodoni: tekst ---> caesar code.";
	string x2 = "Shtypni 2 nese deshironi te dekodoni: caesar code ---> text.";

	cout << endl << "Zgjedheni se cfare enkodimi deshironi qe te beni:  " << endl;
	cout << x1 << endl;
	cout << x2 << endl << endl;
	getline(cin, po);
	cout << endl;

	if (po == "1")
	{
		caesarEncrypt();
	}
	else if (po == "2")
	{
		caesarDecrypt();
	}
	else
	{
		cout << "Keni shtypur diqka gabim! " << endl;
	}

}