#include <iostream>
#include <string>
#include <algorithm>
#include "createUser.cpp"
#include "deleteUser.cpp"
#include "exportKey.cpp"
using namespace std;

void encryptToMorseCode() {
	const char shkronjat[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
								 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
								 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	const string morseCode[37] = { "/", ".-", "-...","-.-.", "-..", ".", "..-.", "--.", "....",
								   "..", ".---", "-.-", ".-..",  "--", "-.", "---", ".--.", "--.-",
								   ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
								   ".----", "..---", "...--", "....-", ".....", "-....", "--...",
								   "---..", "----.", "-----" };
	string textToChange = "";
	string newText = "";

	cout << "Shkruani Textin qe doni ta shendrroni ne Morse Code: ";
	getline(cin, textToChange);
	transform(textToChange.begin(), textToChange.end(), textToChange.begin(), ::tolower);
	// ne kete rast funksioni transform i shenderron shkronjat e medha ne shkronja te vogla

	for (unsigned int i = 0; i < textToChange.size(); i++) {
		for (unsigned short j = 0; j < 37; j++) {
			if (textToChange[i] == shkronjat[j]) {
				newText += morseCode[j];
				newText += " ";
				break;
			}
		}
	}

	cout << "Mesazhi i enkriptuar: " << newText;
}

void decryptFromMorseCode() {
	const char shkronjat[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
								 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
								 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	const string morseCode[37] = { "/", ".-", "-...","-.-.", "-..", ".", "..-.", "--.", "....",
								   "..", ".---", "-.-", ".-..",  "--", "-.", "---", ".--.", "--.-",
								   ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
								   ".----", "..---", "...--", "....-", ".....", "-....", "--...",
								   "---..", "----.", "-----" };

	int nrChar;
	cout << "Sa karaktere do kete teksti qe do ta ktheni ne kod mors: ";
	cin >> nrChar;
	cout << endl;

	string textToChange[150];
	string newText = "";

	cout << "Shkruani Morse Code-in qe doni ta shendrroni ne Text: " << endl;
	for (int i = 0; i < nrChar; i++) {
		cout << "Kodi mors i shkronjes numer " << i + 1 << ": ";
		cin >> textToChange[i];
	}

	for (unsigned int i = 0; i < nrChar; i++) {
		for (unsigned short j = 0; j < 37; j++) {
			if (textToChange[i] == morseCode[j]) {
				newText += shkronjat[j];
				newText += "";
				break;
			}
		}
	}

	cout << endl << "Mesazhi i dekriptuar: " << newText;
}

void morseCodeText() {

	string po;
	string x1 = "Shtypni 1 nese deshironi te enkodoni: tekst ---> morse code.";
	string x2 = "Shtypni 2 nese deshironi te dekodoni: morse code ---> text.";

	cout << endl << "Zgjedheni se cfare enkodimi deshironi qe te beni:  " << endl;
	cout << x1 << endl;
	cout << x2 << endl << endl;
	getline(cin, po);
	cout << endl;

	if (po == "1")
	{
		encryptToMorseCode();
	}
	else if (po == "2")
	{
		decryptFromMorseCode();
	}
	else
	{
		cout << "Keni shtypur diqka gabim! " << endl;
	}
}


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
int main() {
	string bo;
	string bo1 = "Shtypni 1 per komanden Morse Code.";
	string bo2 = "Shtypni 2 per komanden Tap-Code.";
	string bo3 = "Shtypni 3 per komanden Caesar.";
	string bo4 = "Shtypni 4 per komanden Create-User.";
	string bo5 = "Shtypni 5 per komanden Delete-User.";
	string bo6 = "Shtypni 6 per komanden Export-Key.";

	cout << "Zgjedheni komanden qe i'u nevojitet: " << endl;
	cout << bo1 << endl;
	cout << bo2 << endl;
	cout << bo3 << endl;
	cout << bo4 << endl;
	cout << bo5 << endl;
	cout << bo6 << endl << endl;

	getline(cin, bo);

	if (bo == "1")
	{
		morseCodeText();
		cout << endl << endl;
	}
	else if (bo == "2")
	{
		tapCodeText();
		cout << endl << endl;
	}
	else if (bo == "3")
	{
		caesarText();
		cout << endl << endl;
	}
	else if (bo == "4")
	{
		createUser();
		cout << endl << endl;
	}
	else if (bo == "5")
	{
		deleteUser();
		cout << endl << endl;
	}
	else if (bo == "6")
	{
		exportKey();
		cout << endl << endl;
	}
	else
	{
		cout << "Keni shtypur dicka gabim. " << endl << endl;
	}

	return 0;
}

