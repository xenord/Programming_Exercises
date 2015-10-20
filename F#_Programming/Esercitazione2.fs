module Esercitazione2

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
                                            then 365
                                          else 366;;


let data_difference (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int =  if (year1 = year2)
                                                                                                                  then ((sum_of_days day1 month1 year1) - (sum_of_days day2 month2 year2))
                                                                                                                 else 0;;


let data_to_day (day : int) (month : int) (year : int) : int = (sum_of_days day month);;

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

let rec lunar_cycle (day : int) (month : int) (year : int) : string = types_lunar_cycle (module_day day month year);;
