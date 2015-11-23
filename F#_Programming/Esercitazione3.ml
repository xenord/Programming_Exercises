(* Esercizio 1:

 *  Data una lista non vuota di numeri interi positivi diversi da 0,
 *  si richiede di scrivere una funzione che:
 *  presa in input la lista, restituisca come output una tupla contenete in ordine la media aritmetica,
 *  la media geometrica e la media armonica.

Firma:  means: int list -> (float * float * float)


Esercizio 2:

 *Data una lista non vuota di numeri interi, si richiede di scrivere una funzione che:
 *presa in input la lista, restituisca come output la coppia contenente in ordine il numero minimo e
 *il numero massimo della lista.

Firma:  min_max: int list -> (int * int)


Esercizio 3:

 *Data una lista non vuota di numeri interi si richiede di scrivere una funzione che:
 *presa in input la lista, restituisca come output la moda della lista.
 *In caso più numeri abbiano la stessa occorrenza,
 *si ritroni il numero che compare per primo nella lista tra quelli con l'occorrenza massima.

Firma:  mode: int list -> int
*)
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

(*let geometric_mean (xs : int list) : int = ((mult xs) ** (1 / (elem_counter xs)));; *)

let rec sum_fract (xs : int list) : int =  match xs with
                                              |[] -> failwith "Empty List"
                                              |[s] -> 1/s
                                              |s :: xs -> 1/s + (sum_fract xs);;

(*let harmonic_mean (xs : int list) : int = elem_counter xs / sum_fract xs;; *)



let rec means (l : int list) : (float * float * float) = 0., 0., 0.

let rec min (l : int list) : int = match l with
                                    | [] -> failwith "The list is empty"
                                    | [hd] -> hd
                                    | hd :: hd2 :: l -> if hd<hd2 then min (hd :: l) else min (hd2 :: l);;

let rec max (l : int list) : int = match l with
                                    |[] -> failwith "The list is empty"
                                    |[hd] -> hd
                                    | hd :: hd2 :: l -> if hd > hd2 then max(hd :: l) else max(hd2 :: l);;



(*let min_max (l : int list) : (int * int) = min(l) * max(l);; (* Da provare! *) *)


let occurences_counter (l : int list) : int = let rec aus_fun (l : int list) (n : int) : int = match l with
                                                                                                |[] -> failwith "The list is empty"
                                                                                                |[hd] -> 1
                                                                                                |hd :: hd2 :: l -> if hd = hd2 then aus_fun l            else aus_fun hd2 :: list
                                              in aus_fun l 0;;
let rec mode (l : int list) : int = 0
