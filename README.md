"# GRUPI-30-DATA-SECURITY" 

===========================================================================

                                         FAZA I

Të dhëna mbi programin

Ky program të cilin e kemi koduar në gjuhën programuese C++, sherben per enkriptimin dhe dekriptimin e të dhënave në tri mënyra të ndryshme:
             1. Morse Code
             2. Tap Code
             3. Caesar

Morse Code -
Kodi Morse është një lloj alfabeti, ose sistem komunikimi me telegraf, i cili përbëhet nga pika dhe viza të bashkërenduara në grupe, që ju përgjigjen shkronjave ose numrave të caktuar (karaktere alfanumerike), krijuar nga Samuel Morse.

Tap Code -
Tap code është një metodë e enkriptimit të të dhënave shkronjë më shkronjë, ku mesazhi transmetohet duke i lëshuar një seri zërash. Kjo metodë është përdorur nga tē burgosurit për të komunikuar mes veti.

Caesar -
Në kriptimin e Cezarit secila shkronjë e tekstit të pakriptuar (anglisht: plaintext) zhvendoset për tri vende, kështu A zëvendësohet me D, B zëvendësohet me E e kështu me radhë. Këtë metodë e ka perdorur Caesari në kohërat e lashta, tani kodi i Caesarit është lehtë i thyeshëm, por në atë kohë ishte mjaftë efikas.

===========================================================================

Pëshkrimi i komandave

1. EncryptMorseCode - e merr tekstin si plaintext me anë të qelsit e kthen ne pika dhe viza, pra në morse code, ose në cyphertext.

2. DecryptMorseCode - e merr cyphertextin me pika dhe viza dhe e kthen ne text te lexueshem, pra plaintext.

3. EncryptTapCode - e merr tekstin si plain tekst dhe me ane te tabeles se tap code e kthen ne pika per secilin karakter pra ne tap code ose cyphertext.

4. DecryptTapCode - e merr cyphertextin ne forme te pikave dhe sipas tabeles e kthen ne tekst te lexueshem.

5. EncryptCaesar - e merr tekstin si plaintext dhe cdo shkronje e zhvendose per nje numer te caktuar shkronjash djathtas.

6. DecryptCaesar - e merr cyphertextin dhe cdo shkronje e zhvendose per nje numer te caktuar shkronjash majtas.

===========================================================================

Rezultatet e ekzekutimit me nga një shembull për secilën komandë dhe nënkomandë.

MORSE CODE -

1. Enkriptimi me Morse code  
Shkruani tekstin qe doni ta ktheni ne morse code: egzon gashi fiek 2020  
Enkriptimi: . --. --.. --- -. / --. .- ... .... .. / ..-. .. . -.- / ..--- ----- ..--- -----   

2. Dekriptimi me Morse code  
Shkruani nje nga nje secilin karakter qe keni ne morse code:  
Karakteri numer 1: .  
Karakteri numer 2: --.  
Karakteri numer 3: --..  
Katakteri numer 4: ---  
Karakteri numer 5: -.  
Dekriptimi: egzon  

TAP CODE -  

1. Enkriptimi me tap code  
Shkruani tekstin qe doni ta ktheni ne tap code: albin  
Enkriptimi: ._.  ..._.  ._..  .._....  ..._...  

2. Shkruani nje nga nje secilin karakter qe keni ne tap code:  
Karakteri numer 1: ._.  
Karakteri numer 2: ..._.  
Karakteri numer 3: ._..  
Katakteri numer 4: .._....  
Karakteri numer 5: ..._...  
Dekriptimi: albin  
  
CAESAR -  
  
1. Enkriptimi me Caesar  
Shkruani tekstin qe deshironi ta enkriptoni: betim   
Shkruani numrin e zhvendosjes : 1  
Enkriptimi : cfujn  
  
2. Dekriptimi me Caesar  
Shenoni mesazhin qe deshironi ta dekriptoni: gblvmmufuj j joyijojfsjtf lpnqkvufsjlf  
Shenoni numrin e zhvendosjes: 1  
Dekriptimi: fakullteti i inxhinierise kompjuterike  

===========================================================================

                                         FAZA II

Ne kuader te kesaj faze, programin e shkruar e kemi zgjeruar duke i'a shtuar edhe disa komanda te tjera qe perfshijne nje komande per 
te krijuar nje perdorues, nje komande per te fshire nje perdorues, nje komande per te eksportuar nje qeles, nje komande per te importuar
nje qeles, nje komande per ti derguar nje mesazh nje perdoruesi dhe nje komande per ta dekriptuar ate mesazh.

Komandat e shtuara jane:

1. create-user
2. delete-user
3. export-key
4. import-key
5. write-message
6. read-message

===========================================================================

Pershkrimi i komandave

1. Komanda create-user krijon një çift të publik/privat të RSA me emrat <name>.pem dhe <name>.pub.pem brenda direktoriumit të çelësave keys.

2. Komanda delete-user i largon të gjithë çelësat ekzistues të shfrytëzuesit.

3. Komanda export-key eksporton çelësin publik ose privat të shfrytëzuesit nga direktoriumi i çelësave.

4. Komanda import-key importon çelësin publik ose privat të shfrytëzuesit nga shtegu i dhënë dhe e vendos në direktoriumin e çelësave.

5. Komanda write-message e shkruan një mesazh të enkriptuar të dedikuar për një shfrytëzues.

6. Komanda read-message e dekripton dhe e shfaq në console mesazhin e enkriptuar ose e ruan ne nje path te caktuar.

===========================================================================

Rezultatet e ekzekutimit me nga një shembull për secilën komandë.  

create-user -  

$ds create user albin  
Eshte krijuar celesi privat 'keys/albin.pem'.  
Eshte krijuar celesi publik 'keys/albin.pub.pem.  

delete-user -  

$ds delete user albin  
Eshte fshire celesi privat 'keys/albin.pem'.  
Eshte fshire celesi publik 'keys/albin.pub.pem'.  

export-key -  

$ds export key public albin C:\\Users\\HP\\Desktop\\albin.pem  
Celesi publik u ruajt ne fajllin 'C:\\Users\\HP\\Desktop\\albin.pem'.  

import-key -   

$ ds import-key albin C:\\Users\\HP\\Desktop\\somekey.pub.pem  
Celesi publik u ruajt ne fajllin 'C:\\Users\\HP\\Desktop\\keys\\albin.pub.pem'.  

write-message -  

$ ds write-message egzon takimi_mbahet_ne_ora_2_mos_eja  
ZWd6b24=.MTIzNDEyMzQ=.MDAwMDExMTE=.dGFraW1pX21iYWhldF9uZV9vcmFfMl9tb3NfZWph.  

read-message -  

$ ds read-message ZWd6b24=.MTIzNDEyMzQ=.MDAwMDExMTE=.dGFraW1pX21iYWhldF9uZV9vcmFfMl9tb3NfZWph.  
Marresi: egzon  
Mesazhi: takimi_mbahet_ne_ora_2_mos_eja  


===========================================================================

Credits:

Base64
https://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp/

OpenSSL
https://www.openssl.org/

Fstream
http://www.cplusplus.com/reference/fstream/fstream/

Gjetja e file-size
https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c/40879144#40879144

String to array
https://stackoverflow.com/questions/17956939/array-size-and-split-of-string

Sstream
http://www.cplusplus.com/reference/sstream/

Gjenerimi i RSA keys
https://stackoverflow.com/questions/38582334/use-openssl-in-cbuilder?noredirect=1&lq=1

Ofstream
http://www.cplusplus.com/reference/fstream/ofstream/

Ifstream
http://www.cplusplus.com/reference/fstream/ifstream/

Caesar code
http://practicalcryptography.com/ciphers/caesar-cipher/
https://www.tutorialspoint.com/cplusplus-program-to-implement-caesar-cypher

Tap code
https://en.wikipedia.org/wiki/Tap_code

Morse code
https://www.geeksforgeeks.org/morse-code-implementation/
