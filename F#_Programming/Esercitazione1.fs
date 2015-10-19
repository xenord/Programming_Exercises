module Esercitazione1

let NomeCognome : string = "Francesco Benetello"

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

let prova (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int =  (year1 - year2) * 365 + ((sum_of_days day1 month1) - (sum_of_days day2 month2));;

let data_difference (day1 : int) (month1 : int) (year1 : int) (day2 : int) (month2 : int) (year2 : int) : int = if (year1 < year2) 
                                                                                                                 then (year2 - year1) * 365 + ((sum_of_days day1 month1) - (sum_of_days day2 month2))
                                                                                                                else if (year2 < year1)
                                                                                                                      then (year1 - year2) * 365 + ((sum_of_days day1 month1) - (sum_of_days day2 month2))
                                                                                                                     else ((sum_of_days day1 month1) - (sum_of_days day2 month2));;

        


let rec lunar_cycle (day : int) (month : int) (year : int) : string = ""


