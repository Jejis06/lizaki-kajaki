--------------------------------------- ZADANIE LIZAK OI(18) --------------------------------------- 

					Problem : 

Dostajemy ciag literek S skladajacy sie z liter 'T' i 'W' (eg. TWTWTWTTWTW....) rozmiar ciągu n i ilość zapytań m

W ciągu 'T' ma wartośc 2 a 'W' ma warosc 1

Każde zapytanie podaje liczbe k i oczekuje takiego podciągu że wartość jego elementów będzie równa k

					Przyklad: 

n = 5 <-- rozmiar ciagu 
m = 2 <-- ilosc zapytan 
S = WTWTW <-- ciag

dla k = 2 przykladowy podciag to 'T' a do wypisania podajemy jego początek i koniec {2,2}
dla k = 5 przykladowy podciag to 'TWT' a do wypisania podajemy jego początek i koniec {2,4}

					Rozwiązanie : 

Okazuje się że przy limicie 1e6 zapytan gąsienica nie będzie optymalnym rozwiązaniem prawdopodobnie dalaby ok 30 pkt an 100.

Rozwiązanie polega preprocessingu czyli policzeniu wszytkich mozliwych k dla danego ciągu
Obliczone wyniki zapisalibysmy w tablicy par gdzie pierwszy element to indeks poczatku podciagu a drugi to indeks konca podciagu w ciagu podanym przez urzytkownika

dla przykladu z lini 11 taka tablica wygladalaby tak

0:  
1: 3 3
2: 2 2
3: 2 3
4: 1 3
5: 2 4
6: 1 4
7: 1 5
8: 
9:
....

Puste miejsca mowia nam ze dla takiego k nie ma rozwiazania
Warto nadmienic ze np dla k=2 mogą byc dwa rózne przedzialy (2 2) oraz (4 4) w tym zadaniu mozemy wypisac dowolny z nich

Aby utworzyc taka tablice rozwiazan do ktorej mozemy sie odwolac mozemy zauwazyc ze dla dowolnego ciagu jezeli obliczymy sume calego ciagu to 
będziemy w stanie obliczyc wszystkie inne sumy podciagi z ta samą parzystością.

W przykladzie z lini jedenastej mamy ciag WTWTW
jego suma jest rowna 7 czyli jest nieparzysta.


rozpatrzajac wszystkie mozliwe poczatki i konce dowolnych ciagow mozemy zauwazyc ze zawsze wartosc danego ciagu bedziemy mogli zmniejszyc o 2

T.........T
2---------2

W.........T
1---------2

T.........W
2---------1

W.........W
1---------1

Oznacza to ze jezeli znamy sume danego ciagu i jest ona nieparzysta jestesmy w stanie obliczyc wszystkie mozliwe kombinacje mniejsze od sumy
w przykladzie z lini 11 mamy ciag WTWTW ktory sumuje sie do 7

korzystajac z naszej obserwacji mozemy obliczyc wszystkie nieparzyste podciagi mniejsze od 7

WTWTW = 7 | odejmujemy 2 a skoro jedno 'W' jest rowne 1 musimy odjac oba
_TWT_ = 5 | po obu stronach mamy 'T' warte 2 wiec mozemy zabrac dowolne 
__WT_ = 3 | po jednej stronie mamy 'W' warte 1 a po drógiej 'T' warte 2 wiec zabieramy 'T'
__W__ = 1 

W ten sposób obliczylismy przedzialy dla wszystkich mozliwych nieparzystych k wiec zostaly nam juz tylko parzyste k aby otrzymac pelną tabelę

Aby zmienic parzystosc ciagu w naszym przykladzie z nieparzystych na parzyste musimy odjac jedno 'W' w ten sposob w przykladzie gdzie suma byla 7 jak odejmniemy jedno W mamy 6 i to jest nasza maksymalna liczba parzysta
a z niej tym samym co dla liczb nieparzystych algorytmem schodzimy w dół

Sposób jest ten poprawny gdyz jezeli zabierzemy 1 od dowolnej liczby parzystej stanie sie ona nieparzysta i na odwrót.


WTWTW |  nieparzyste zabieramy jedno W
_TWTW = 6
__WTW = 4
___T_ = 2

i w taki sposób uzyskalismy tablice wszystkich rozwiazan. Teraz pozostaje tylko pobrac od uzytkownika dowolne k sprawdzic czy posiada ono w naszej tablicy pare liczb opisujacych podciag jezeli tak wypisac go jezeli nie wypisac NIE na wyjscie.



--------------------------------------- ZADANIE KAJAKI--------------------------------------- 

					Problem : 

Dostajemy maksymalna wage danego kajaka m (kazdy moze pomiescic 2 osoby) nastepnie dostajemy liczbe osob n i po kolei n wag kazdego urzytkownika. Naszym zadaniem jest wypisac minimalna ilosc kajakow
jake musimy wyporzyczyc aby kazdy sie zmiescil.

					Przykład : 

m = 100 <-- maksymalna waga jaka uniesie kajak
n = 4 <-- ilosc ludzi

	<-- kolejne wagi uczestnikow -->
w1 = 20
w2 = 50
w3 = 10
w4 = 90

wynikiem dla takiej konfiguracji bedzie 2


					Rozwiązanie : 

Programowanie zachlanne

Rozwiązanie tego zadania jest bardzo proste. Nalezy zauwazyc ze jezeli posortujemy uczestnikow od najlzejszych do najciezszych to bedziemy w stanie zobaczyc czy najciezszy moze wejsc do kajaka z najlzejszym.
Jezeli nie najciezszy wezmie caly kajak dla siebie.

Na przykladzie z lini 99 wyglada to tak

*sortujemy wagi*

10 20 50 90

sprawdzamy czy 10 + 90 <= maksymalnej wagi jaka uniesie kajak (m)
jezeli tak obu uczestnikow wkladamy do jednego kajaka i idziemy dalej(dodajemy do oddzielnej zmiennej 1 zeby zaprezentowac ile kajakow dotychczasowo wzielismy)

__ 20 50 __ 

sprawdzamy znowu czy 20 + 50 <= m

ostatecznym wynikiem jest 2


Gdyby max_capacity kajaka byla 100 a wagi ludzi bylyby takie:
10 20 30 40 80 90 90 90 90

To program przeszedłby przez to tak
 	
	uczestnicy		ile_kajakow

10 20 30 40 80 90 90 90 90		0 | pakujemy 10 i 90 do jednego kajaka bo moze je uniesc
__ 20 30 40 80 90 90 90 __		1 | pakujemy jedynie 90 do kajaka gdzy z 20 kajak nie utrzymal 2 osob
__ 20 30 40 80 90 90 __ __		2 | ponownie pakujemy jedynie 90 do kajaka gdzy z 20 kajak nie utrzymal 2 osob
__ 20 30 40 80 90 __ __ __		3 | poraz kolejny pakujemy jedynie 90 do kajaka gdzy z 20 kajak nie utrzymal 2 osob
__ 20 30 40 80 __ __ __ __		4 | pakujemy 20 i 80 do jednego kajaka bo jeden kajak moze je uniesc
__ __ 30 40 __ __ __ __ __		5 | pakujemy 30 i 40 do jednego kajaka bo jeden kajak moze je uniesc
__ __ __ __ __ __ __ __ __		6 | konczymy program

minimalna liczba kajakow do wyporzyzcenia to 6


iIkajaki