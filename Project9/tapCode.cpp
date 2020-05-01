#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void encryptToTapCode() {
	const char karakteret[26] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l',
							 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	const string tapCode[26] = { "/", "._.", "._..","._...", "._....", "._.....",
									  ".._.", ".._..", ".._...",".._....", ".._.....",
									  "..._.", "..._..", "..._...", "..._....", "..._.....",
									  "...._.", "...._..","...._...", "...._....", "...._.....",
									  "....._.", "....._..", "....._...", "....._....", "....._....." };
	string	givenText = "";
	string encryptedText = "";

	cout << "Shkruani Textin qe doni ta shendrroni ne Tap Code: ";
	getline(cin, givenText);
	transform(givenText.begin(), givenText.end(), givenText.begin(), ::tolower);
	// ne kete rast funksioni transform i shenderron shkronjat e medha ne shkronja te vogla

	for (unsigned int i = 0; i < givenText.size(); i++) {
		for (unsigned short j = 0; j < 26; j++) {
			if (givenText[i] == karakteret[j]) {
				encryptedText += tapCode[j];
				encryptedText += "   ";
				break;
			}
		}
	}

	cout << "Mesazhi i enkriptuar: " << encryptedText;
}

void decryptFromTapCode() {
	const char karakteret[26] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l',
								 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	const string tapCode[26] = { "/", "._.", "._..","._...", "._....", "._.....",
									  ".._.", ".._..", ".._...",".._....", ".._.....",
									  "..._.", "..._..", "..._...", "..._....", "..._.....",
									  "...._.", "...._..","...._...", "...._....", "...._.....",
									  "....._.", "....._..", "....._...", "....._....", "....._....." };

	int nr;
	cout << "Sa karaktere do kete teksti qe do ta ktheni ne tap code: ";
	cin >> nr;
	cout << endl;

	string givenText[150];
	string decryptedText = "";

	cout << "Shkruani Tap Code-in qe doni ta shendrroni ne Text: " << endl;
	for (int i = 0; i < nr; i++) {
		cout << "Tap Code i shkronjes numer " << i + 1 << ": ";
		cin >> givenText[i];
	}

	for (unsigned int i = 0; i < nr; i++) {
		for (unsigned short j = 0; j < 37; j++) {
			if (givenText[i] == tapCode[j]) {
				decryptedText += karakteret[j];
				decryptedText += "";
				break;
			}
		}
	}

	cout << endl << "Mesazhi i dekriptuar: " << decryptedText;
}

void tapCodeText() {

	string po;
	string x1 = "Shtypni 1 nese deshironi te enkodoni: tekst ---> tap code.";
	string x2 = "Shtypni 2 nese deshironi te dekodoni: tap code ---> text.";

	cout << endl << "Zgjedheni se cfare enkodimi deshironi qe te beni:  " << endl;
	cout << x1 << endl;
	cout << x2 << endl << endl;
	getline(cin, po);
	cout << endl;

	if (po == "1")
	{
		encryptToTapCode();
	}
	else if (po == "2")
	{
		decryptFromTapCode();
	}
	else
	{
		cout << "Keni shtypur diqka gabim! " << endl;
	}
}
