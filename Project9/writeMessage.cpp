#include <iostream>
#include <string>
#include <sstream>
#include "libraries/base64.cpp"
#include "libraries/base64.h"

using namespace std;

void writeMessage() {

    string query;
    cout << endl << "Kujdes, tek mesazhi ne vend te hapesirave perdorni underline ( _ ) ."<<endl<< "ds write-message ";   // Ketu e japim kerkesen tone.
    getline(cin, query);
    cout << endl;

    string arr[3];   // Ketu string-in e kthejme ne string array, per qasje me te lehte.
    int i = 0;
    stringstream ssin(query);
    while (ssin.good() && i < 3) {
        ssin >> arr[i];
        ++i;
    }

    fstream file;
    file.open("C:\\Users\\HP\\Desktop\\keys\\" + arr[0] + ".pem");

    if (file.fail()) {   // Ketu e check-iratum nese ky file egziston.

        cout << "Gabim: Celesi publik '" + arr[0] + "' nuk ekziston." << endl;

    }
    else {
        string iv = "12345678";
        string key;
        cout << "Jepni vleren e key per enkriptimin e mesazhit me DES: ";
        cin >> key;

        string encodedArr0 = base64_encode(reinterpret_cast<const unsigned char*>(arr[0].c_str()), arr[0].length());
        string encodedIv = base64_encode(reinterpret_cast<const unsigned char*>(iv.c_str()), iv.length());
        string encodedKey = base64_encode(reinterpret_cast<const unsigned char*>(key.c_str()), key.length());
        string encodedArr1 = base64_encode(reinterpret_cast<const unsigned char*>(arr[1].c_str()), arr[1].length());

        if (arr[2] == "") {
            
            cout << encodedArr0 << "." <<encodedIv << "." << encodedKey << "." << encodedArr1 << "." << endl;

        }
        else {
            ofstream outfile(arr[2]);   // Krijojme dhe shkruajme ne kete file.
            outfile << encodedArr0 << "." << encodedIv << "." << encodedKey << "." << encodedArr1 << "." << endl;
            outfile.close();

            cout << "Mesazhi i enkriptuar u ruajt ne fajllin '" + arr[2] +"'." << endl;
        }
    }

}