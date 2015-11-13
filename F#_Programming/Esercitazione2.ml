(* copy this in the terminal #use "Esercitazione2.ml";; *)

(* Funzione che definisce dato l'anno se Febbraio ha 28 o 29 giorni*)
let is_bisestile (year : int) : int = if ((year mod 4 = 0) || (year mod 400 = 0) || (year mod 100 = 0))
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

let rec sum_of_days (day : int) (month : int) (year : int) : int =  if month = 1
                                                        then day
                                                        else day + sum_of_days (days_for_every_month (month-1) year) ( month - 1) year;;

let is_bisestile_year (year : int) : int = if ((year mod 4 = 0) || (year mod 400 = 0) || (year mod 100 = 0))
                                           then 366
                                           else 365;;

let check_year (year1 : int) (year2 : int) : int =let rec check_year2 (y1 : int) (y2 : int) (n : int) = match (y1,y2,n) with
                                                                                                          |(a,b,n) when a=b -> n
                                                                                                          |(a,b,n) when a<b -> check_year2 (a+1) b (n+(is_bisestile_year a))
                                                                                                          |(a,b,n) when a>b -> check_year2 a (b+1) (n+(is_bisestile_year b))
                                                                                                          |_ -> failwith "errore"
                                                   in check_year2 year1 year2 0;;



let data_difference (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int = if year1 < year2
                                                                                                                  then check_year year1 year2 + sum_of_days day2 month2 year2 - sum_of_days day1 month1 year1
                                                                                                                else if year1 > year2
                                                                                                                      then check_year year1 year2 + sum_of_days day1 month1 year1 - sum_of_days day2 month2 year2
                                                                                                                     else sum_of_days day2 month2 year2 - sum_of_days day1 month1 year1;;

let counter (n : int) : int = let rec counter_aus (n : int) (i : int) : int = match (n,i) with
                                                                                |(n,i) when n = 0 -> i
                                                                                |(n,i) when n > 0 -> counter_aus (n/10) (i+1)
                                                                                |_ -> failwith "Errore algoritmo! Controlla bene!"
                              in counter_aus n 0;;

let reverse_number (n : int) : int = let rec reverse_number_aus (n : int) (j : int) : int = match (n,j) with
                                                                                              |(n,j) when j=0 -> n
                                                                                              |(n,j) -> (n + (reverse_number_aus n mod 10 * (int(10 ** j))) (j-1)
                                                                                              |(n,j) when j< counter (n-1) -> (n + (reverse_number_aus(((n / 10) mod 10)*((10**j))))) (j-1)
                                                                                              |_ -> failwith "Errore o caso non studiato"
                                    in reverse_number_aus n counter (n-1);;



let blue_moon (year : int) : int = 
