(*  
	#use "exercises_2_part.ml";;
*)

(*
let rec lstlen (lst : int list) : int = match lst with
										|[] -> 0
										|[x] -> 1
										|x::xs -> 1+ lstlen(xs);;
*)

(*
let rec aux_eliminate (lst : int list) (n : int) (i : int) : int list = match (lst, n, i) with
																			|([], _, _) -> []
																			|(x::xs, n, i) when i = n -> xs
																			|(x::xs, n, i) when i <> n -> x:: (aux_eliminate xs n (i+1));;


let rec eliminate (lst : int list) (n : int ) : int list = aux_eliminate lst n 0;;
*)

(*
let rec nextprime (n : int) (i : int) : bool = match (n,i) with
												|(n, i) when i >= n -> true
												|(n, i) when n mod i = 0 & i<n -> false
												|(n, i) when n mod i <> 0 & i<n -> nextprime n (i+1);;

let is_prime (n : int) : bool = nextprime n 2;;


let rec goldbach_aux (n : int) (i : int) : (int * int) = match (n,i) with
														|(n, i) when i < 2 -> goldbach_aux (n-1) (i+1)
														|(n, i) when is_prime(n) & is_prime(i) -> (n, i)
														|(n, i) -> goldbach_aux (n-1) (i+1);;


let goldbach (n : int) : (int * int) = if n mod 2 = 0 then goldbach_aux n 0
										else failwith("Inserire numero pari e riprovare");;
*)


(*
let rec nextprime (n : int) (i : int) : bool = match (n,i) with
												|(n, i) when i >= n -> true
												|(n, i) when n mod i = 0 & i<n -> false
												|(n, i) when n mod i <> 0 & i<n -> nextprime n (i+1);;

let is_prime (n : int) : bool = nextprime n 2;;


let rec genera_primi_aux (n : int) (m : int) (lst : 'a list) : 'a list = if m > n then []
																			else if is_prime(m) then m :: genera_primi_aux n (m+1) lst
																			else genera_primi_aux n (m+1) lst;;

let genera_primi (n : int) : 'a list = genera_primi_aux n 2 [];;
*)

(*
let piano_studi = [("programmazione" , 12); ("architettura", 12); ("matematica", 6); ("algebra", 6)];;


let rec trova_crediti (lst : 'a list) (nome : string) : int = match (lst, nome) with
																|([], _) -> 0
																|((x,y)::xs, nome) when x = nome -> y
																|((x,y)::xs, nome) when x <> nome -> trova_crediti (xs) nome;;

let main = trova_crediti piano_studi "algebra";;
*)

(*
let libretto1 = [("programmazione", 22); ("architettura", 26); ("matematica", 24)];;

let rec libretto_lenght (libretto : 'a list) : int = match libretto with
														| [] -> 0
														| [x] -> 1
														| x::xs -> 1+ libretto_lenght(xs);;

let rec somma_voti (libretto : 'a list) : int = match libretto with
												|([]) -> 0
												|([x,y]) -> y
												|((x,y)::xs) -> y+somma_voti(xs);;

let media_voti (libretto : 'a list) : float = int_of_float(somma_voti libretto) /. int_of_float(libretto_lenght libretto);;

let main = media_voti libretto1;;

incompleta - guarda appunti per versione completa
*)

(*
let rec fib_rec (index : int) (n : int) (fib1 : int) (fib2 : int) : int = if index >= n then (fib1 + fib2)
																			else fib_rec (index+1) n (fib1+fib2) fib1;;

let fibs_n_digits (n : int) : int = match n with
									| n when n = 0 -> 0
									| n when n = 1 || n = 2 -> 1
									| n when n > 2 -> fib_rec 3 n 1 1;;
*)

(*
let rec tab_aux (numero : int) (quanto : int) (index : int) (lst : int list) : int list = if index > quanto then []
																							else (numero * index) :: tab_aux numero quanto (index+1) lst;;

let tab (numero : int) (quanto : int) : int list = tab_aux numero quanto 1 [];;
*)

let rec reverse_aux (initial : 'a list) (final : 'a list) : 'a list = match initial with
																		| [] -> final;
																		| [x] -> x::final
																		| x::xs -> reverse_aux (xs) (x::final);;

let rec reverse (initial : 'a list) : 'a list = reverse_aux initial [];;