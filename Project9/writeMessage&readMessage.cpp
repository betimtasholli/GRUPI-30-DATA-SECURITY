#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "libraries/base64.cpp"
#include "libraries/base64.h"

using namespace std;

void writeMessage() {

    string query;
    cout << endl << "Kujdes, tek mesazhi ne vend te hapesirave perdorni underline ( _ ) ." << endl << "ds write-message ";  // Ketu e japim kerkesen tone.
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
        string iv;
        cout << "Jepni vleren e IV: ";
        cin >> iv;

        string key;
        cout << "Jepni vleren e key per enkriptimin e mesazhit me DES: ";
        cin >> key;

        string encodedArr0 = base64_encode(reinterpret_cast<const unsigned char*>(arr[0].c_str()), arr[0].length());
        string encodedIv = base64_encode(reinterpret_cast<const unsigned char*>(iv.c_str()), iv.length());
        string encodedKey = base64_encode(reinterpret_cast<const unsigned char*>(key.c_str()), key.length());
        string encodedArr1 = base64_encode(reinterpret_cast<const unsigned char*>(arr[1].c_str()), arr[1].length());

        if (arr[2] == "") {
            
            cout << endl << encodedArr0 << "." <<encodedIv << "." << encodedKey << "." << encodedArr1 << "." << endl;

        }
        else {
            ofstream outfile(arr[2]);   // Krijojme dhe shkruajme ne kete file.
            outfile << encodedArr0 << "." << encodedIv << "." << encodedKey << "." << encodedArr1 << "." << endl;
            outfile.close();

            cout << "Mesazhi i enkriptuar u ruajt ne fajllin '" + arr[2] +"'." << endl;
        }
    }

}



void readMessage() {

    string query;
    cout << endl << "ds read-message ";   // Ketu e japim kerkesen tone.
    getline(cin, query);
    cout << endl;

    string sentence = query;   // E kemi ndare string-kerkesen ne vektor me ane te pikes (.).
    istringstream iss(sentence);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(iss, token, '.')) {
        if (!token.empty())
            tokens.push_back(token);
    }

    if (tokens.size() == 2) {   // Nese kerkesa ka vetem nje pike atehere i bie se eshte path.
        string  word;
        fstream file;

        file.open(query.c_str());
        while (file >> word)
        {
            cout << "Mesazhi i enkriptuar ne ate file: " << word << endl;
        }

        string sentence = word;
        istringstream iss(sentence);
        std::vector<std::string> tokens2;
        std::string token2;
        while (std::getline(iss, token2, '.')) {
            if (!token2.empty())
                tokens2.push_back(token2);
        }

        fstream file2;
        file2.open("C:\\Users\\HP\\Desktop\\keys\\" + base64_decode(tokens2[0]) + ".pem");

        if (file2.is_open()) {

            cout << "Marresi: " << base64_decode(tokens2[0]) << endl;
            cout << "Mesazhi: " << base64_decode(tokens2[3]) << endl;

        } else {
             cout << "Celesi privat 'C:\\Users\\HP\\Desktop\\keys\\" << base64_decode(tokens2[0]) << ".pem' nuk egziston." << endl;
        }
    }

    else {   // Nese kerkesa ka me shume pika atehere i bie se eshte vete mesazhi i enkriptuar.

        fstream file;
        file.open("C:\\Users\\HP\\Desktop\\keys\\" + base64_decode(tokens[0]) + ".pem");

        if (file.is_open()) {

            cout << "Marresi: " << base64_decode(tokens[0]) << endl;
            cout << "Mesazhi: " << base64_decode(tokens[3]) << endl;

        }

        else {
            cout << "Celesi privat 'C:\\Users\\HP\\Desktop\\keys\\" << base64_decode(tokens[0]) << ".pem' nuk egziston." << endl;
        }
    }
}
