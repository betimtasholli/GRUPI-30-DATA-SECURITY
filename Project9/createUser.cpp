#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void createUser() {
    char characters[37] = { '_','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	string name;
	cout << endl << "$ds create user ";
	getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    int allowedchars = 0;
    for (int i = 0; i < name.length(); i++) {
        for (int j = 0; j < 37; j++) {
            if (name[i] == characters[j]) {
                allowedchars++;
            }
        }
    }

    if (allowedchars != name.length()) {
        cout << "Kujdes! Emrat duhet te permbajne vetem simbolet A-Z, a-z, 0-9, dhe _. Emrat nuk guxojne te permbajne hapesira." << endl;
    }
    else {
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        string path = name + ".xml";   // E check-irat nese egziston ky file me kete emer.
        ifstream fin(path);

        if (fin.is_open()) {
            cout << "Gabim: Celesi " + name + " ekziston paraprakisht." << endl;
        }
        else {
            cout << "Eshte krijuar celesi privat 'keys/" + name + ".xml'. \nEshte krijuar celesi publik 'keys/" + name + ".pub.xml'." << endl;
            ofstream MyFile("C:\\Users\\HP\\Desktop\\" + name + ".xml");   // Ketu krijohet file, celesi privat.
            ofstream MyFile2("C:\\Users\\HP\\Desktop\\" + name + ".pub.xml");   // Ketu krijohet file tjeter, celesi publik.
        }
    }
}
