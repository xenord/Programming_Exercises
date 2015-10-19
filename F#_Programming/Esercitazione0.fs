(* Esercizio 1:

Dato un triangolo rettangolo, si richiede di scrivere una funzione che:
presi in input la misura di un cateto e della sua proiezione sull'ipotenusa, restituisca come output la dimensione dell'ipotenusa.

Esempio:

euclides_hypotenuse 3. 2. ==> 4.5

Firma:

euclides_hypotenuse: float -> float -> float
--------------------------------------------

Esercizio 2:

Dato un piano cartesiano, si richiede di scrivere una funzione che:
presi in input le coordinate bidimensionali di due punti, restituisca come output l'area del quadrilateo formato dal segmento congiungente i due punti e la proiezione dello stesso sull'asse delle ascisse.



Esempio:

segment_integral 3. 3. 2. 2. ==> 2.5


Firma:

segment_integral: float -> float -> float -> float -> float

-----------------------------------------------------------

Esercizio 3:

Dato un triangolo rettangolo, si richiede di scrivere una funzione che:
presi in input la misura di un cateto e della sua proiezione sull'ipotenusa, restituisca come output l'area del triangolo.



Esempio:

triangle_area 15. 9. ==> 150.0



Firma:

triangle_area: float -> float -> float


*)

module Esercitazione0



let NomeCognome : string = "Francesco Benetello"

let euclides_ipotenusa (cb : float) (ch : float) : float = (cb * cb) / ch;;

let segment_integral (x1 : float) (y1 : float) (x2 : float) (y2 : float)  : float = ((abs(x2 - x1)) * (y2 + y1) / 2.);;

let triangle_area (cb : float) (ch : float) : float = 
    let ca = euclides_ipotenusa cb ch 
    let bh = sqrt((cb**2.) - (ch**2.))
    in (ca * bh) / 2.;;
