#include <iostream>
#include <string>
#include <algorithm>

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