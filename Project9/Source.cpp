#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void encryptToMorseCode() {
	const char shkronjat[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	const string morseCode[37] = { "    ", ". ___", "___ . . .", "___ . ___ .", "___ . .", ".", ". . ___ .", "___ ___ .", ". . . .", ". .", ". ___ ___ ___", "___ . ___", ". ___ . .",  "___ ___", "___ .", "___ ___ ___", ". ___ ___ .", "___ ___ . ___", ". ___ .", ". . .", "_", ". . ___", ". . . ___", ". ___ ___", "___ . . ___", "___ . ___ ___", "___ ___ . .", ". ___ ___ ___ ___", ". . ___ ___ ___", ". . . ___ ___", ". . . . ___", ". . . . .", "___ . . . .", "___ ___ . . .", "___ ___ ___ . .", "___ ___ ___ ___ .", "___ ___ ___ ___ ___" };
	string textToChange = "";
	string newText = "";

	cout << "Shkruani tekstin qe doni ta shendrroni ne Morse Code: " << endl;
	getline(cin, textToChange);
	transform(textToChange.begin(), textToChange.end(), textToChange.begin(), ::tolower);
	// ne kete rast funksioni transform i shenderron shkronjat e medha ne shkronja te vogla

	for (unsigned int i = 0; i < textToChange.size(); i++) {
		for (unsigned short j = 0; j < 37; j++) {
			if (textToChange[i] == shkronjat[j]) {
				newText += morseCode[j];
				newText += "   ";
				break;
			}
		}
	}

	cout << "Kodi ne Morse Code: " << endl << newText;
	int a;
	cin >> a;
}

void decryptFromMorseCode() {
	const char shkronjat[37] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	const string morseCode[37] = { "    ", ". ___", "___ . . .", "___ . ___ .", "___ . .", ".", ". . ___ .", "___ ___ .", ". . . .", ". .", ". ___ ___ ___", "___ . ___", ". ___ . .",  "___ ___", "___ .", "___ ___ ___", ". ___ ___ .", "___ ___ . ___", ". ___ .", ". . .", "_", ". . ___", ". . . ___", ". ___ ___", "___ . . ___", "___ . ___ ___", "___ ___ . .", ". ___ ___ ___ ___", ". . ___ ___ ___", ". . . ___ ___", ". . . . ___", ". . . . .", "___ . . . .", "___ ___ . . .", "___ ___ ___ . .", "___ ___ ___ ___ .", "___ ___ ___ ___ ___" };
	string textToChange = "";
	string newText = "";

	cout << "Shkruani kodin qe doni ta ktheni ne text: " << endl;
	getline(cin, textToChange);
	transform(textToChange.begin(), textToChange.end(), textToChange.begin(), ::tolower);
	// ne kete rast funksioni transform i shenderron shkronjat e medha ne shkronja te vogla

	for (unsigned int i = 0; i < textToChange.size(); i++) {
		for (unsigned short j = 0; j < 37; j++) {
			if (textToChange[i] == shkronjat[j]) {
				newText += shkronjat[j];
				newText += "   ";
				break;
			}
		}
	}

	cout << "Teksti: " << endl << newText;
	int a;
	cin >> a;
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

int main() {
	string bo;
	string bo1 = "Shtypni 1 per komanden Morse Code.";
	string bo2 = "Shtypni 2 per komanden Tap-Code.";
	string bo3 = "Shtypni 3 per komanden Caesar.";

	cout << "Zgjedheni komanden qe i'u nevojitet: " << endl;
	cout << bo1 << endl;
	cout << bo2 << endl;
	cout << bo3 << endl << endl;

	getline(cin, bo);

	if (bo == "1")
	{
		morseCodeText();
		cout << endl << endl;
	}
	else if (bo == "2")
	{
		cout << endl << endl;
	}
	else if (bo == "3")
	{
		cout << endl << endl;
	}
	else
	{
		cout << "Keni shtypur dicka gabim. " << endl << endl;
	}

	return 0;
}

/* credits: http://theflyingkeyboard.net/c/c-string-to-morse-code/ 
            https://en.wikipedia.org/wiki/Morse_code      
			https://www.youtube.com/watch?v=xsDk5_bktFo
			*/