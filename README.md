# AVL Sorter - Sortiranje riječi pomoću AVL stabla
Program demonstrira primjenu AVL stabla za leksikografsko sortiranje riječi iz tekstualnog fajla.
Program eliminiše duplikate, sortira riječi po abecednom redoslijedu i vrši dodatnu obradu kroz algoritme sortiranja dužina riječi.

## Funkcionalnosti
* Učitavanje riječi iz ulaznog fajla (ulaz1.txt, ulaz2.txt)
* Uklanjanje duplikata i zapisivanje u posebne fajlove (duplikati1.txt, duplikati2.txt)
* Formiranje AVL stabla na sljedeći način:
  * prva riječ se postavlja u korijen stabla
  * riječi koje su leksikografski veće idu u desno podstablo
  * riječi koje su leksikografski manje idu u lijevo podstablo
  * nakon svakog ubacivanja vrši se balansiranje stabla
* Ispis sortiranih riječi **inorder** obilaskom stabla
* Formiranje niza dužina riječi i njegovo sortiranje:
  * bubble sort algoritmom (rastući redoslijed)
  * insertion sort algoritmom (opadajući redoslijed)
* Prikaz ukupnog broja duplikata

## Primjer izvršavanja
```
SIMULACIJA BR.1

Rezultat inorder obilaska:
Ovo je kao koji koristi primjer se teksta zadatka.
--------------------------------------------------
Niz duzina: 3 2 3 4 7 7 2 6 8
--------------------------------------------------
Niz sortiran po rastucem redoslijedu:
2 2 3 3 4 6 7 7 8
--------------------------------------------------
Niz sortiran po opadajucem redoslijedu:
8 7 7 6 4 3 3 2 2
--------------------------------------------------
Broj duplikata: 1

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SIMULACIJA BR.2

Rezultat inorder obilaska:
Rijeci Test duplikate. i identifikuje ispravnosti kako pojavljuju poput program programa. provjere puta radi rijeci se sortira vise
--------------------------------------------------
Niz duzina: 6 4 10 1 12 11 4 10 5 7 9 8 4 4 6 2 7 4
--------------------------------------------------
Niz sortiran po rastucem redoslijedu:
1 2 4 4 4 4 4 5 6 6 7 7 8 9 10 10 11 12
--------------------------------------------------
Niz sortiran po opadajucem redoslijedu:
12 11 10 10 9 8 7 7 6 6 5 4 4 4 4 4 2 1
--------------------------------------------------
Broj duplikata: 3
```

## Napomena
Program razlikuje velika i mala slova pri poređenju riječi (case sensitive).

## Ključni algoritmi i strukture
* AVL stablo - balansirano binarno stablo pretrage
* Bubble sort
* Insertion sort
* Inorder traversal - inorder obilazak stabla

# Autorska prava
© 2025 Aleksandra Vučićević
