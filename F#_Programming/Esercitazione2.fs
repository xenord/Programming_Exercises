module Esercitazione2

(*
Alcune note utili:
Il terzo esercizio è collegato alla scorsa esercitazione, si consiglia di leggere la scorsa esercitazione (se già non l'avete fatto)
Convenzioni
Le seguenti convenzioni sono da ritenersi vincolanti affinché la vostra soluzione venga considerata corretta!
La durata di un ciclo lunare è pari ad ESATTAMENTE 29 giorni.
Ipotizziate che il 1 gennaio del 2000 fosse l'inizio di un ciclo lunare (ci fosse quindi la Luna Nuova e il giorno corrispondente del ciclo lunare fosse 0).
Le fasi lunari sono definite come segue:
(Fase) (Intervallo Giorni) (Codice)
Luna Nuova 0 - 3	 LN
Luna Crescente 4 - 6 LR
Primo Quarto 7 - 10	PQ
Gibbosa Crescente 11 - 14 GR
Luna Piena 15 - 18 LP
Gibbosa Calante 19 - 21 GA
Ultimo Quarto 22 - 25 UQ
Luna Calante 26 - 28 LA
Una luna piena è considerata parte di un mese se il suo 15° giorno di ciclo fa parte del mese in questione
La durata dei mesi è quella del calendario Gregoriano, COMPRESI GLI ANNI BISESTILI .
Un anno si definisce bisestile se il suo numero è divisibile per 4, con l'eccezione degli anni secolari (quelli divisibili per 100) che non sono divisibili per 400.
L'anno 2000 è bisestile perché è un anno secolare ma è divisibile per 400.
L'anno 1900 non è bisestile perché è secolare ma non è divisibile per 400.
L'anno 1988 è bisestile perché è divisibile per 4.
L'anno 1989 non è bisestile perchè non è divisibile per 4.
Una data gg/mm/aaaa è definita come segue:
Il numero	corrisponde a      	con le limitazioni
gg	giorno del mese	da 1 a 31
mm	mese dell'anno
da 1 a 12
aaaa	cifre dell'anno
da 0 in avanti

Esercizio 1:
Date due date gg/mm/aaaa si richiede di scrivere una funzione che:
presi in input i numeri che compongono le due date, restituisca come output la differenza in giorni tra le due date, considerando anche gli anni bisestili.
data_difference 10 1 1989 15 12 1988 ==> 26
data_difference 30 9 2015 8 10 2015 ==> -8
data_difference 8 10 2015 8 10 2015 ==> 0
data_difference 6 1 2001 1 1 2000 ==> 371
data_difference 6 1 2005 1 1 2000 ==> 1832
data_difference 28 2 2012 1 3 2012 ==> -2
Firma:
data_difference: int -> int -> int -> int -> int -> int -> int

Esercizio 2:
Dato un numero, si richiede di scrivere una funzione che:
preso in input un numero, restituisca come output il numero con le cifre invertite.
NON USATE la conversione in Stringhe
Esempio:
reverse_number 12345 ==> 54321
reverse_number 7  ==> 7
reverse_number 100 ==> 1
reverse_number 101 ==> 101
reverse_number 1203 ==> 3021
Firma:
reverse_number: int -> int
Esercizio 3:
Dato il termine Luna Blu, che indica la seconda luna piena di un mese, si richiede di scrivere una funzione che:
preso in input un anno, restituisca come output il numero del primo mese dell'anno che contenga una luna blu, in caso nessun mese ne abbia si deve lanciare un'eccezione failwith "NON TROVATO", considerando anche gli anni bisestili.
Esempio:
blue_moon 1988 ==> NON TROVATO
blue_moon 2015 ==> NON TROVATO
blue_moon 2020 ==> NON TROVATO
blue_moon 2016 ==> 1
blue_moon 1989 ==> 3
blue_moon 2004 ==> 4
blue_moon 2009 ==> 5
blue_moon 2019 ==> 6
blue_moon 1992 ==> 7
blue_moon 2002 ==> 8
blue_moon 2017 ==> 9
blue_moon 1985 ==> 10
blue_moon 2000 ==> 11
blue_moon 2005 ==> 12
Firma:
blue_moon: int -> int
*)

let NomeCognome : string = "Francesco Benetello"


let is_bisestile (year: int) : int = if ((year % 4 = 0) || (year % 400 = 0) || (year % 100 = 0))
                                      then 29
                                     else 28;;

let days_for_every_month (month : int) (year : int) : int = match month with
                                                              |1 -> 31
                                                              |2 -> is_bisestile(year)
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

let rec sum_of_days (day : int) (month : int) (year : int): int =  if month = 1
                                                                    then day
                                                                   else day + sum_of_days (days_for_every_month(month-1) (year)) ( month - 1) year;;

let is_bisestile_year (year: int) : int = if ((year % 4 = 0) || (year % 400 = 0) || (year % 100 = 0))
                                            then 366
                                          else 365;;



let rec sum_bisestile_year_and_not (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int =  if (year1 = year2)
                                                                                                                      then ((sum_of_days day1 month1 year1) - (sum_of_days day2 month2 year2))
                                                                                                                     else ((sum_of_days day1 month1 year1) - (sum_of_days day2 month2 year2)) + data_difference((year1) year2);;

let rec data_difference (year1 : int) (year2 : int) : int = if (year1 = year2)
                                                                        then is_bisestile_year(year1)
                                                                       else data_difference(year1 (is_bisestile_year(year2))) year1 year2 + 1;;


(*let data_to_day (day : int) (month : int) (year : int) : int = (sum_of_days day month);;

let prova (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int =  (year1 - year2) * 365 + ((sum_of_days day1 month1) - (sum_of_days day2 month2));;




let total_days (day : int) (month : int) (year : int) : int = data_difference (day month year) (1 1 2000);;

let types_lunar_cycle (day : int) : string = match day with
                                              |0|1|2|2 -> "LN"
                                              |4|5|6 -> "LR"
                                              |7|8|9|10 -> "PQ"
                                              |11|12|13|14 -> "GR"
                                              |15|16|17|18 -> "LP"
                                              |19|20|21 -> "GA"
                                              |22|23|24|25 -> "UQ"
                                              |26|27|28 -> "LA";;
let module_day (day : int) (month : int) (year : int) : int = mod (total_days day month year);;

let rec lunar_cycle (day : int) (month : int) (year : int) : string = types_lunar_cycle (module_day day month year);; *)
