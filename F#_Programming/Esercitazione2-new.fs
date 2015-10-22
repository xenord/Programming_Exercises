

let rec pow (n : int) (m : int) : int = if m = 0
                                          then 1
                                        else n * pow n (m-1);;


let rec number_count (n : int) : int = if n / 10 = 0
                                          then 1
                                       else 1 + number_count (n / 10);;



let rec reverse_number (n : int)
