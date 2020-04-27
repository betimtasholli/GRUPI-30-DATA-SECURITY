#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <openssl/rsa.h> // Gjuha programuese C++ nuk ka librari build-in per kryptografi andaj kam perdorur openssl.
#include <openssl/pem.h>

using namespace std;

bool generate_key()   // Funksioni per gjenerimin e qelsave.
{
	int	ret = 0;
	RSA* r = NULL;
	BIGNUM* bne = NULL;
	BIO* bp_public = NULL, * bp_private = NULL;

	int	bits = 2048;
	unsigned long e = RSA_F4;

	bne = BN_new();   // Ketu e kemi gjeneruar RSA keys.
	ret = BN_set_word(bne, e);
	if (ret != 1) {
		goto free_all;
	}

	r = RSA_new();
	ret = RSA_generate_key_ex(r, bits, bne, NULL);
	if (ret != 1) {
		goto free_all;
	}

	bp_public = BIO_new_file("C:\\Users\\HP\\Desktop\\keys\\public.pem", "w+");   // Ketu e kemi rujatur qelsin publik.
	ret = PEM_write_bio_RSAPublicKey(bp_public, r);
	if (ret != 1) {
		goto free_all;
	}

	bp_private = BIO_new_file("C:\\Users\\HP\\Desktop\\keys\\private.pem", "w+");   // Ketu e kemi rujatur qelsin privat.
	ret = PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);

free_all:
	BIO_free_all(bp_public);
	BIO_free_all(bp_private);
	RSA_free(r);
	BN_free(bne);

	return (ret == 1);
}

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

        string path = "C:\\Users\\HP\\Desktop\\keys\\" + name + ".pem";   // E check-irat nese egziston ky file me kete emer.
        ifstream fin(path);

        if (fin.is_open()) {
            cout << "Gabim: Celesi " + name + " ekziston paraprakisht." << endl;
        }
        else {

			generate_key();   // Nese ai qeles nuk egziston dhe ai path i atij qelesi eshte ne rregull atehere i gjenerojme keys.

			string newpath = "C:\\Users\\HP\\Desktop\\keys\\" + name + ".pub.pem";
			int i;   // Ketu me eshte dashur qe nga string te kthej ne char sepse path-et nuk po lejojshin ne string te jepen.
			char array[60];
			for (i = 0; i < newpath.size(); i++) {
				array[i] = newpath[i];
			}
			array[i] = '\0';
			char oldpath[] = "C:\\Users\\HP\\Desktop\\keys\\public.pem";
			rename(oldpath, array);   // Ketu e kam bere rename file, per te iu pershtatur kerkesave nga projekti.

			string newpathprivate = "C:\\Users\\HP\\Desktop\\keys\\" + name + ".pem";
			int j;
			char arrayprivate[60];
			for (j = 0; j < newpathprivate.size(); j++) {
				arrayprivate[j] = newpathprivate[j];
			}
			arrayprivate[j] = '\0';
			char oldpathprivate[] = "C:\\Users\\HP\\Desktop\\keys\\private.pem";
			rename(oldpathprivate, arrayprivate);

            cout << "Eshte krijuar celesi privat 'keys/" + name + ".pem'. \nEshte krijuar celesi publik 'keys/" + name + ".pub.pem'." << endl;
        }
    }
}

	// Direktoriumet e files te pershtaten sikur ne PC tuaj.