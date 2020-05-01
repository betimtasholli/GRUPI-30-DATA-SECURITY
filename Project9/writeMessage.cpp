#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void writeMessage() {

    string query;
    cout << endl << "ds write-message ";   // Ketu e japim kerkesen tone.
    getline(cin, query);
    cout << endl;

    string arr[3];   // Ketu string-in e kthejme ne string array, per qasje me te lehte.
    int i = 0;
    stringstream ssin(query);
    while (ssin.good() && i < 3) {
        ssin >> arr[i];
        ++i;
    }


    // to be continued ..........
}