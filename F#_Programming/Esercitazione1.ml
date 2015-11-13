(*
Convenzioni
Le seguenti convenzioni sono da ritenersi vincolanti affinché la vostra soluzione venga considerata corretta!
La durata di un ciclo lunare è pari a ESATTAMENTE 29 giorni.
Ipotizziate che il 1 gennaio del 2000 fosse l'inizio di un ciclo lunare (ci fosse quindi la Luna Nuova e il giorno corrispondente del ciclo lunare fosse 0).
La durata dei mesi è quella del calendario Gregoriano NON ci sono però gli anni bisestili.
Esercizio 1:
Data una data gg/mm/aaaa, definita come segue:
Il numero	corrisponde a      	con le limitazioni
gg	giorno del mese	da 1 a 31
mm	mese dell'anno
da 1 a 12
aaaa	cifre dell'anno
da 0 in avanti
si richiede di scrivere una funzione che:
presi in input i numeri che compongono la data, restituisca come output il numero del giorno rappresentato dalla data all'interno dell'anno (quindi un numero compreso tra 1 e 365).
Esempio:
data_to_day 10 1 1989 ==> 10
data_to_day 15 12 1988 ==> 349
Firma:
data_to_day: int -> int -> int -> int
Esercizio 2:
Date due date gg/mm/aaaa, definite come il primo esercizio si richiede di scrivere una funzione che:
presi in input i numeri che compongono le due date, restituisca come output la differenza in giorni tra le due date.
Esempio:
data_difference 3 1 2012 1 1 2012 ==> 2
data_difference 10 1 1989 15 12 1988 ==> 26
data_difference 30 9 2015 8 10 2015 ==> -8
data_difference 8 10 2015 8 10 2015 ==> 0
data_difference 6 1 2001 1 1 2000 ==> 370
Firma:
data_difference: int -> int -> int -> int -> int -> int -> int
Esercizio 3:
Data una data gg/mm/aaaa, definita come il primo esercizio e le fasi lunari definite come segue:
(Fase) (Intervallo Giorni) (Codice)
Luna Nuova 0 - 3	 LN
Luna Crescente 4 - 6 LR
Primo Quarto 7 - 10	PQ
Gibbosa Crescente 11 - 14 GR
Luna Piena 15 - 18 LP
Gibbosa Calante 19 - 21 GA
Ultimo Quarto 22 - 25 UQ
Luna Calante 26 - 28 LA
si richiede di scrivere una funzione che:
presi in input i numeri che compongono la data, restituisca come output il codice della fase lunare corrispondente.
NOTA BENE il codice della fase lunare è richiesto essere scritto in MAIUSCOLO (è key sensitive)
Esempio:
lunar_cycle 10 1 2000 ==> 'PQ'
Firma:
lunar_cycle: int -> int -> int -> string
*)

let days_for_every_month (month : int) : int = match month with
                                                |1 -> 31
                                                |2 -> 28
                                                |3 -> 31
                                                |4 -> 30
                                                |5 -> 31
                                                |6 -> 30
                                                |7 -> 31
                                                |8 -> 31
                                                |9 -> 30
                                                |10 -> 31
                                                |11 -> 30
                                                |12 -> 31
                                                |_ -> failwith("This isn't a month!");;

let rec sum_of_days (day : int) (month : int) : int =  if month = 1
                                                        then day
                                                       else day + sum_of_days (days_for_every_month(month-1)) ( month - 1);;


let data_to_day (day : int) (month : int) (year : int) : int = (sum_of_days day month);;



let data_difference (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int =  (year1 - year2) * 365 + ((sum_of_days day1 month1) - (sum_of_days day2 month2));;



let total_days (day : int) (month : int) (year : int) : int = data_difference day month year 1 1 2000;;

let types_lunar_cycle (day : int) : string = match day with
                                              |0|1|2|3 -> "LN"
                                              |4|5|6 -> "LR"
                                              |7|8|9|10 -> "PQ"
                                              |11|12|13|14 -> "GR"
                                              |15|16|17|18 -> "LP"
                                              |19|20|21 -> "GA"
                                              |22|23|24|25 -> "UQ"
                                              |26|27|28 -> "LA"
                                              |_ -> failwith("Errore!");;
let module_day (day : int) (month : int) (year : int) : int = (total_days day month year) mod 29;;

let lunar_cycle (day : int) (month : int) (year : int) : string = types_lunar_cycle (module_day day month year);;
