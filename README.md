# -Tema2-POO
TEMA: Biblioteca


Un sistem de gestionare a bibliotecilor unei universitati in care mai multe biblioteci sunt organizate la un loc printr-un catalog. Logica principala se bazeaza pe o ierarhie de tipuri de biblioteci, unde fiecare clasa derivata reprezinta o biblioteca specifica a unei facultati care își gestionează cărțile si rezervările.  Catalogul va conține toate cărțile si biblioteca in care se afla. Prin intermediul acestuia clienții își vor putea face rezervari.

Am creat clasele „Client”, „Rezervare” și „Carte”, pe care le-am folosit în ierarhie. Clasa de bază se numește „Biblioteca” și are ca parametri: numele, locația, un vector în care sunt stocate cărțile din bibliotecă și un vector în care sunt stocate rezervările. În această clasă am implementat mai multe funcții, printre care se află metode de afișare, de căutare a clienților, de realizare a rezervărilor etc.
Clasele derivate sunt: „bibliotecaFMI”, „bibliotecaLitere”, „bibliotecaDrept” și „bibliotecaIstorie” (adăugată ulterior). Pentru a gestiona toate bibliotecile, am creat clasa „Catalog”, în care se află un vector de pointeri la clasa de bază. Cu ajutorul catalogului se realizează acțiuni precum afișarea rezervărilor unei anumite biblioteci, adăugarea mai multor biblioteci etc.
În main, am început prin a crea catalogul și a adăuga în acesta bibliotecile și cărțile disponibile. Informațiile despre fiecare carte le-am citit din fișierul „carti.txt”. În acesta se află, pe fiecare rând, biblioteca corespunzătoare, numele cărții, autorul și anul apariției.
După aceea, clientul poate căuta o carte pentru a vedea unde și dacă este disponibilă. De asemenea, își poate face rezervări și poate alege să vadă rezervările de la biblioteca dorită. La finalul programului se afișează toate rezervările și numărul de biblioteci.

Nume pentru review: Lica Daria Ioana
