let elem_counter (xs : int list) : int = let rec elem_counter_aus (s : int) (xs : int list) : int = match xs with
                                                                                                    |[] -> s
                                                                                                    |_ :: xs -> elem_counter_aus (s+1) xs
                                              in elem_counter_aus 0 xs;;

let rec sum (xs : int list) : int =  match xs with
                                              |[] -> failwith "Empty List"
                                              |[s] -> s
                                              |s :: xs -> s + (sum xs);;

let rec mult (xs : int list) : int = match xs with
                                      |[] -> failwith "Empty List"
                                      |[s] -> s
                                      |s :: xs -> s * (mult xs);;

let arithmetic_mean (xs : int list) : int = sum xs / elem_counter xs;;


let harmonic_mean (xs : int list) : int = 



let rec means (l : int list) : (float * float * float) = 0., 0., 0.

let rec min_max (l : int list) : (int * int) = 0, 0

let rec mode (l : int list) : int = 0
