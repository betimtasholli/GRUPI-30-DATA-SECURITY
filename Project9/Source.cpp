#include <iostream>
#include <string>
#include <algorithm>
#include "morseCode.cpp"
#include "tapCode.cpp"
#include "caesar.cpp"
#include "createUser.cpp"
#include "deleteUser.cpp"
#include "exportKey.cpp"
#include "importKey.cpp"
#include "writeMessage&readMessage.cpp"

using namespace std;

int main() {
	
	cout << "Zgjedheni komanden qe i'u nevojitet: \n"
		"Shtypni 1 per komanden Morse Code.\nShtypni 2 per komanden Tap-Code.\n"
		"Shtypni 3 per komanden Caesar.\nShtypni 4 per komanden Create-User.\n"
		"Shtypni 5 per komanden Delete-User.\nShtypni 6 per komanden Export-Key.\n"
		"Shtypni 7 per komanden Import-Key.\nShtypni 8 per komanden Write-Message.\n"
		"Shtypni 9 per komanden Read-Message\n\n";
			

	string komanda;
	getline(cin, komanda);

	if (komanda == "1"){
		morseCodeText();
		cout << endl << endl;
	}
	else if (komanda == "2"){
		tapCodeText();
		cout << endl << endl;
	}
	else if (komanda == "3"){
		caesarText();
		cout << endl << endl;
	}
	else if (komanda == "4"){
		createUser();
		cout << endl << endl;
	}
	else if (komanda == "5"){
		deleteUser();
		cout << endl << endl;
	}
	else if (komanda == "6"){
		exportKey();
		cout << endl << endl;
	}
	else if (komanda == "7"){
		importKey();
		cout << endl << endl;
	}
	else if (komanda == "8"){
		writeMessage();
		cout << endl << endl;
	}
	else if (komanda == "9") {
		readMessage();
		cout << endl << endl;
	}
	else{
		cout << "Keni shtypur dicka gabim. " << endl << endl;
	}

	return 0;
}

