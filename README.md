"# GRUPI-30-DATA-SECURITY" 

===========================================================================

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
