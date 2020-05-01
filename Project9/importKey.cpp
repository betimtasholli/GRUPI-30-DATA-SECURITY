#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
using namespace std;

int fileSize(const char* add) {   // Do e perdorim kete funksion per te determinuar file size.
    ifstream mySource;   // Me ane te ketij funksioni do e kuptojme se a eshte public apo private key.
    mySource.open(add, ios_base::binary);
    mySource.seekg(0, ios_base::end);
    int size = mySource.tellg();
    mySource.close();
    return size;
}

void importKey() {
    string query;
    cout << endl << "ds import-key ";   // Ketu e japim kerkesen tone.
    getline(cin, query);
    cout << endl;

    string arr[2];   // Ketu string-in e kthejme ne string array, per qasje me te lehte.
    int i = 0;
    stringstream ssin(query);
    while (ssin.good() && i < 2) {
        ssin >> arr[i];
        ++i;
    }

    string path = arr[1];   // Ketu nga string kam kthyer ne char sepse path-et nuk po lejojshin ne string te jepen.
    int q;
    char pathchar[60];
    for (q = 0; q < path.size(); q++) {
        pathchar[q] = path[q];
    }
    pathchar[q] = '\0';


    fstream file;
    file.open("C:\\Users\\HP\\Desktop\\keys\\" + arr[0] + ".pem");

    if (file.is_open()) {   // Ketu e check-iratum nese ky file egziston paraprakisht.

        cout << "Gabim: Celesi '" + arr[0] + "' ekziston paraprakisht." << endl;

    }

    else if (file.fail()) {   // Nese nuk egziston, atehere vazhdojme me bartjen.

        if (fileSize(pathchar) < 500) {   // Nese file eshte me i vogel se 500 bytes, konkludojme se eshte public key.
            ifstream fin;   // Pasi qe public keys qe te gjithe i kam shikuar dhe kane saktesisht 434 bytes.
            fin.open(arr[1]);
            ofstream fout;
            fout.open("C:\\Users\\HP\\Desktop\\keys\\" + arr[0] + ".pub.pem");   // File-in bejme import tek dikteriumi i keys.
            char ch;
            while (!fin.eof()) {
                fin.get(ch);
                fout << ch;
            }
            fin.close();

            cout << "Celesi publik u ruajt ne fajllin 'keys/" + arr[0] + ".pub.pem'" << endl;
        }

        else if ((fileSize(pathchar) > 500) && (fileSize(pathchar) < 8000)) {   // Nese file eshte me i madh se 500 bytes dhe me i vogel se 8000 bytes, atehere eshte private key.
            ifstream fin;
            fin.open(arr[1]);
            ofstream fout;
            fout.open("C:\\Users\\HP\\Desktop\\keys\\" + arr[0] + ".pem");
            char ch;
            while (!fin.eof()) {
                fin.get(ch);
                fout << ch;
            }
            fin.close();

            cout << "Celesi privat u ruajt ne fajllin 'keys/" + arr[0] + ".pem'" << endl;
            cout << "Celesi publik u ruajt ne fajllin 'keys/" + arr[0] + ".pub.pem'" << endl;

            generate_key();   // Krijimi i celesit publik, duke e pasur ate private.
            string generatePubPath = "C:\\Users\\HP\\Desktop\\keys\\" + arr[0] + ".pub.pem";
            int w;   // Ketu me eshte dashur qe nga string te kthej ne char sepse path-et nuk po lejojshin ne string te jepen.
            char alist[60];
            for (w = 0; w < generatePubPath.size(); w++) {
                alist[w] = generatePubPath[w];
            }
            alist[w] = '\0';
            char oldpath[] = "C:\\Users\\HP\\Desktop\\keys\\public.pem";
            rename(oldpath, alist);   // Ketu e kam bere rename file, per te iu pershtatur kerkesave nga projekti.
            remove("C:\\Users\\HP\\Desktop\\keys\\private.pem");
        }

        else if (fileSize(pathchar) > 8000) {
            cout << "Gabim: Fajlli i dhene nuk eshte celes valid." << endl;
        }

        else {
            cout << "Dicka gabim!" << endl;
        }

    }

}