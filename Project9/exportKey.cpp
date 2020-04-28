#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void exportKey() {

	string query;
	cout << endl << "ds export-key ";   // Ketu e japim kerkesen tone.
    getline(cin, query);
    cout << endl;

    string arr[3];   // Ketu string-in e kthejme ne string array, per qasje me te lehte.
    int i = 0;
    stringstream ssin(query);
    while (ssin.good() && i < 3) {
        ssin >> arr[i];
        ++i;
    }
    
    if (arr[0] == "public") {   // Nese e kerkojme celsin public.
        if (arr[2] == "") {   // Nese pjesa [file] nuk eshte kerkuar.
            ifstream f("C:\\Users\\ACER\\Desktop\\keys\\" + arr[1] + ".pub.pem");

            if (f.is_open()) {   // Atehere vetem e lexojme celsin public.
                cout << f.rdbuf();
            }
            else {
                cout << "Gabim: Celesi public '" + arr[1] + "' nuk ekziston." << endl;
            }
        }
        else {   // Nese pjesa [file] eshte kerkuar.
            ifstream fin;
            fin.open("C:\\Users\\ACER\\Desktop\\keys\\" + arr[1] + ".pub.pem");
            ofstream fout;
            fout.open(arr[2]);   // File-in bejme export ne nje path qe e zgjedhim ne vet.
            char ch;
            while (!fin.eof()) {
                fin.get(ch);
                fout << ch;
            }
            fin.close();
            
            cout << "Celesi public u ruajt ne " + arr[2] <<"."<< endl;
        }
   }


    else if (arr[0] == "private") {   // Nese e kerkojme celsin private.
        if (arr[2] == "") {
            ifstream f("C:\\Users\\ACER\\Desktop\\keys\\" + arr[1] + ".pem");

            if (f.is_open()) {
                cout << f.rdbuf();
            }
            else {
                cout << "Gabim: Celesi private '" + arr[1] + "' nuk ekziston." << endl;
            }
        }
        else {
            ifstream fin;
            fin.open("C:\\Users\\ACER\\Desktop\\keys\\" + arr[1] + ".pem");
            ofstream fout;
            fout.open(arr[2]);
            char ch;
            while (!fin.eof()) {
                fin.get(ch);
                fout << ch;
            }
            fin.close();

            cout << "Celesi private u ruajt ne " + arr[2] << "." << endl;
        }
    }

    else {
        cout << "Diqka gabim!" << endl;
    }

}
